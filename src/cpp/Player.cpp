//
// Created by Linux Oid on 21/12/2019.
//

#include "../headers/Player.h"
#include "../headers/DominoBlock.h"
#include "../headers/Board.h"
#include <utility>

Player::Player(std::vector<DominoBlock> hand) : hand_(std::move(hand)) {}

void Player::StoreDominoBlock(DominoBlock const &bone) {
    hand_.push_back(bone);
}

const Player::HandType &Player::hand() const noexcept {
    return hand_;
}

DominoBlock Player::RemoveBlock(DominoBlock bone) {
    hand_.erase(std::remove(hand_.begin(), hand_.end(), bone), hand_.end());
    return bone;
}

bool Player::IsReady(const Board &board) const noexcept {
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
