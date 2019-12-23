//
// Created by Linux Oid on 06/12/2019.
//

#include "../headers/RealPlayer.h"

RealPlayer::RealPlayer(HandType start_hand) : IPlayer(std::move(start_hand)),
                                              step_mode_(StepMode::NONE) {}

bool RealPlayer::step(Board &board) {
    switch (step_mode_) {
        case StepMode::FRONT:
            board.PushFront(RemoveBlock(step_block_));
            break;
        case StepMode::BACK:
            board.PushBack(RemoveBlock(step_block_));
            break;
        case StepMode::NONE:
            throw std::logic_error("Illegal state of step_mode_ in RealPlayer");
    }

    return true;
}

void RealPlayer::SetStep(const RealPlayer::StepMode &mode, DominoBlock const &block) {
    step_mode_ = mode;
    step_block_ = block;
}
