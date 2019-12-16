//
// Created by Linux Oid on 06/12/2019.
//

#ifndef DOMINO_DOMINOBLOCK_H
#define DOMINO_DOMINOBLOCK_H

#include <cstddef>
#include <cstdint>
#include <string>

class DominoBlock {
public:
    using ValueType = uint8_t;

    DominoBlock(ValueType, ValueType) noexcept;

    DominoBlock() = default;

    ValueType first() const noexcept;

    ValueType last() const noexcept;

private:
    ValueType first_ = -1;
    ValueType last_ = -1;
};

bool operator==(const DominoBlock &block1, const DominoBlock &block2) noexcept;

struct HashDominoBlock {
    size_t operator()(const DominoBlock &block) const noexcept;
};

DominoBlock SwapFields(DominoBlock const &) noexcept;

std::string ToString(DominoBlock const &);


#endif //DOMINO_DOMINOBLOCK_H
