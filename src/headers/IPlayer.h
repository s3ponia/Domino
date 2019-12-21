//
// Created by Linux Oid on 06/12/2019.
//

#ifndef DOMINO_IPLAYER_H
#define DOMINO_IPLAYER_H

#include "Board.h"
#include <vector>

class IPlayer {
public:
    IPlayer(std::vector<DominoBlock> hand);

    /**
     * @return может ли ходить игрок
     */
    virtual bool step(Board &) = 0;

    void StoreDominoBlock(DominoBlock const &bone);

    virtual ~IPlayer() = default;

protected:
    std::vector<DominoBlock> hand_;
};


#endif //DOMINO_IPLAYER_H
