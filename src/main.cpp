#define NDEBUG

#include "headers/Game.h"
#include "headers/RealPlayer.h"
#include "headers/Board.h"
#include "headers/UIRealPlayer.h"
#include "headers/UIModel.h"
#include "headers/UIComputer.h"
#include <tuple>

int main() {
    Board board;
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
    raw();
    UIModel uiModel(window);
    std::vector<DominoBlock> hand = {
            {1, 2},
            {2, 3},
            {3, 3},
            {3, 1}
    };
    for (auto const &bone : hand) {
        board.PushBack(bone);
    }

    Game game(board, {std::make_shared<UIRealPlayer>(std::make_unique<RealPlayer>(std::vector<DominoBlock>{{1, 1},
                                                                                                           {2, 3},
                                                                                                           {3, 4}}),
                                                     uiModel),
                      std::make_shared<UIComputer>(std::make_unique<Computer>(std::vector<DominoBlock>{{1, 1},
                                                                                                       {2, 3},
                                                                                                       {3, 4}}))},
              Boneyard({{1, 1},
                        {1, 1},
                        {1, 1}}), uiModel);
    while (game.run())
        game.step();

    uiModel.PrintBoard(board);
    endwin();
}