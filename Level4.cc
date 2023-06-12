#include <string>
#include <vector>
#include <utility>
#include "Level4.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <random>
#include <chrono>
#include "IBlock.h"
#include "JBlock.h"
#include "LBlock.h"
#include "OBlock.h"
#include "SBlock.h"
#include "ZBlock.h"
#include "TBlock.h"
using namespace std;

#include<cstdlib>

Level4::Level4(unsigned seed) : numBlock{0}, seed{seed} {
    isRandom = true;
    myLevel = 4;
}

int Level4::getLevel() {
    return 4;
}

shared_ptr<Block> Level4::generateBlock() {
    if (isRandom) return generateRandomBlock();
    else {
        return generateSequencedBlock();
    }

}

std::shared_ptr<Block> Level4::generateRandomBlock() {
    vector<int> v;

    for(int i = 1; i <= 9; ++i) {
        v.emplace_back(i);
    }

    unsigned mySeed;
    if (seed == 0) {
        mySeed = std::chrono::system_clock::now().time_since_epoch().count();
    } else {
        mySeed = seed;
    }

    std::default_random_engine eng{mySeed};

    std::shuffle( v.begin(), v.end(), eng );

    // Creates a vector int {1,..,9} where 1-2 is mapped to S-MyBlocks, 3-4 is mapped to Z-MyBlocks,
    // 5 is mapped to I-MyBlocks, 6 is mapped to J-MyBlocks, 7 is mapped to L-MyBlocks,
    // 8 is mapped to O-MyBlocks, 9 is mapped to T-MyBlocks
    if (1 == v[0] || 2 == v[0]) {
        shared_ptr<Block> b(new SBlock(myLevel, true));
        numBlock++;
        return b;
    } else if (3 == v[0] || 4== v[0]) {
        shared_ptr<Block> b {new ZBlock(myLevel, true)};
        numBlock++;
        return b;
    } else if (5 == v[0]) {
        shared_ptr<Block> b {new IBlock(myLevel, true)};
        numBlock++;
        return b;
    } else if (6 == v[0]) {
        shared_ptr<Block> b {new JBlock(myLevel, true)};
        numBlock++;
        return b;
    } else if (7 == v[0]) {
        shared_ptr<Block> b {new LBlock(myLevel, true)};
        numBlock++;
        return b;
    } else if (8 == v[0]) {
        shared_ptr<Block> b {new OBlock(myLevel, true)};
        numBlock++;
        return b;
    } else {
        shared_ptr<Block> b {new TBlock(myLevel, true)};
        numBlock++;
        return b;
    }
}

