//
// Created by Linux Oid on 06/12/2019.
//

#include "../headers/RealPlayer.h"

RealPlayer::RealPlayer(std::vector<DominoBlock> start_hand, Boneyard &boneyard) : hand_(std::move(start_hand)),
                                                                                  boneyard(boneyard) {}

std::pair<bool, DominoBlock> RealPlayer::GetDominoBlock() {
    return boneyard.GetDominoBlock(this);
}

bool RealPlayer::step(Board &) {
    return true;
}
