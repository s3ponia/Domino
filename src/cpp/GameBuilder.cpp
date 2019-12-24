//
// Created by Linux Oid on 21/12/2019.
//

#include "../headers/GameBuilder.h"
#include "../headers/UIRealPlayer.h"
#include "../headers/UIComputer.h"
#include <ncurses.h>

Game GameBuilder::Build(UIModel &ui_model) {
    Boneyard boneyard({{0, 0},
                       {0, 1},
                       {0, 2},
                       {0, 3},
                       {0, 4},
                       {0, 5},
                       {0, 6},
                       {1, 1},
                       {1, 2},
                       {1, 3},
                       {1, 4},
                       {1, 5},
                       {1, 6},
                       {2, 2},
                       {2, 3},
                       {2, 4},
                       {2, 5},
                       {2, 6},
                       {3, 3},
                       {3, 4},
                       {3, 5},
                       {3, 6},
                       {4, 4},
                       {4, 5},
                       {4, 6},
                       {5, 5},
                       {5, 6},
                       {6, 6}});

    auto real_player = RealPlayer();
    auto computer = Computer();

    bool first_real_player = true;
    DominoBlock min_pair((uint8_t) -1, (uint8_t) -1);

    for (int i = 0; i < 7; ++i) {
        auto temp_bone = boneyard.GetDominoBlock();
        real_player.StoreDominoBlock(temp_bone);

        if (temp_bone.first() == temp_bone.last() && temp_bone.last() < min_pair.last()) {
            min_pair = temp_bone;
            first_real_player = true;
        }

        temp_bone = boneyard.GetDominoBlock();
        computer.StoreDominoBlock(temp_bone);

        if (temp_bone.first() == temp_bone.last() && temp_bone.last() < min_pair.last()) {
            min_pair = temp_bone;
            first_real_player = false;
        }
    }

    if (min_pair.first() == (uint8_t) -1) {
        first_real_player = rand() % 2;
    }

    std::shared_ptr<UIRealPlayer> ui_real_player = std::make_shared<UIRealPlayer>(
            std::make_unique<RealPlayer>(real_player),
            ui_model);
    std::shared_ptr<UIComputer> ui_computer = std::make_shared<UIComputer>(std::make_unique<Computer>(computer));

    auto players = (first_real_player ? std::vector<std::shared_ptr<UIPlayer>>{ui_real_player, ui_computer}
                                      : std::vector<std::shared_ptr<UIPlayer>>{ui_computer,
                                                                               ui_real_player});

    return Game(std::move(players), std::move(boneyard), ui_model);
}
