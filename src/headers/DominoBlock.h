//
// Created by Linux Oid on 06/12/2019.
//

/**
 * \class DominoBlock
 * \brief Класс, представляющий кости
 * \authors Heineken FAMS: Филипп Кутырев, Артем Смирнов, Николай Мамаевский, Вячеслав Шляга
 */

#ifndef DOMINO_DOMINOBLOCK_H
#define DOMINO_DOMINOBLOCK_H

#include <cstddef>
#include <cstdint>
#include <string>

class DominoBlock {
public:
    /*! \var using ValueType = uint8_t;
     * \brief Определние типа для значений
     */
    using ValueType = uint8_t;

    DominoBlock(ValueType, ValueType) noexcept;

    DominoBlock() = default;

    [[nodiscard]] ValueType first() const noexcept;

    [[nodiscard]] ValueType last() const noexcept;

    DominoBlock &operator=(DominoBlock const &rhs);

private:
    ValueType first_ = -1;
    ValueType last_ = -1;
};

bool operator==(const DominoBlock &block1, const DominoBlock &block2) noexcept;

struct HashDominoBlock {
    size_t operator()(const DominoBlock &block) const noexcept;
};

namespace std{
    template<>
    struct hash<DominoBlock> {
        size_t operator()(const DominoBlock &block) const noexcept;
    };
}

DominoBlock SwapFields(DominoBlock const &) noexcept;

std::string ToString(DominoBlock const &);


#endif //DOMINO_DOMINOBLOCK_H
