//
// Created by Linux Oid on 06/12/2019.
//

#ifndef DOMINO_BONEYARD_H
#define DOMINO_BONEYARD_H

#include "IPlayer.h"
#include "DominoBlock.h"
#include <vector>
#include <unordered_set>
#include <map>
#include <utility>

class Boneyard {
public:
    using HandType = std::unordered_set<DominoBlock, HashDominoBlock>;

    explicit Boneyard(std::vector<DominoBlock>);

    /**
     * @return пару, первое значение которой это булево значение означающее закончились ли фишки,
     *  а вторая - сама фишка
     */
    DominoBlock GetDominoBlock();

    HandType const &GetPlayerHand(IPlayer *);

    bool empty() const noexcept;

    std::vector<DominoBlock>::size_type size() const noexcept;

private:
    std::vector<DominoBlock> heap_;
    std::map<IPlayer *, HandType> players_hand_;
};

#endif //DOMINO_BONEYARD_H
