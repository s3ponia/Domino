//
// Created by Linux Oid on 06/12/2019.
//

/**
 * \class Board
 * \brief Контейнер для костей, которые лежат на доске
 *
 * С помощью методов можно добавлять кость в начало или конец костяшек.
 *
 * \authors Heineken FAMS: Филипп Кутырев, Артем Смирнов, Николай Мамаевский, Вячеслав Шляга
 */

#ifndef DOMINO_BOARD_H
#define DOMINO_BOARD_H

#include <deque>
#include "DominoBlock.h"

class Board {
public:
    /// Создает пустую доску
    Board() = default;

    /// Перемещающий конструктор
    Board(Board &&) noexcept(std::is_nothrow_move_constructible<std::deque<DominoBlock>>::value);

    /// Конструктор копирования
    Board(Board const &) noexcept(std::is_nothrow_copy_assignable<std::deque<DominoBlock>>::value) = default;

    /// \return первую кость
    [[nodiscard]] DominoBlock front() const;

    /// \return последнюю кость
    [[nodiscard]] DominoBlock back() const;

    /// \return количество костей на доске
    [[nodiscard]] std::deque<DominoBlock>::size_type size() const noexcept;

    /// \return константный итератор на первую кость
    [[nodiscard]] std::deque<DominoBlock>::const_iterator begin() const noexcept;

    /// \return константный итератор указывающий после последней кости
    [[nodiscard]] std::deque<DominoBlock>::const_iterator end() const noexcept;

    /// \return пустая ли доска
    [[nodiscard]] bool empty() const noexcept;

    /**
     * \param[in] bone - добавляемая в начало кость
     * \brief Добавляет кость в начало доски
     *
     * Добавляет кость в начало доски.
     * Если кость не подходит, возвращает false, иначе возвращает true.
     *
     * \return true если кость подходит, иначе false
     */
    void PushFront(const DominoBlock &block);

    /**
     * \param block - добавляемая в конец кость
     * \brief Добавляет кость в конец доски
     *
     * Добавляет кость в конец доски.
     * Если кость не подходит, возвращает false, иначе возвращает true.
     *
     * \return true если кость подходит, иначе false
     */
    void PushBack(const DominoBlock &block);

private:
    std::deque<DominoBlock> board_; /*!< Дека, хранящая лежащие на столе кости */
};


#endif //DOMINO_BOARD_H
