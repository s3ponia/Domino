//
// Created by Linux Oid on 16/12/2019.
//

#include "../headers/UIModel.h"

void UIModel::PrintHand(std::vector<DominoBlock> const &hand, int chosen) {
    decltype(hand.size()) width, height;
    getmaxyx(window_, height, width);
    int hand_coor_x = width / 2ul - hand.size() * 3ul;
    int hand_coor_y = height - 6;
    for (decltype(hand.size()) i = 0; i < hand.size(); ++i, hand_coor_x += 4) {
        wmove(window_, hand_coor_y, hand_coor_x);
        if (i == chosen) {
            wattron(window_, COLOR_PAIR(CHOSEN_COLOR_PAIR));
            PrintVerticalBone(hand.at(i));
            wattroff(window_, COLOR_PAIR(CHOSEN_COLOR_PAIR));
        } else {
            PrintVerticalBone(hand.at(i));
        }
    }
}

void UIModel::PrintVerticalBone(DominoBlock const &bone) {
    auto curx = getcurx(window_);
    auto cury = getcury(window_);
    mvwprintw(window_, cury++, curx, "---\n");
    mvwprintw(window_, cury++, curx, "|%d|\n", bone.first());
    mvwprintw(window_, cury++, curx, "---\n");
    mvwprintw(window_, cury++, curx, "|%d|\n", bone.last());
    mvwprintw(window_, cury, curx, "---\n");
}

void UIModel::PrintHorizontalBone(DominoBlock const &bone) {
    auto curx = getcurx(window_);
    auto cury = getcury(window_);

    mvwprintw(window_, cury++, curx, "-----\n");
    mvwprintw(window_, cury++, curx, "|%d|%d|\n", bone.first(), bone.last());
    mvwprintw(window_, cury, curx, "-----\n");
}

UIModel::UIModel(WINDOW *window) : window_(window) {}

void UIModel::PrintBoard(Board const &board) {
    decltype(board.size()) width, height;
    getmaxyx(window_, height, width);
    auto coor_x = width / 2 - board.size() * 5;
    auto coor_y = height / 2;
    for (auto it : board) {
        if (it.first() == it.last()) {
            wmove(window_, coor_y, coor_x);
            PrintVerticalBone(it);
            coor_x += 4;
        } else {
            wmove(window_, coor_y + 1ul, coor_x);
            PrintHorizontalBone(it);
            coor_x += 6;
        }
    }
}

void UIModel::clear() noexcept {
    if (window_ == nullptr)
        return;
    wclear(window_);
}
