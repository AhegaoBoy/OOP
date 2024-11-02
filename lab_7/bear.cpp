#include "wolf.h"
#include "bear.h"
#include "robber.h"

void bear::print()
{
    std::cout << *this;
}

void bear::print(std::ostream &outfs) {
    outfs << *this;
}

bool bear::accept(std::shared_ptr<NPC> visitor) {
    return visitor->fight(std::shared_ptr<bear>(this,[](bear*){}));
}


void bear::save(std::ostream &os)
{
    os << _bear << std::endl;
    NPC::save(os);
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

std::ostream &operator<<(std::ostream &os, bear &bear)
{
    os << "bear : " << *static_cast<NPC *>(&bear) << std::endl;
    return os;
}