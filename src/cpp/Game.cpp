//
// Created by Linux Oid on 06/12/2019.
//

#include "../headers/Game.h"
#include "../headers/UIPlayer.h"

void Game::step() {
    bool step = false;
    for (auto const &player: players_) {
        if (!CheckDominoBlocks())
            throw std::logic_error("Duplicate DominoBlocks");
        bool ready;
        while (!(ready = player->player().IsReady(board_)) && !boneyard_.empty()) {
            player->player().StoreDominoBlock(boneyard_.GetDominoBlock());
        }
        if (ready) {
            PreparePlayer(player);
            player->Step(board_);
            step = true;
        }
        if (player->player().hand().empty()) {
            run_ = false;
            return;
        }
    }
    run_ = step;
}

Game::Game(std::vector<std::shared_ptr<UIPlayer>> players, Boneyard boneyard, UIModel const &model)
        : players_(std::move(players)), boneyard_(std::move(boneyard)), model_(model) {}

bool Game::run() const noexcept {
    return run_;
}

void Game::PreparePlayer(const std::shared_ptr<UIPlayer> &player) {
    do {
        model_.Clear();
        PrintInfo(*player);
        model_.PrintBoard(board_);
        player->PrintHand();
    } while (!player->Handle(model_.GetChar(), board_));
}

bool Game::CheckDominoBlocks() {
    std::unordered_set<DominoBlock, HashDominoBlock> set;
    for (auto const &player:players_) {
        for (auto const &bone:player->player().hand()) {
            auto const &[it, ret] = set.insert(bone);
            if (!ret)
                return false;
        }
    }
    for (auto const &bone:board_) {
        auto const &[it, ret] = set.insert(bone);
        if (!ret)
            return false;
    }
    return true;
}

void Game::PrintInfo(UIPlayer const &player) {
    model_.Print(0, 0, "Boneyard: " + std::to_string(boneyard_.size()));
    for (int i = 0; i < players_.size(); ++i) {
        auto const &p = *players_.at(i);
        if (&player == &p)
            model_.AttrOn(COLOR_PAIR(CHOSEN_COLOR_PAIR));
        model_.Print(i + 1, 0,
                     "Player " + std::to_string(i) + ":" + std::to_string(players_.at(i)->player().hand().size()));
        model_.AttrOff(COLOR_PAIR(CHOSEN_COLOR_PAIR));
    }
}
