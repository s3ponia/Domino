//
// Created by Linux Oid on 16/12/2019.
//

#ifndef DOMINO_UIPLAYER_H
#define DOMINO_UIPLAYER_H

#include "Board.h"

class UIPlayer {
public:
    virtual bool Step(Board &) = 0;

    /**
     * @return true if ready and false if not
     */
    virtual bool Handle(int, Board const &) = 0;

    virtual ~UIPlayer() = default;
};


#endif //DOMINO_UIPLAYER_H
