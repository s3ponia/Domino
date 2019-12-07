//
// Created by Linux Oid on 06/12/2019.
//

#include "../headers/DominoBlock.h"

DominoBlock::DominoBlock(ValueType f, ValueType s) : first_(f), last_(s) {}

DominoBlock::ValueType DominoBlock::first() const {
    return first_;
}

DominoBlock::ValueType DominoBlock::last() const {
    return last_;
}

bool operator==(const DominoBlock &block1, const DominoBlock &block2) {
    return block1.first_ == block2.first_ && block2.last_ == block1.last_;
}

size_t HashDominoBlock::operator()(const DominoBlock &block) const {
    return (static_cast<size_t>(block.first()) << sizeof(decltype(block.first()))) |
           static_cast<size_t>(block.last());
}

DominoBlock SwapFields(DominoBlock const &block) {
    return {block.last(), block.first()};
}

std::string ToString(DominoBlock const &block) {
    return "{" +
           std::to_string(block.first()) + ", " + std::to_string(block.last()) +
           "}";
}