//
// Created by Linux Oid on 16/12/2019.
//

#ifndef DOMINO_UIPLAYER_H
#define DOMINO_UIPLAYER_H

class Board;
class Player;

class UIPlayer {
public:
    virtual void Step(Board &board) = 0;

    /**
     * @return true if ready and false if not
     */
    virtual bool Handle(int, Board const &) = 0;

    virtual Player &player() = 0;

    virtual void PrintHand() = 0;

    virtual ~UIPlayer() = default;
};


#endif //DOMINO_UIPLAYER_H
