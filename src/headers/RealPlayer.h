//
// Created by Linux Oid on 06/12/2019.
//

#ifndef DOMINO_REALPLAYER_H
#define DOMINO_REALPLAYER_H

#include "Player.h"
#include "DominoBlock.h"

class RealPlayer : public Player {
public:
    enum class StepMode {
        NONE, FRONT, BACK
    };

    explicit RealPlayer(HandType start_hand);

    RealPlayer() = default;

    void step(Board &board) override;

    void SetStep(StepMode const &, DominoBlock const &);

private:
    StepMode step_mode_ = StepMode::NONE;
    DominoBlock step_block_;
};


#endif //DOMINO_REALPLAYER_H
