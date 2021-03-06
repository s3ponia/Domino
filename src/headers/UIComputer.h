//
// Created by Linux Oid on 16/12/2019.
//

#ifndef DOMINO_UICOMPUTER_H
#define DOMINO_UICOMPUTER_H

#include "UIPlayer.h"
#include "Computer.h"

class UIComputer : public UIPlayer {
public:
    UIComputer(std::unique_ptr<Computer> computer);

    void Step(Board &board) override;

    bool Handle(int, Board const &) override;

    Player &player() override;

    void PrintHand() override;

private:
    std::unique_ptr<Computer> computer_;
};


#endif //DOMINO_UICOMPUTER_H
