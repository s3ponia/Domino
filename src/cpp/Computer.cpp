//
// Created by Linux Oid on 06/12/2019.
//

#include "../headers/Computer.h"

Computer::Computer(Boneyard &boneyard) : boneyard(boneyard) {}

void Computer::step(Board &) {

}

std::pair<bool, DominoBlock> Computer::GetDominoBlock() {
    return boneyard.GetDominoBlock(this);
}

Computer::Computer(std::vector<DominoBlock> start_hand, Boneyard &boneyard) : hand_(std::move(start_hand)), boneyard(boneyard) {}
