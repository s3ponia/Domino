#define NDEBUG

#include "headers/Game.h"
#include "headers/RealPlayer.h"
#include "headers/Board.h"
#include "headers/UIRealPlayer.h"
#include "headers/UIModel.h"
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
    UIRealPlayer uiRealPlayer(std::make_unique<RealPlayer>(std::vector<DominoBlock>{{1, 1},
                                                                                    {2, 3},
                                                                                    {3, 4}}), uiModel);
    std::vector<DominoBlock> hand = {
            {1, 2},
            {2, 3},
            {3, 3},
            {3, 1}
    };
    for (auto const &bone : hand) {
        board.PushBack(bone);
    }
    do {
        uiModel.Clear();
        uiModel.PrintBoard(board);
        uiRealPlayer.PrintHand();
    } while (!uiRealPlayer.Handle(uiModel.GetChar(), board));
    uiModel.PrintBoard(board);
    endwin();
}