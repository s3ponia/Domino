//
// Created by Linux Oid on 06/12/2019.
//

#ifndef DOMINO_REALPLAYER_H
#define DOMINO_REALPLAYER_H

#include "IPlayer.h"
#include "Boneyard.h"
#include <vector>
#include <utility>

class RealPlayer : public IPlayer {
public:
    RealPlayer(std::vector<DominoBlock> start_hand, Boneyard &boneyard);

    bool step(Board &) override;

private:
    std::pair<bool, DominoBlock> GetDominoBlock();

    std::vector<DominoBlock> hand_;
    Boneyard &boneyard;
};


#endif //DOMINO_REALPLAYER_H
