#include "npc.h"
#include "robber.h"
#include "wolf.h"
#include "bear.h"

#include <sstream>
#include <atomic>
#include <thread>
#include <optional>
#include <array>
#include <chrono>
#include <queue>
#include <mutex>


using namespace std::chrono_literals;
std::mutex print_mutex;

// Text Observer
class TextObserver : public fight_observer {
private:
    TextObserver(){};

public:
    static std::shared_ptr<fight_observer> get() {
        static TextObserver instance;
        return std::shared_ptr<fight_observer>(&instance, [](fight_observer *) {});
    }

    void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override {
        if (win) {
            std::lock_guard<std::mutex> lck(print_mutex);
            std::cout << std::endl
                      << "Murder --------" << std::endl;
            attacker->print();
            defender->print();
        }
    }
};


// Фабрики -----------------------------------
std::shared_ptr<NPC> factory(std::istream &is) {
    std::shared_ptr<NPC> result;
    int type{0};
    if (is >> type) {
        switch (type)
        {
            case _robber:
                result = std::make_shared<robber>(is);
                break;
            case _wolf:
                result = std::make_shared<wolf>(is);
                break;
            case _bear:
                result = std::make_shared<bear>(is);
                break;
        }
    }
    else
        std::cerr << "unexpected NPC type:" << type << std::endl;

    if (result)
        result->subscribe(TextObserver::get());
    return result;
}

std::shared_ptr<NPC> factory(npc_type type, int x, int y) {
    std::shared_ptr<NPC> result;
    switch (type)
    {
        case _robber:
            result = std::make_shared<robber>(x, y);
            break;
        case _wolf:
            result = std::make_shared<wolf>(x, y);
            break;
        case _bear:
            result = std::make_shared<bear>(x, y);
            break;
        default:
            break;
    }
    if (result)
        result->subscribe(TextObserver::get());
    return result;
}

// save array to file
void save(const set_t &array, const std::string &filename) {
    std::ofstream fs(filename);
    fs << array.size() << std::endl;
    for (auto &n : array)
        n->save(fs);
    fs.flush(); //все данные, находящиеся в буфере, будут записаны в файл
    fs.close();
}

set_t load(const std::string &filename) {
    set_t result;
    std::ifstream is(filename);
    if (is.good() && is.is_open())
    {
        int count;
        is >> count;
        for (int i = 0; i < count; ++i)
            result.insert(factory(is));
        is.close();
    }
    else
        std::cerr << "Error: " << std::strerror(errno) << std::endl;
    return result;
}

// print to screen
std::ostream &operator<<(std::ostream &os, const set_t &array) {
    for (auto &n : array)
        n->print();
    return os;
}

set_t fight(const set_t &array, size_t distance) {
    set_t dead_list;

    for (const auto &attacker : array)
        for (const auto &defender : array)
            if ((attacker != defender) && (attacker->is_close(defender, distance)))
            {
                bool success{false};
                // if (defender->is_robber())
                //     success = attacker->fight(std::dynamic_pointer_cast<Robber>(defender));
                // if (defender->is_wolf())
                //     success = attacker->fight(std::dynamic_pointer_cast<Wolf>(defender));
                // if (defender->is_bear())
                //     success = attacker->fight(std::dynamic_pointer_cast<Bear>(defender));

                success = defender->accept(attacker);

                if (success)
                    dead_list.insert(defender);
            }

    return dead_list;
}

struct print : std::stringstream {
    ~print()
    {
        static std::mutex mtx;
        std::lock_guard<std::mutex> lck(print_mutex);
        std::cout << this->str();
        std::cout.flush();
    }
};


bool k = true, m = true;
struct FightEvent {
    std::shared_ptr<NPC> attacker;
    std::shared_ptr<NPC> defender;
};

class FightManager {
private:
    std::queue<FightEvent> events;
    std::shared_mutex mtx;

    FightManager() {}

public:
    static FightManager &get() {
        static FightManager instance;
        return instance;
    }

    void add_event(FightEvent &&event) {
        std::lock_guard<std::shared_mutex> lock(mtx);
        events.push(event);
    }

    void operator()() {
        while (k) {
            {
                std::optional<FightEvent> event;

                {
                    std::lock_guard<std::shared_mutex> lock(mtx);
                    if (!events.empty()) {
                        event = events.back();
                        events.pop();
                    }
                }

                if (event) {
                    try {
                        if (event->attacker->is_alive())     // no zombie fighting!
                            if (event->defender->is_alive()) // already dead!
                                if (event->defender->accept(event->attacker))
                                    event->defender->must_die();
                    }
                    catch (...) {
                        std::lock_guard<std::shared_mutex> lock(mtx);
                        events.push(*event);
                    }
                }
                else
                    std::this_thread::sleep_for(100ms);
            }
        }
    }
};

int main() {
    set_t array;

    const int MAX_X{500};
    const int MAX_Y{500};
    const int DISTANCE{40};


    std::cout << "Generating ...  " << std::endl;
    for (size_t i = 0; i < 10; ++i)
        array.insert(factory(npc_type(std::rand() % 3 + 1),
                             std::rand() % 500,
                             std::rand() % 500));


    std::cout << "Starting list  :" << std::endl
              << array;

    std::thread fight_thread(std::ref(FightManager::get()));

    int count = 0;
    std::thread move_thread([&array, MAX_X, MAX_Y, DISTANCE, &count]() {
        while (m) {
            // move phase
            for (std::shared_ptr<NPC> npc : array) {
                if(npc->is_alive()){
                    int shift_x = std::rand() % 20 - 10;
                    int shift_y = std::rand() % 20 - 10;
                    npc->move(shift_x, shift_y, MAX_X, MAX_Y);
                }
            }
            // lets fight
            for (std::shared_ptr<NPC> npc : array)
                for (std::shared_ptr<NPC> other : array)
                    if (other != npc)
                        if (npc->is_alive())
                            if (other->is_alive())
                                if (npc->is_close(other, DISTANCE))
                                    FightManager::get().add_event({npc, other});

            std::this_thread::sleep_for(1s);
            ++count;
        } });

    int now = 0, end = 50;
    while (now < end) {
        const int grid{20}, step_x{MAX_X / grid}, step_y{MAX_Y / grid}; {
            std::array<char, grid * grid> fields{0};
            for (std::shared_ptr<NPC> npc : array) {
                auto [x, y] = npc->position();
                int i = x / step_x;
                int j = y / step_y;

                if (npc->is_alive())
                {
                    switch (npc->get_type())
                    {
                        case _wolf:
                            fields[i + grid * j] = 'W';
                            break;
                        case _robber:
                            fields[i + grid * j] = 'R';
                            break;
                        case _bear:
                            fields[i + grid * j] = 'B';
                            break;

                        default:
                            break;
                    }
                }
                else
                    fields[i + grid * j] = '.';
            }

            if(count > 40) {
                break;
            }
            std::lock_guard<std::mutex> lck(print_mutex);
            for (int j = 0; j < grid; ++j) {
                for (int i = 0; i < grid; ++i) {
                    char c = fields[i + j * grid];
                    if (c != 0)
                        std::cout << "[" << c << "]";
                    else
                        std::cout << "[ ]";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
        std::this_thread::sleep_for(1s);
        now += 1;
    }

    k = false; m = false;
    move_thread.join();
    fight_thread.join();

    return 0;
}