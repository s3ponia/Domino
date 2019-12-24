//
// Created by Linux Oid on 16/12/2019.
//

#include "../headers/UIModel.h"

void UIModel::PrintHand(IPlayer::HandType const &hand, int chosen) {
    decltype(hand.size()) width, height;
    getmaxyx(window_, height, width);
    auto hand_coor_x = width / 2ul - hand.size() * 3;
    auto hand_coor_y = height - 6;
    PrintHand(hand, chosen, hand_coor_y, hand_coor_x);
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
    auto coor_x = width / 2 - board.size() * 3;
    auto coor_y = height / 2;
    PrintBoard(board, coor_y, coor_x);
}

void UIModel::Clear() noexcept {
    if (window_ == nullptr)
        return;
    wclear(window_);
}

chtype UIModel::GetChar() noexcept {
    return wgetch(window_);
}

RealPlayer::StepMode UIModel::RealPlayerChooseInterface(Board const &board, DominoBlock const &bone) {
    if (board.empty()) {
        return RealPlayer::StepMode::FRONT;
    }
    bool run = true;
    bool front_side = true;
    auto front = board.front().first();
    auto back = board.back().last();
    if (bone.last() != front && bone.first() != front && bone.last() != back && bone.first() != back)
        return RealPlayer::StepMode::NONE;
    if (bone.last() != front && bone.first() != front) {
        PrintRealPlayerChooseInterface(board, bone, true);
        wrefresh(window_);
        return RealPlayer::StepMode::BACK;
    } else if (bone.last() != back && bone.first() != back) {
        PrintRealPlayerChooseInterface(board, bone, false);
        wrefresh(window_);
        return RealPlayer::StepMode::FRONT;
    }
    while (run) {
        Clear();
        PrintRealPlayerChooseInterface(board, bone, front_side);
        auto input = wgetch(window_);
        switch (input) {
            case KEY_LEFT:
                front_side = true;
                break;
            case KEY_RIGHT:
                front_side = false;
                break;
            case KEY_ENTER:
            case ' ':
                run = false;
                break;
            case 27:
            case 'q':
                return RealPlayer::StepMode::NONE;
            default:
                break;
        }
    }
    return front_side ? RealPlayer::StepMode::FRONT : RealPlayer::StepMode::BACK;
}

void UIModel::PrintRealPlayerChooseInterface(Board board, DominoBlock const &bone, bool front_side) {
    Board board_print(std::move(board));
    if (front_side) {
        board_print.PushFront(bone);
    } else {
        board_print.PushBack(bone);
    }
    PrintBoard(board_print);
}

void UIModel::PrintHand(std::vector<DominoBlock> const &hand, int chosen, int coor_y, int coor_x) {
    for (decltype(hand.size()) i = 0; i < hand.size(); ++i, coor_x += 4) {
        wmove(window_, coor_y, coor_x);
        if (i == chosen) {
            wattron(window_, COLOR_PAIR(CHOSEN_COLOR_PAIR));
            PrintVerticalBone(hand.at(i));
            wattroff(window_, COLOR_PAIR(CHOSEN_COLOR_PAIR));
        } else {
            PrintVerticalBone(hand.at(i));
        }
    }
}

void UIModel::PrintBoard(Board const &board, int coor_y, int coor_x) {
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

void UIModel::Print(int y, int x, std::string const &string) {
    mvwprintw(window_, y, x, string.c_str());
}

void UIModel::AttrOn(int attr) {
    wattron(window_, attr);
}

void UIModel::AttrOff(int attr) {
    wattroff(window_, attr);
}
