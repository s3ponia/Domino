//
// Created by Linux Oid on 06/12/2019.
//

#ifndef DOMINO_IPLAYER_H
#define DOMINO_IPLAYER_H

#include "Board.h"

struct IPlayer {
    /**
     * @return может ли ходить игрок
     */
    virtual bool step(Board &) = 0;

    virtual void StoreDominoBlock(DominoBlock const &boneyard) = 0;

    virtual ~IPlayer() = default;
};


#endif //DOMINO_IPLAYER_H
