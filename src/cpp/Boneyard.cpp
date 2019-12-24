//
// Created by Linux Oid on 06/12/2019.
//

#include "../headers/Boneyard.h"
#include <random>

DominoBlock Boneyard::GetDominoBlock() {
    if (heap_.empty())
        throw std::runtime_error("Boneyard is empty");
    DominoBlock ret = heap_.back();
    heap_.pop_back();
    return ret;
}

Boneyard::Boneyard(std::vector<DominoBlock> vector) : heap_(std::move(vector)) {
    static std::random_device rd;
    static std::mt19937 g{rd()};
    std::shuffle(heap_.begin(), heap_.end(), g);
}

const Boneyard::HandType &Boneyard::GetPlayerHand(IPlayer *player) {
    return players_hand_.at(player);
}

bool Boneyard::empty() const noexcept {
    return heap_.empty();
}

std::vector<DominoBlock>::size_type Boneyard::size() const noexcept {
    return heap_.size();
}
