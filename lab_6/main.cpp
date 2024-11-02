#include "npc.h"
#include "robber.h"
#include "wolf.h"
#include "bear.h"


class text_observer : public fight_observer
{
private:
    text_observer(){};

public:
    void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override
    {
        if (win)
        {
            std::cout << std::endl
                      << "Murder -------- " << std::endl;
            attacker->print();
            defender->print();
        }
    }
    static std::shared_ptr<fight_observer> get()
    {
        static text_observer instance;
        return std::shared_ptr<fight_observer>(&instance, [](fight_observer*){});
    }
};

class file_observer : fight_observer
{
private:
    std::ofstream file;

    file_observer()
    {
        file.open("log.txt");
    }

public:

    void on_fight(std::shared_ptr<NPC> const attacker, std::shared_ptr<NPC> const defender, bool win) override
    {
        if(win)
        {
            file << std::endl
                        <<  "Murder -------- " << std::endl;
            attacker->print(file);
            defender->print(file);
        }
    }
    static std::shared_ptr<fight_observer> get()
    {
        static std::shared_ptr<fight_observer> instance;
        return instance;
    }

};

std::shared_ptr<NPC> factory(std::istream &is)
{
    std::shared_ptr<NPC> result;
    int type{0};
    if (is >> type)
    {
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
        result->subscribe(text_observer::get());
    result->subscribe(file_observer::get());

    return result;
}

std::shared_ptr<NPC> factory(npc_type type, int x, int y)
{
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
        result->subscribe(text_observer::get());
    result->subscribe(file_observer::get());

    return result;
}

void save(const set_t &array, const std::string &filename)
{
    std::ofstream fs(filename);
    fs << array.size() << std::endl;
    for (auto &n : array)
        n->save(fs);
    fs.flush();
    fs.close();
}

set_t load(const std::string &filename)
{
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

std::ostream &operator<<(std::ostream &os, const set_t &array)
{
    for (auto &n : array)
        n->print();
    return os;
}

set_t fight(const set_t &array, size_t distance)
{
    set_t dead_list;

    for (const auto &attacker : array)
        for (const auto &defender : array)
            if ((attacker != defender) && (attacker->is_close(defender, distance)))
            {
                bool success{false};

                success = defender->accept(attacker);

                if (success)
                    dead_list.insert(defender);
            }

    return dead_list;
}

int main()
{
    set_t array;


    std::cout << "Generating ... " << std::endl;
    for (size_t i = 0; i < 40; ++i)
        array.insert(factory(npc_type(std::rand() % 3 + 1),
                             std::rand() % 500,
                             std::rand() % 500)); // х и у до 500


    std::cout << "Saving ...  " << std::endl;


    save(array, "npc.txt");

    std::cout << "Loading ... " << std::endl;

    array = load("npc.txt");

    std::cout << "Fighting ... " << std::endl << array;

    for (size_t distance = 20; (distance <= 300) && !array.empty(); distance += 50)
    {
        auto dead_list = fight(array, distance);
        for (auto &d : dead_list)
            array.erase(d);
        std::cout << "Fight stats ----------" << std::endl
                  << "distance: " << distance << std::endl
                  << "killed  : " << dead_list.size() << std::endl
                  << std::endl << std::endl;

    }

    std::cout << "Survivors  : " << array;

    return 0;
}
