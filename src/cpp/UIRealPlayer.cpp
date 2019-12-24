//
// Created by Linux Oid on 16/12/2019.
//

#include "../headers/UIRealPlayer.h"
#include <ncurses.h>

bool UIRealPlayer::Step(Board &board) {
    player_->step(board);
    return true;
}

bool UIRealPlayer::Handle(int input, Board const &board) {
    bool ready = false;
    switch (input) {
        case KEY_RIGHT:
            if (chosen_bone_ < player_->hand().size() - 1)
                ++chosen_bone_;
            break;
        case KEY_LEFT:
            if (chosen_bone_ > 0)
                --chosen_bone_;
            break;
        case KEY_ENTER:
        case ' ':
            mode_ = model_.RealPlayerChooseInterface(board, player_->hand().at(chosen_bone_));
            ready = (mode_ != RealPlayer::StepMode::NONE);
            break;
        default:
            break;
    }
    if (ready)
        PrepareStep();
    return ready;
}

void UIRealPlayer::PrepareStep() {
    player_->SetStep(mode_, player_->hand().at(chosen_bone_));
    if (chosen_bone_ > 0 && chosen_bone_ >= player_->hand().size() - 1)
        --chosen_bone_;
}

UIRealPlayer::UIRealPlayer(std::unique_ptr<RealPlayer> player, UIModel &model) : player_(std::move(player)),
                                                                                 model_(model) {}

void UIRealPlayer::PrintHand() {
    model_.PrintHand(player_->hand(), chosen_bone_);
}

IPlayer &UIRealPlayer::player() {
    return *player_;
}
