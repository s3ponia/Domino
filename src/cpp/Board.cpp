//
// Created by Linux Oid on 06/12/2019.
//

#include <string>
#include "../headers/Board.h"

DominoBlock Board::front() {
    return board_.front();
}

DominoBlock Board::back() {
    return board_.back();
}

void Board::PushFront(DominoBlock block) {
    if (board_.empty()) {
        board_.push_back(block);
        return;
    }
    auto front_value = board_.front().first();
    if (block.first() == front_value)
        board_.push_front(SwapFields(block));
    else if (block.last() == front_value)
        board_.push_front(block);

    throw std::logic_error("Illegal block: " + ToString(block) + " opposite to " + ToString(board_.front()));
}

void Board::PushBack(DominoBlock block) {
    if (board_.empty()) {
        board_.push_back(block);
        return;
    }
    auto back_value = board_.back().last();
    if (block.last() == back_value)
        board_.push_back(SwapFields(block));
    else if (block.first() == back_value)
        board_.push_back(block);

    throw std::logic_error(
            "Illegal block " + ToString(block) + ": " + ToString(board_.back()) + " opposite to " + ToString(block));
}

Board::Board(Board &&board) noexcept(std::is_nothrow_move_constructible<std::deque<DominoBlock> >::value) :
        board_(std::move(board.board_)) {}
