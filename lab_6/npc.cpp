#include "npc.h"

void NPC::subscribe(std::shared_ptr<fight_observer> observer)
{
    observers.push_back(observer);
}

void NPC::fight_notify(std::shared_ptr<NPC> defender, bool win)
{
    for(auto obs : observers)
        if(obs) obs->on_fight(shared_from_this(), defender, win);
}

bool NPC::is_close(std::shared_ptr<NPC> other, size_t dist) const
{
   return std::pow(_x - other->_x, 2) + std::pow(_y - other->_y, 2) <= std::pow(dist, 2); // по теореме Пифагора
}

bool NPC::visit(std::shared_ptr<robber> robber)
{
    return this->fight(robber);
}
bool NPC::visit(std::shared_ptr<wolf> wolf)
{
    return this->fight(wolf);
}
bool NPC::visit(std::shared_ptr<bear> bear)
{
    return this->fight(bear);
}

void NPC::save(std::ostream &os)
{
    os << _x << std::endl;
    os << _y << std::endl;
}

std::ostream &operator<<(std::ostream &os, NPC &npc)
{
    os << "{ x:" << npc._x << ", y:" << npc._y << "} ";
    return os;
}