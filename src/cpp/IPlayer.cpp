//
// Created by Linux Oid on 21/12/2019.
//

#include "../headers/IPlayer.h"

#include <utility>

IPlayer::IPlayer(std::vector<DominoBlock> hand) : hand_(std::move(hand)) {}

void IPlayer::StoreDominoBlock(DominoBlock const &bone) {
    hand_.push_back(bone);
}
