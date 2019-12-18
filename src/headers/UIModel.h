//
// Created by Linux Oid on 16/12/2019.
//

#ifndef DOMINO_UIBOARDMODEL_H
#define DOMINO_UIBOARDMODEL_H

#include <vector>
#include "DominoBlock.h"
#include "Board.h"
#include <ncurses.h>

#define CHOSEN_COLOR_PAIR 2

class UIBoardModel {
public:
    UIBoardModel(WINDOW *window);

    void PrintHand(std::vector<DominoBlock> const &hand, int chosen);

    void PrintBoard(Board const &);

    void clear() noexcept;

private:
    void PrintVerticalBone(DominoBlock const &bone);

    void PrintHorizontalBone(DominoBlock const &bone);

    WINDOW *window_;
};


#endif //DOMINO_UIBOARDMODEL_H
