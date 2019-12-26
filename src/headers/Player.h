//
// Created by Linux Oid on 06/12/2019.
//

/**
 * \class Player
 * \brief
 */

#ifndef DOMINO_PLAYER_H
#define DOMINO_PLAYER_H

#include <vector>

class Board;
class DominoBlock;

class Player {
public:
    explicit Player(std::vector<DominoBlock> hand = {});

    using HandType = std::vector<DominoBlock>;

    /**
     * @return может ли ходить игрок
     */
    virtual void step(Board &board) = 0;

    void StoreDominoBlock(DominoBlock const &bone);

    const HandType &hand() const noexcept;

    bool IsReady(const Board &board) const noexcept;

    virtual ~Player() = default;

protected:
    DominoBlock RemoveBlock(DominoBlock bone);

    std::vector<DominoBlock> hand_;
};


#endif //DOMINO_PLAYER_H
