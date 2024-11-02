#ifndef LAB_7_WOLF_H
#define LAB_7_WOLF_H

#include "npc.h"

struct wolf : public NPC
{
    wolf(int x, int y) : NPC(_wolf, x, y) {};
    wolf(std::istream &is) : NPC(_wolf, is){};

    void print() override;
    void print(std::ostream &os) override;

    bool accept(std::shared_ptr<NPC> other) override;

    bool fight(std::shared_ptr<wolf> other) override;
    bool fight(std::shared_ptr<robber> other) override;
    bool fight(std::shared_ptr<bear> other) override;

    void save(std::ostream &os) override;

    friend std::ostream &operator<<(std::ostream &os, wolf &wolf);
};
#endif
