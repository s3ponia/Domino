//
// Created by Linux Oid on 06/12/2019.
//

#ifndef DOMINO_GAME_H
#define DOMINO_GAME_H

#include "IPlayer.h"
#include "UIPlayer.h"
#include "Board.h"
#include "Boneyard.h"
#include <vector>
#include <utility>

class Game {
public:
    Game(Board board, std::vector<IPlayer *> players, Boneyard boneyard);

    void step();

    bool run() const noexcept;

private:
    Board board_;
    std::vector<IPlayer *> players_;
    Boneyard boneyard_;
    bool run_ = true;
};


#endif //DOMINO_GAME_H
