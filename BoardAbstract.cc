#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include "BoardAbstract.h"
#include "IBlock.h"
#include "JBlock.h"
#include "LBlock.h"
#include "OBlock.h"
#include "SBlock.h"
#include "ZBlock.h"
#include "TBlock.h"

using namespace std;

BoardAbstract::~BoardAbstract() {}

int BoardAbstract::removeRow(int row) {
    int total = 0;


    for (auto block : blocksVec) {
        for (auto &coord : block->getAllPixels()) {
            if (coord.x == row) {     // yeet all points on this row out of the board
                coord.x = -10000;
                coord.y = -10000;
            }
        }
    }

    for (auto block : blocksVec) {
        for (auto &coord : block->getAllPixels()) {
            if ((coord.x >= 0) && (coord.x < row)) {    // drop down by 1 row the blocks on top 
                coord.x++;
            }
        }
    }



    for (auto block : blocksVec) {  // maybe could remove block from vector
        int pixelsCleared = 0;
        for (auto &coord : block->getAllPixels()) {
            if (coord.x == -1) {    // checks if a full block has been cleared
                pixelsCleared++;
            }
            if (pixelsCleared == 4) {
                total = (block->getLevel() + 1) * (block->getLevel() + 1);
            }
        }
    }

    return total;
}

void BoardAbstract::addBlock(std::shared_ptr<Block> block) {
    blocksVec.emplace_back(block);
}

std::shared_ptr<Block> BoardAbstract::force(char block, int level) {
    blocksVec.erase(blocksVec.end()-1);   //might not need to pop back...depends if blocks are automatically added onto blocksVec or not
    if (block == 'I') {
        blocksVec.emplace_back(new IBlock(level)); // Add level
    } else if (block == 'J') {
        blocksVec.emplace_back(new JBlock(level));
    } else if (block == 'L') {
        blocksVec.emplace_back(new LBlock(level));
    } else if (block == 'O') {
        blocksVec.emplace_back(new OBlock(level));
    } else if (block == 'S') {
        blocksVec.emplace_back(new SBlock(level));
    } else if (block == 'T') {
        blocksVec.emplace_back(new TBlock(level));
    } else if (block == 'Z') {
        blocksVec.emplace_back(new ZBlock(level));
    } else {
        cout << block << " is an invalid block. Please choose a valid block!" << endl;
    }

    return blocksVec.at((blocksVec.size() - 1));
}

char BoardAbstract::actualCharAt(int row, int col) {
    for (auto block : blocksVec) {
        for (auto coord : block->getAllPixels()) {
            if ((coord.x == row) && (coord.y == col)) {
                return block->getC();
            }
        }
    }
    return ' ';
}

