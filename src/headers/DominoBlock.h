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

    DominoBlock(ValueType, ValueType);

    DominoBlock() = default;

    ValueType first() const;

    ValueType last() const;

private:
    friend bool operator==(const DominoBlock &block1, const DominoBlock &block2);

    ValueType first_ = -1;
    ValueType last_ = -1;
};

struct HashDominoBlock {
    size_t operator()(const DominoBlock &block) const;
};

DominoBlock SwapFields(DominoBlock const &);

std::string ToString(DominoBlock const &);


#endif //DOMINO_DOMINOBLOCK_H
