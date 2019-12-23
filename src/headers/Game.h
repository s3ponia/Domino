//
// Created by Linux Oid on 06/12/2019.
//

#ifndef DOMINO_GAME_H
#define DOMINO_GAME_H

#include "IPlayer.h"
#include "UIPlayer.h"
#include "Board.h"
#include "Boneyard.h"
#include "UIModel.h"
#include <vector>
#include <utility>

class Game {
public:
    Game(Board board, std::vector<UIPlayer *> players, Boneyard boneyard, UIModel const &model);

    void step();

    bool run() const noexcept;

private:
    void PreparePlayer(UIPlayer *);

    Board board_;
    std::vector<UIPlayer *> players_;
    Boneyard boneyard_;
    UIModel model_;
    bool run_ = true;
};


#endif //DOMINO_GAME_H
