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
    explicit Computer(Boneyard &boneyard);

    Computer(std::vector<DominoBlock> start_hand, Boneyard &boneyard);

    void step(Board &) override;

private:
    std::pair<bool, DominoBlock> GetDominoBlock();
    std::vector<DominoBlock> hand_;
    Boneyard& boneyard;
};


#endif //DOMINO_COMPUTER_H
