//
// Created by Linux Oid on 06/12/2019.
//

#ifndef DOMINO_BOARD_H
#define DOMINO_BOARD_H

#include "DominoBlock.h"
#include <deque>

class Board {
public:
    DominoBlock front();

    DominoBlock back();

    void PushFront(DominoBlock block);

    void PushBack(DominoBlock);

private:
    std::deque<DominoBlock> board_;
};


#endif //DOMINO_BOARD_H
