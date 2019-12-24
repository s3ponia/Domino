//
// Created by Linux Oid on 06/12/2019.
//

#ifndef DOMINO_IPLAYER_H
#define DOMINO_IPLAYER_H

#include "Board.h"
#include <vector>

class IPlayer {
public:
    explicit IPlayer(std::vector<DominoBlock> hand = {});

    using HandType = std::vector<DominoBlock>;

    /**
     * @return может ли ходить игрок
     */
    virtual bool step(Board &) = 0;

    void StoreDominoBlock(DominoBlock const &bone);

    const HandType &hand() const noexcept;

    bool IsReady(const Board &board) const noexcept;

    virtual ~IPlayer() = default;

protected:
    const DominoBlock &RemoveBlock(DominoBlock const &bone);

    std::vector<DominoBlock> hand_;
};


#endif //DOMINO_IPLAYER_H
