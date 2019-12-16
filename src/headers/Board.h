//
// Created by Linux Oid on 06/12/2019.
//

#ifndef DOMINO_BOARD_H
#define DOMINO_BOARD_H

#include "DominoBlock.h"
#include <deque>
#include <type_traits>

class Board {
public:
    Board() = default;

    Board(Board &&) noexcept(std::is_nothrow_move_constructible<std::deque<DominoBlock>>::value);

    DominoBlock front();

    DominoBlock back();

    void PushFront(DominoBlock block);

    void PushBack(DominoBlock);

private:
    std::deque<DominoBlock> board_;
};


#endif //DOMINO_BOARD_H
