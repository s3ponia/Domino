//
// Created by Linux Oid on 06/12/2019.
//

#ifndef DOMINO_GAME_H
#define DOMINO_GAME_H

#include "IPlayer.h"
#include "Board.h"
#include "Boneyard.h"
#include "UIModel.h"
#include <vector>
#include <utility>

class UIPlayer;

class Game {
public:
    Game(std::vector<std::shared_ptr<UIPlayer>> players, Boneyard boneyard, UIModel const &model);

    void step();

    bool run() const noexcept;

private:
    void PrintInfo(UIPlayer const &player);

    bool CheckDominoBlocks();

    void PreparePlayer(const std::shared_ptr<UIPlayer> &);

    Board board_;
    std::vector<std::shared_ptr<UIPlayer>> players_;
    Boneyard boneyard_;
    UIModel model_;
    bool run_ = true;
};


#endif //DOMINO_GAME_H
