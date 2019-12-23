//
// Created by Linux Oid on 06/12/2019.
//

#include "../headers/Game.h"

void Game::step() {
    bool step = false;
    for (auto const &player: players_) {
        bool ready;
        while (!boneyard_.empty() && !(ready = player->player().IsReady(board_))) {
            player->player().StoreDominoBlock(boneyard_.GetDominoBlock(&player->player()));
        }
        if (ready) {
            PreparePlayer(player);
            player->Step(board_);
            step = true;
        }
        if (player->player().hand().empty()) {
            run_ = false;
            break;
        }
    }
    run_ = step;
}

Game::Game(Board board, std::vector<std::shared_ptr<UIPlayer>> players, Boneyard boneyard, UIModel const &model)
        : board_(std::move(board)), players_(std::move(players)), boneyard_(std::move(boneyard)), model_(model) {}

bool Game::run() const noexcept {
    return run_;
}

void Game::PreparePlayer(const std::shared_ptr<UIPlayer> &player) {
    do {
        model_.Clear();
        model_.PrintBoard(board_);
        player->PrintHand();
    } while (!player->Handle(model_.GetChar(), board_));
}
