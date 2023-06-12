#include "Level.h"
#include <fstream>
#include "IBlock.h"
#include "JBlock.h"
#include "LBlock.h"
#include "OBlock.h"
#include "SBlock.h"
#include "ZBlock.h"
#include "TBlock.h"
using namespace std;


Level::~Level() {}
Level::Level() {}

void Level::changeRandom(bool rand, std::string file) {
    isRandom = rand;
    if (!rand) {
        std::ifstream ifs {file};
        std::string newBlock;
        blockSequence.clear();
        while (ifs >> newBlock) {
            blockSequence.emplace_back(newBlock[0]);
        }
    }
}

std::shared_ptr<Block> Level::generateSequencedBlock() {
    if (index == static_cast<int>(blockSequence.size())) index = 0;
    for (int i = index; i < static_cast<int>(blockSequence.size()); i++) {
        if (blockSequence.at(i) == 'I') {
            shared_ptr<IBlock> b {new IBlock(myLevel)};
            index++;
            return b;
        } else if (blockSequence.at(i) == 'J') {
            shared_ptr<JBlock> b {new JBlock(myLevel)};
            index++;
            return b;
        } else if (blockSequence.at(i) == 'L') {
            shared_ptr<LBlock> b {new LBlock(myLevel)};
            index++;
            return b;
        } else if (blockSequence.at(i) == 'O') {
            shared_ptr<OBlock> b {new OBlock(myLevel)};
            index++;
            return b;
        } else if (blockSequence.at(i) == 'S') {
            shared_ptr<SBlock> b {new SBlock(myLevel)};
            index++;
            return b;
        } else if (blockSequence.at(i) == 'Z') {
            shared_ptr<ZBlock> b {new ZBlock(myLevel)};
            index++;
            return b;
        } else if (blockSequence.at(i) == 'T') {
            shared_ptr<TBlock> b {new TBlock(myLevel)};
            index++;
            return b;
        }
    }

    return shared_ptr<TBlock> {new TBlock(myLevel)};
}


