//
// Created by Linux Oid on 06/12/2019.
//

#include <string>
#include "../headers/Board.h"

DominoBlock Board::front() const {
    return board_.front();
}

DominoBlock Board::back() const {
    return board_.back();
}

void Board::PushFront(const DominoBlock &block) {
    if (board_.empty()) {
        board_.push_back(block);
        return;
    }
    auto front_value = board_.front().first();
    if (block.first() == front_value) {
        board_.push_front(SwapFields(block));
        return;
    } else if (block.last() == front_value) {
        board_.push_front(block);
        return;
    }
}

void Board::PushBack(const DominoBlock &block) {
    if (board_.empty()) {
        board_.push_back(block);
        return;
    }
    auto back_value = board_.back().last();
    if (block.last() == back_value) {
        board_.push_back(SwapFields(block));
        return;
    } else if (block.first() == back_value) {
        board_.push_back(block);
        return;
    }
}

Board::Board(Board &&board) noexcept(std::is_nothrow_move_constructible<std::deque<DominoBlock> >::value) :
        board_(std::move(board.board_)) {}

std::deque<DominoBlock>::const_iterator Board::begin() const noexcept {
    return board_.begin();
}

std::deque<DominoBlock>::const_iterator Board::end() const noexcept {
    return board_.end();
}

std::deque<DominoBlock>::size_type Board::size() const noexcept {
    return board_.size();
}

bool Board::empty() const noexcept {
    return board_.empty();
}