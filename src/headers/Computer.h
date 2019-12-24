//
// Created by Linux Oid on 06/12/2019.
//

#ifndef DOMINO_COMPUTER_H
#define DOMINO_COMPUTER_H

#include "IPlayer.h"
#include "Board.h"
#include <vector>

class Computer : public IPlayer {
public:
    explicit Computer(std::vector<DominoBlock> start_hand);

    Computer() = default;

    bool step(Board &) override;

private:
    DominoBlock BestBone(std::vector<DominoBlock> const &);
};


#endif //DOMINO_COMPUTER_H
