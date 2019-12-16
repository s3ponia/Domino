//
// Created by Linux Oid on 06/12/2019.
//

#include "../headers/RealPlayer.h"

enum class RealPlayer::StepMode : uint8_t {
    NONE, FRONT, BACK
};

RealPlayer::RealPlayer(HandType start_hand, Boneyard &boneyard_) : hand_(std::move(start_hand)),
                                                                   boneyard_(boneyard_),
                                                                   step_mode_(StepMode::NONE) {}

auto RealPlayer::GetDominoBlock() {
    return boneyard_.GetDominoBlock(this);
}

bool RealPlayer::step(Board &board) {
    switch(step_mode_) {
        case StepMode::FRONT:
            board.PushFront(step_block_);
            break;
        case StepMode::BACK:
            board.PushBack(step_block_);
            break;
        case StepMode::NONE:
            throw std::logic_error("Illegal state of step_mode_ in RealPlayer");
    }

    return true;
}

const RealPlayer::HandType &RealPlayer::hand() const {
    return hand_;
}

void RealPlayer::SetStep(const RealPlayer::StepMode &mode, DominoBlock const &block) {
    step_mode_ = mode;
    step_block_ = block;
}

RealPlayer::RealPlayer(Boneyard &boneyard) : boneyard_(boneyard) {}
