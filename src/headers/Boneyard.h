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
#include <random>

class Boneyard {
public:
    explicit Boneyard(std::vector<DominoBlock>);

    /**
     * @return пару, первое значение которой это булево значение означающее закончились ли фишки,
     *  а вторая - сама фишка
     */
    std::pair<bool, DominoBlock> GetDominoBlock(IPlayer *);

private:
    std::vector<DominoBlock> heap_;
    std::map<IPlayer *, std::unordered_set<DominoBlock>> players_hand_;
};


#endif //DOMINO_BONEYARD_H
