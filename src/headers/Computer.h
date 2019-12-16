//
// Created by Linux Oid on 06/12/2019.
//

#ifndef DOMINO_COMPUTER_H
#define DOMINO_COMPUTER_H

#include "IPlayer.h"
#include "Board.h"
#include "Boneyard.h"
#include <vector>
#include <utility>

class Computer : public IPlayer {
public:
    Computer(std::vector<DominoBlock> start_hand);

    bool step(Board &) override;

private:
    static DominoBlock BestBone(std::vector<DominoBlock> const &);

    std::pair<bool, DominoBlock> GetDominoBlock(Boneyard &boneyard);
    std::vector<DominoBlock> hand_;
};


#endif //DOMINO_COMPUTER_H
