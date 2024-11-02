#include "wolf.h"
#include "bear.h"
#include "robber.h"

void bear::print()
{
    std::cout << *this;
}


void bear::print(std::ostream &outfs)
{
    outfs << *this;
}

bool bear::accept(std::shared_ptr<NPC> visitor)
{
    std::shared_ptr<bear> This = std::make_shared<bear>(*this);
    return visitor->visit(This);
}

bool bear::fight(std::shared_ptr<bear> other)
{
    fight_notify(other, false);
    return false;
}

bool bear::fight(std::shared_ptr<robber> other)
{
    fight_notify(other, false);
    return false;
}

bool bear::fight(std::shared_ptr<wolf> other)
{
    fight_notify(other, true);
    return true;
}

void bear::save(std::ostream &os)
{
    os << _bear << std::endl;
    NPC::save(os);
}

std::ostream &operator<<(std::ostream &os, bear &bear)
{
    os << "bear: " << *static_cast<NPC *>(&bear) << std::endl;
    return os;
}