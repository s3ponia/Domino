//
// Created by Linux Oid on 06/12/2019.
//

#include "../headers/Board.h"

DominoBlock Board::front() {
    return board_.front();
}

DominoBlock Board::back() {
    return board_.back();
}

void Board::PushFront(DominoBlock block) {
    board_.push_front(block);
}

void Board::PushBack(DominoBlock block) {
    board_.push_back(block);
}
