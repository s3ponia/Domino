//
// Created by Linux Oid on 06/12/2019.
//

#ifndef DOMINO_BONEYARD_H
#define DOMINO_BONEYARD_H

#include "DominoBlock.h"
#include <vector>
#include <unordered_set>

class Boneyard {
public:
    using HandType = std::unordered_set<DominoBlock, HashDominoBlock>;

    explicit Boneyard(std::vector<DominoBlock>);

    /**
     * @return пару, первое значение которой это булево значение означающее закончились ли фишки,
     *  а вторая - сама фишка
     */
    DominoBlock GetDominoBlock();

    bool empty() const noexcept;

    std::vector<DominoBlock>::size_type size() const noexcept;

private:
    std::vector<DominoBlock> heap_;
};

#endif //DOMINO_BONEYARD_H
