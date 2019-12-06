//
// Created by Linux Oid on 06/12/2019.
//

#include "../headers/Boneyard.h"

std::pair<bool, DominoBlock> Boneyard::GetDominoBlock(IPlayer *player) {
    if (heap_.empty())
        return std::make_pair(false, DominoBlock(0, 0));
    DominoBlock ret = heap_.back();
    heap_.pop_back();
    players_hand_[player].insert(ret);
    return std::make_pair(true, ret);
}

Boneyard::Boneyard(std::vector<DominoBlock> vector) : heap_(std::move(vector)) {
    static std::random_device rd;
    static std::mt19937 g{rd};
    std::shuffle(heap_.begin(), heap_.end(), g);
}
