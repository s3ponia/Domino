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

    Board(Board const &) noexcept(std::is_nothrow_copy_assignable<std::deque<DominoBlock>>::value) = default;

    DominoBlock front() const;

    DominoBlock back() const;

    std::deque<DominoBlock>::size_type size() const noexcept;

    std::deque<DominoBlock>::const_iterator begin() const noexcept;

    std::deque<DominoBlock>::const_iterator end() const noexcept;

    std::deque<DominoBlock>::const_iterator cbegin() const noexcept;

    std::deque<DominoBlock>::const_iterator cend() const noexcept;

    /**
     * @param block
     * @return true if block pushed and false otherwise
     */
    bool PushFront(const DominoBlock &block);

    /**
     * @param block
     * @return true if block pushed and false otherwise
     */
    bool PushBack(const DominoBlock &);

private:
    std::deque<DominoBlock> board_;
};


#endif //DOMINO_BOARD_H
