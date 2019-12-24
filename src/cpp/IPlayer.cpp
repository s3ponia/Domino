//
// Created by Linux Oid on 21/12/2019.
//

#include "../headers/IPlayer.h"

#include <utility>

IPlayer::IPlayer(std::vector<DominoBlock> hand) : hand_(std::move(hand)) {}

void IPlayer::StoreDominoBlock(DominoBlock const &bone) {
    hand_.push_back(bone);
}

const IPlayer::HandType &IPlayer::hand() const noexcept {
    return hand_;
}

DominoBlock IPlayer::RemoveBlock(DominoBlock bone) {
    hand_.erase(std::remove(hand_.begin(), hand_.end(), bone), hand_.end());
    return bone;
}

bool IPlayer::IsReady(const Board &board) const noexcept {
    if (board.empty())
        return true;
    auto start = board.front().first();
    auto end = board.back().last();
    for (auto bone: hand_) {
        if (bone.first() == start || bone.last() == start) {
            return true;
        }
        if (bone.first() == end || bone.last() == end) {
            return true;
        }
    }
    return false;
}
