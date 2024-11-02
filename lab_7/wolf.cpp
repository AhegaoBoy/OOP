#include "wolf.h"
#include "robber.h"
#include "bear.h"

void wolf::print()
{
    std::cout << *this;
}

void wolf::print(std::ostream &outfs)
{
    outfs << *this;
}

bool wolf::accept(std::shared_ptr<NPC> other) 
{
    return other->fight(std::shared_ptr<wolf>(this,[](wolf*){}));
}

void wolf::save(std::ostream &os)
{
    os << _wolf << std::endl;
    NPC::save(os);
}

bool wolf::fight(std::shared_ptr<robber> other)
{
    fight_notify(other, true);
    return true;
}

bool wolf::fight(std::shared_ptr<wolf> other)
{
    fight_notify(other, false);
    return false;
}

bool wolf::fight(std::shared_ptr<bear> other)
{
    fight_notify(other, false);
    return false;
}

std::ostream &operator<<(std::ostream &os, wolf &wolf)
{
    os << "wolf : " << *static_cast<NPC *>(&wolf) << std::endl;
    return os;
}