#include "headers/UIModel.h"
#include "headers/GameBuilder.h"
#include "headers/UIRealPlayer.h"
#include "headers/UIComputer.h"
#include <tuple>

int main() {
    auto window = initscr();
    if (!has_colors()) {
        wprintw(window, "Terminal doesn't support colors.");
        exit(EXIT_FAILURE);
    }
    start_color();
    init_pair(CHOSEN_COLOR_PAIR, COLOR_RED, COLOR_BLACK);
    noecho();
    nocbreak();
    set_escdelay(0);
    timeout(0);
    curs_set(0);
    halfdelay(1);
    keypad(stdscr, TRUE);
    UIModel ui_model(window);
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
    auto computer = RealPlayer();

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

    auto ui_real_player = std::make_shared<UIRealPlayer>(
            std::make_unique<RealPlayer>(real_player),
            ui_model);
    auto ui_computer = std::make_shared<UIRealPlayer>(std::make_unique<RealPlayer>(computer), ui_model);

    auto players = (first_real_player ? std::vector<std::shared_ptr<UIPlayer>>{ui_real_player, ui_computer}
                                      : std::vector<std::shared_ptr<UIPlayer>>{ui_computer,
                                                                               ui_real_player});
    Game game(players, boneyard, ui_model);
    while (game.run())
        game.step();
    endwin();
}