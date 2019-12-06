//
// Created by Linux Oid on 06/12/2019.
//

#include "../headers/DominoBlock.h"

DominoBlock::DominoBlock(char f, char s) : first_(f), second_(s) { }

char DominoBlock::first() {
    return first_;
}

char DominoBlock::second() {
    return second_;
}
