//
// Created by Linux Oid on 16/12/2019.
//

#ifndef DOMINO_UIREALPLAYER_H
#define DOMINO_UIREALPLAYER_H

#include "UIPlayer.h"
#include "RealPlayer.h"
#include "UIModel.h"
#include <memory>

class UIRealPlayer : public UIPlayer {
public:
    UIRealPlayer(std::unique_ptr<RealPlayer> player, UIModel &model);

    bool Step(Board &) override;

    bool Handle(int, Board const &) override;

    void PrintHand() override;

    IPlayer &player() override;

private:
    void PrepareStep();

    std::unique_ptr<RealPlayer> player_;
    UIModel &model_;
    int chosen_bone_ = 0;
    RealPlayer::StepMode mode_ = RealPlayer::StepMode::NONE;
};


#endif //DOMINO_UIREALPLAYER_H
