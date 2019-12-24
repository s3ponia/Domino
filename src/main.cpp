#include "headers/UIModel.h"
#include "headers/GameBuilder.h"
#include <tuple>
#include <chrono>
#include <thread>

int main() {
    using namespace std::chrono_literals;
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
    auto game = GameBuilder::Build(ui_model);
    while (game.run()) {
        game.step();
        std::this_thread::sleep_for(100ms);
    }
    endwin();
}