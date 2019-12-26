//
// Created by Linux Oid on 16/12/2019.
//

#include "../headers/UIComputer.h"

void UIComputer::Step(Board &board) {
    return computer_->step(board);
}

UIComputer::UIComputer(std::unique_ptr<Computer> computer) : computer_(std::move(computer)) {}

bool UIComputer::Handle(int, Board const &) {
    return true;
}

Player &UIComputer::player() {
    return *computer_;
}

void UIComputer::PrintHand() {}
