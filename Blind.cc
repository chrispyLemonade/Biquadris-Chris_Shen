#include <vector>
#include "Blind.h"
#include "BoardAbstract.h"
#include "IBlock.h"
#include "JBlock.h"
#include "LBlock.h"
#include "OBlock.h"
#include "SBlock.h"
#include "ZBlock.h"
#include "TBlock.h"
using namespace std;

Blind::Blind(shared_ptr<BoardAbstract> myBoard) : Decorator{myBoard} {}
Blind::~Blind() {}

char Blind::charAt(int row, int col) {
    if ((row >= 2) && (row <= 11) && (col >= 2) && (col <= 8)) {
        return '?';
    } else {
        return myBoard->charAt(row, col);
    }
}

char Blind::actualCharAt(int row, int col) {
    for (auto block : myBoard->blocksVec) {
        for (auto coord : block->getAllPixels()) {
            if ((coord.x == row) && (coord.y == col)) {
                return block->getC();
            }
        }
    }
    return ' ';
}

std::shared_ptr<Block> Blind::force(char block, int level) {
    myBoard->blocksVec.erase(myBoard->blocksVec.end()-1);   //might not need to pop back...depends if blocks are automatically added onto blocksVec or not
    if (block == 'I') {
        myBoard->blocksVec.emplace_back(new IBlock(level)); // Add level
    } else if (block == 'J') {
        myBoard->blocksVec.emplace_back(new JBlock(level));
    } else if (block == 'L') {
        myBoard->blocksVec.emplace_back(new LBlock(level));
    } else if (block == 'O') {
        myBoard->blocksVec.emplace_back(new OBlock(level));
    } else if (block == 'S') {
        myBoard->blocksVec.emplace_back(new SBlock(level));
    } else if (block == 'T') {
        myBoard->blocksVec.emplace_back(new TBlock(level));
    } else if (block == 'Z') {
        myBoard->blocksVec.emplace_back(new ZBlock(level));
    } else {
        cout << block << " is an invalid block. Please choose a valid block!" << endl;
    }

    return myBoard->blocksVec.at((myBoard->blocksVec.size() - 1));
}

void Blind::addBlock(std::shared_ptr<Block> block) {
    myBoard->addBlock(block);
}




