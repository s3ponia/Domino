//
// Created by Linux Oid on 16/12/2019.
//

#ifndef DOMINO_UIMODEL_H
#define DOMINO_UIMODEL_H

#include <vector>
#include "DominoBlock.h"
#include "RealPlayer.h"
#include "Board.h"
#include <ncurses.h>

#define CHOSEN_COLOR_PAIR 2

class UIModel {
public:
    explicit UIModel(WINDOW *window);

    void PrintHand(IPlayer::HandType const &hand, int chosen);

    void PrintBoard(Board const &board);

    void Clear() noexcept;

    chtype GetChar() noexcept;

    /**
     * @param board - place for bone
     * @param bone - chosen bone
     * @return side or illegal
     */
    RealPlayer::StepMode RealPlayerChooseInterface(Board const &board, DominoBlock const &bone);

private:
    void PrintRealPlayerChooseInterface(Board board, DominoBlock const &bone, bool front_side);

    void PrintVerticalBone(DominoBlock const &bone);

    void PrintHand(std::vector<DominoBlock> const &hand, int chosen, int coor_y, int coor_x);

    void PrintBoard(Board const &board, int coor_y, int coor_x);

    void PrintHorizontalBone(DominoBlock const &bone);

    WINDOW *window_;
};


#endif //DOMINO_UIMODEL_H
