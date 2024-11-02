#ifndef LAB_6_BEAR_H
#define LAB_6_BEAR_H
#include "npc.h"

class bear : public NPC
{
public:
    bear(int x, int y) : NPC(_bear, x, y) {}
    explicit bear(std::istream &is) : NPC(_bear, is) {}

    void print() override;
    void print(std::ostream &os) override;

    bool accept(std::shared_ptr<NPC> visitor);
    bool fight(std::shared_ptr<robber> other);
    bool fight(std::shared_ptr<wolf> other);
    bool fight(std::shared_ptr<bear> other);

    void save(std::ostream &os) override;

    friend std::ostream &operator<<(std::ostream & os, bear & bear);

};
#endif //LAB_6_BEAR_H
