#include "npc.h"

bool NPC::visit(std::shared_ptr<robber> robber) 
{
    return this->fight(robber);
}
bool NPC::visit(std::shared_ptr<wolf> wolf) {
    return this->fight(wolf);
}
bool NPC::visit(std::shared_ptr<bear> bear) {
    return this->fight(bear);
}

void NPC::subscribe(std::shared_ptr<fight_observer> observer) {
    observers.push_back(observer);
}

void NPC::fight_notify(const std::shared_ptr<NPC> defender, bool win) {
    for (auto &o : observers)
        o->on_fight(std::shared_ptr<NPC>(this, [](NPC *) {}), defender, win);
}

bool NPC::is_close(const std::shared_ptr<NPC> &other, size_t distance)
{
    auto [other_x, other_y] = other->position();
    std::lock_guard<std::mutex> lck(mtx);

    if (this -> _type == _robber){
        distance = 10;
    } else if (this -> _type == _wolf){
        distance = 5;
    } else if (this -> _type == _bear){
        distance = 10;
    }

    if ((std::pow(_x - other_x, 2) + std::pow(_y - other_y, 2)) <= std::pow(distance, 2)) // по теореме Пифагора
        return true;
    else
        return false;
}

npc_type NPC::get_type()
{
    std::lock_guard<std::mutex> lck(mtx);
    return _type;
}

std::pair<int, int> NPC::position()
{
    std::lock_guard<std::mutex> lck(mtx);
    return {_x, _y};
}

void NPC::save(std::ostream &os)
{
    os << _x << std::endl;
    os << _y << std::endl;
}

std::ostream &operator<<(std::ostream &os, NPC &npc) {
    os << "{ x:" << npc._x << ", y:" << npc._y << "} ";
    return os;
}

void NPC::move(int shift_x, int shift_y, int max_x, int max_y) {
    std::lock_guard<std::mutex> lck(mtx);
    int move_distance = 0;

    if (this -> _type == _robber){
        move_distance = 10;
    } else if (this -> _type == _wolf){
        move_distance = 40;
    } else if (this -> _type == _bear){
        move_distance = 5;
    }

    if (shift_y & 1 == 0)
    {
        shift_x = move_distance * pow(-1, shift_x);
        shift_y = move_distance * pow(-1, shift_y);
    }
    else
    {
        shift_x = move_distance * pow(-1, shift_x);
        shift_y = move_distance * pow(-1, shift_y);
    }

    if ((_x + shift_x >= 0) && (_x + shift_x <= max_x))
        _x += shift_x;
    if ((_y + shift_y >= 0) && (_y + shift_y <= max_y))
        _y += shift_y;
}

bool NPC::is_alive()
{
    std::lock_guard<std::mutex> lck(mtx);
    return _alive;
}

void NPC::must_die()
{
    std::lock_guard<std::mutex> lck(mtx);
    _alive = false;
}