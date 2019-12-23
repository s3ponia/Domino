//
// Created by Linux Oid on 06/12/2019.
//

#include "../headers/Game.h"

void Game::step() {
    for (auto const &player: players_) {
        while (!boneyard_.empty() && !player->player().IsReady(board_)) {
            player->player().StoreDominoBlock(boneyard_.GetDominoBlock(&player->player()));
        }
        PreparePlayer(player);
        player->Step(board_);
    }
}

Game::Game(Board board, std::vector<UIPlayer *> players, Boneyard boneyard, UIModel const &model)
        : board_(std::move(board)), players_(std::move(players)), boneyard_(std::move(boneyard)), model_(model) {}

bool Game::run() const noexcept {
    return !boneyard_.empty();
}

void Game::PreparePlayer(UIPlayer *player) {
    do {
        model_.Clear();
        model_.PrintBoard(board_);
        player->PrintHand();
    } while (!player->Handle(model_.GetChar(), board_));
}
