//
// Created by Linux Oid on 06/12/2019.
//

#include "../headers/Computer.h"

bool Computer::step(Board &board) {
    if (board.empty()) {
        board.PushBack(BestBone(hand_));
        return true;
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
        board.PushFront(BestBone(start_can));
        return true;
    } else if (!end_can.empty()) {
        board.PushBack(BestBone(end_can));
        return true;
    }

    return false;
}

Computer::Computer(std::vector<DominoBlock> start_hand) : IPlayer(std::move(start_hand)) {}

DominoBlock Computer::BestBone(std::vector<DominoBlock> const &bone_vector) {
    DominoBlock best_bone(-1, -1);
    for (auto bone:bone_vector) {
        if (bone.last() == bone.first())
            return bone;
        if (best_bone.first() + best_bone.last() > bone.last() + bone.first())
            best_bone = bone;
    }
    return RemoveBlock(best_bone);
}

