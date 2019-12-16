//
// Created by Linux Oid on 06/12/2019.
//

#include "../headers/Computer.h"

bool Computer::step(Board &) {
    return true;
}

auto Computer::GetDominoBlock(Boneyard &boneyard) {
    return boneyard.GetDominoBlock(this);
}

Computer::Computer(std::vector<DominoBlock> start_hand) : hand_(std::move(start_hand)) {}
