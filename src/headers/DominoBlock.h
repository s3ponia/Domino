//
// Created by Linux Oid on 06/12/2019.
//

#ifndef DOMINO_DOMINOBLOCK_H
#define DOMINO_DOMINOBLOCK_H


class DominoBlock {
public:
    DominoBlock(char, char);

    char first();

    char second();

private:
    char first_;
    char second_;
};


#endif //DOMINO_DOMINOBLOCK_H
