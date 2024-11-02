#ifndef LAB_7_NPC_H
#define LAB_7_NPC_H
#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <random>
#include <fstream>
#include <set>
#include <math.h>
#include <shared_mutex>

class NPC;
class robber;
class wolf;
class bear;
using set_t = std::set<std::shared_ptr<NPC>>;

enum npc_type
{
    Unknown,
    _robber,
    _wolf,
    _bear
};

class fight_observer
{
public:
    virtual void on_fight(std::shared_ptr<NPC> attacker, std::shared_ptr<NPC>  defender, bool win) = 0;
};

class NPC : public std::enable_shared_from_this<NPC>
{
private:

    std::mutex mtx;

    npc_type _type;
    int _x{0};
    int _y{0};
    bool _alive{true};

    std::vector<std::shared_ptr<fight_observer>> observers;

public:

    NPC(npc_type type, int x, int y) : _type(type), _x(x), _y(y) {}

    explicit NPC(npc_type type, std::istream& is) : _type(type)
    {
        is >> _x;
        is >> _y;
    }

    void subscribe(std::shared_ptr<fight_observer> observer);
    void fight_notify(std::shared_ptr<NPC> defender, bool win);
    virtual bool is_close(std::shared_ptr<NPC> const& other, size_t dist);

    virtual bool accept(std::shared_ptr<NPC> visitor) = 0;
    virtual bool fight(std::shared_ptr<robber> other) = 0;
    virtual bool fight(std::shared_ptr<wolf> other) = 0;
    virtual bool fight(std::shared_ptr<bear> other) = 0;

    bool visit(std::shared_ptr<robber> other);
    bool visit(std::shared_ptr<wolf> other);
    bool visit(std::shared_ptr<bear> other);

    std::pair<int, int> position();
    npc_type get_type();

    virtual void print() = 0;
    virtual void print(std::ostream &os) = 0;

    virtual void save(std::ostream &os);

    friend std::ostream &operator<<(std::ostream &os, NPC &npc);

    void move(int shift_x, int shift_y, int max_x, int max_y);

    bool is_alive();
    void must_die();


};


#endif
