#ifndef LAB_7_ROBBER_H
#define LAB_7_ROBBER_H
#include "npc.h"

struct robber : public NPC
{
    robber(int x, int y) : NPC(_robber, x, y){};
    robber(std::istream &is) : NPC(_robber, is) {};

    void print() override;
    void print(std::ostream &os) override;

    bool accept(std::shared_ptr<NPC> visitor) override;

    bool fight(std::shared_ptr<robber> other) override;
    bool fight(std::shared_ptr<wolf> other) override;
    bool fight(std::shared_ptr<bear> other) override;

    void save(std::ostream &os) override;

    friend std::ostream &operator<<(std::ostream &os, robber &robber);
};
#endif
