//
// Created by Linux Oid on 06/12/2019.
//

#ifndef DOMINO_DOMINOBLOCK_H
#define DOMINO_DOMINOBLOCK_H


#include <cstddef>

class DominoBlock {
public:
    DominoBlock(char, char);

    char first() const;

    char second() const;

private:
    friend bool operator==(const DominoBlock &block1, const DominoBlock &block2) {
        return block1.first_ == block2.first_ && block2.second_ == block1.second_;
    }

    char first_;
    char second_;
};

struct HashBoneyard {
    size_t operator()(const DominoBlock &block) const {
        return ((size_t) block.first() << sizeof(decltype(block.first()))) + block.second();
    }
};


#endif //DOMINO_DOMINOBLOCK_H
