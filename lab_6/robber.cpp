#include "robber.h"
#include "wolf.h"
#include "bear.h"

void robber::print()
{
    std::cout << *this;
}

void robber::save(std::ostream &os)
{
    os << _robber << std::endl;
    NPC::save(os);
}

void robber::print(std::ostream &outfs)
{
    outfs << *this;
}

bool robber::accept(std::shared_ptr<NPC> visitor)
{
    std::shared_ptr<robber> This = std::make_shared<robber>(*this);
    return visitor->visit(This);
}

bool robber::fight(std::shared_ptr<bear> other)
{
    fight_notify(other, true);
    return true;
}

bool robber::fight(std::shared_ptr<wolf> other)
{
    fight_notify(other, false);
    return false;
}

bool robber::fight(std::shared_ptr<robber> other)
{
    fight_notify(other, false);
    return false;
}

std::ostream &operator<<(std::ostream &os, robber &robber)
{
    os << "robber:  " << *static_cast<NPC *>(&robber) << std::endl;
    return os;
}
