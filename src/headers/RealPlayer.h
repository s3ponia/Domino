//
// Created by Linux Oid on 06/12/2019.
//

#ifndef DOMINO_REALPLAYER_H
#define DOMINO_REALPLAYER_H

#include "IPlayer.h"
#include "DominoBlock.h"

class RealPlayer : public IPlayer {
public:
    enum class StepMode {
        NONE, FRONT, BACK
    };

    explicit RealPlayer(HandType start_hand);

    RealPlayer() = default;

    bool step(Board &) override;

    void SetStep(StepMode const &, DominoBlock const &);

private:
    StepMode step_mode_ = StepMode::NONE;
    DominoBlock step_block_;
};


#endif //DOMINO_REALPLAYER_H
