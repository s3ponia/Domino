//
// Created by Linux Oid on 06/12/2019.
//

#include "../headers/Game.h"

void Game::step() {
    for (auto player: players_) {
        player->step(board_);
    }
}

Game::Game(Board board, std::vector<IPlayer *> players) : board_(std::move(board)), players_(std::move(players)) {}
