//
// Created by Linux Oid on 06/12/2019.
//

#include "../headers/Game.h"

void Game::step() {
    bool last_step;
    for (auto const &player: players_) {
        while (!(last_step = player->step(board_)) && !boneyard_.empty()) {
            player->StoreDominoBlock(boneyard_.GetDominoBlock(player));
        }
        if (!last_step)
            run_ = last_step;
    }
}

Game::Game(Board board, std::vector<IPlayer *> players, Boneyard boneyard)
        : board_(std::move(board)), players_(std::move(players)), boneyard_(std::move(boneyard)) {}

bool Game::run() const noexcept {
    return run_;
}
