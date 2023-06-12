#ifndef BOARD_ABSTRACT_H
#define BOARD_ABSTRACT_H

#include <string>
#include <vector>
#include <utility>
#include <memory>
#include "myBlock.h"

class BoardAbstract {

public:
    std::vector<std::shared_ptr<Block>> blocksVec;

    virtual ~BoardAbstract();

    virtual char charAt(int row, int col) = 0;
    int removeRow(int row);
    virtual void addBlock(std::shared_ptr<Block> block);
    virtual std::shared_ptr<Block> force(char block, int level);
    virtual char actualCharAt(int row, int col);
};


#endif
