//
// Created by Linux Oid on 06/12/2019.
//

#ifndef DOMINO_REALPLAYER_H
#define DOMINO_REALPLAYER_H

#include "IPlayer.h"
#include "Boneyard.h"
#include <set>
#include <unordered_set>
#include <utility>

class RealPlayer : public IPlayer {
public:
    enum class StepMode : uint8_t;
    using HandType = std::unordered_set<DominoBlock, HashDominoBlock>;

    RealPlayer(HandType start_hand, Boneyard &boneyard_);

    bool step(Board &) override;

    const HandType &hand() const;

    void SetStep(StepMode const &, DominoBlock const &);

private:
    std::pair<bool, DominoBlock> GetDominoBlock();

    HandType hand_;
    Boneyard &boneyard_;
    StepMode step_mode_;
    DominoBlock step_block_;
};


#endif //DOMINO_REALPLAYER_H
