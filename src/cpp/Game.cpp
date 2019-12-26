//
// Created by Linux Oid on 06/12/2019.
//

#include "../headers/Game.h"
#include "../headers/UIPlayer.h"
#include "../headers/UIComputer.h"

std::string GetName(const std::shared_ptr<UIPlayer> &player) {
    return dynamic_cast<UIComputer *>(&*player) == nullptr ? "Player" : "Computer";
}

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
                     GetName(players_.at(i)) + ":" +
                     std::to_string(players_.at(i)->player().hand().size()));
        model_.AttrOff(COLOR_PAIR(CHOSEN_COLOR_PAIR));
    }
}


void Game::GameOver() {
    model_.Clear();
    std::vector<std::pair<int, int>> scores;
    for (decltype(players_.size()) i = 0; i < players_.size(); ++i) {
        scores.emplace_back(GetScore(players_.at(i)), i);
    }
    std::sort(scores.begin(), scores.end());
    int w, h;
    model_.GetMaxYX(h, w);
    h /= 2;
    w /= 2;
    w -= 7;
    h -= scores.size();
    model_.Print(h++, w,
                 "WINNER " + GetName(players_.at(scores.at(0).second)));
    model_.Print(h++, w,
                 "Score " + GetName(players_.at(scores.at(0).second)) + " " + std::to_string(0));
    for (decltype(scores.size()) i = 1; i < scores.size(); ++i) {
        auto temp = scores.at(i);
        model_.Print(h++, w, "Score " +
                             GetName(players_.at(temp.second)) + " " + std::to_string(temp.first));
    }
}


int Game::GetScore(std::shared_ptr<UIPlayer> const &player) {
    auto hand = player->player().hand();
    int score = 0;
    for (auto const &bone:hand) {
        if (bone.first() == 6 && bone.last() == 6) {
            score += 50;
        } else if (bone.first() == 0 && bone.last() == 0) {
            score += 25;
        } else {
            score += bone.last() + bone.first();
        }
    }
    return score;
}
