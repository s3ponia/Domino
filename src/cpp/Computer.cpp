//
// Created by Linux Oid on 06/12/2019.
//

#include "../headers/Computer.h"

void Computer::step(Board &board) {
    if (board.empty()) {
        auto bone = BestBone(hand_);
        assert(std::find(hand_.begin(), hand_.end(), bone) != hand_.end());
        board.PushBack(RemoveBlock(bone));
        assert(std::find(hand_.begin(), hand_.end(), bone) == hand_.end());
        return;
    }

    auto start = board.front().first();
    auto end = board.back().last();
    using ii = decltype(std::declval<DominoBlock>().first());
    std::vector<DominoBlock> start_can;
    std::vector<DominoBlock> end_can;
    for (auto bone: hand_) {
        if (bone.first() == start || bone.last() == start) {
            start_can.push_back(bone);
        }
        if (bone.first() == end || bone.last() == end) {
            end_can.push_back(bone);
        }
    }

    if (start_can.size() > end_can.size()) {
        auto bone = BestBone(start_can);
        assert(std::find(hand_.begin(), hand_.end(), bone) != hand_.end());
        board.PushFront(RemoveBlock(bone));
        assert(std::find(hand_.begin(), hand_.end(), bone) == hand_.end());
    } else if (!end_can.empty()) {
        auto bone = BestBone(end_can);
        assert(std::find(hand_.begin(), hand_.end(), bone) != hand_.end());
        board.PushBack(RemoveBlock(bone));
        assert(std::find(hand_.begin(), hand_.end(), bone) == hand_.end());
    }
}

Computer::Computer(std::vector<DominoBlock> start_hand) : Player(std::move(start_hand)) {}

DominoBlock Computer::BestBone(std::vector<DominoBlock> const &bone_vector) {
    assert(!bone_vector.empty());
    DominoBlock best_bone = bone_vector.at(0);
    for (auto bone:bone_vector) {
        if (bone.last() == bone.first())
            return bone;
        if (best_bone.first() + best_bone.last() < bone.last() + bone.first())
            best_bone = bone;
    }
    return best_bone;
}

