//
// Created by Linux Oid on 06/12/2019.
//

#include "../headers/DominoBlock.h"

DominoBlock::DominoBlock(ValueType f, ValueType s) noexcept : first_(f), last_(s) {}

DominoBlock::ValueType DominoBlock::first() const noexcept {
    return first_;
}

DominoBlock::ValueType DominoBlock::last() const noexcept {
    return last_;
}

DominoBlock &DominoBlock::operator=(DominoBlock const &rhs) = default;

bool operator==(const DominoBlock &block1, const DominoBlock &block2) noexcept {
    return block1.first() == block2.first() && block2.last() == block1.last();
}

size_t HashDominoBlock::operator()(const DominoBlock &block) const noexcept {
    return (static_cast<size_t>(block.first()) << sizeof(decltype(block.first()))) |
           static_cast<size_t>(block.last());
}

DominoBlock SwapFields(DominoBlock const &block) noexcept {
    return {block.last(), block.first()};
}

std::string ToString(DominoBlock const &block) {
    return "{" +
           std::to_string(block.first()) + ", " + std::to_string(block.last()) +
           "}";
}