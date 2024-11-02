#ifndef LAB_7_BEAR_H
#define LAB_7_BEAR_H

#include "npc.h"

struct bear : public NPC{
    bear(int x, int y) : NPC(_bear, x, y){};
    bear(std::istream &is) : NPC(_bear, is){};

    void print() override;
    void print(std::ostream &os) override;
    bool accept(std::shared_ptr<NPC> visitor) override;
    bool fight(std::shared_ptr<robber> other) override;
    bool fight(std::shared_ptr<wolf> other) override;
    bool fight(std::shared_ptr<bear> other) override;
    void save(std::ostream &os) override;
    friend std::ostream &operator<<(std::ostream &os, bear  &bear);
};

#endif
