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
    enum class StepMode {
        NONE, FRONT, BACK
    };
    using HandType = std::vector<DominoBlock>;

    explicit RealPlayer(HandType start_hand);

    RealPlayer() = delete;

    bool step(Board &) override;

    const HandType &hand() const noexcept;

    void SetStep(StepMode const &, DominoBlock const &);

    void StoreDominoBlock(const DominoBlock &bone) override;

private:
    HandType hand_;
    StepMode step_mode_ = StepMode::NONE;
    DominoBlock step_block_;
};


#endif //DOMINO_REALPLAYER_H
