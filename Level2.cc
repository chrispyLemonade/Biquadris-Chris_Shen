#include <string>
#include <vector>
#include <utility>
#include "Level2.h"
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

Level2::Level2() {
    myLevel = 2;
    isRandom = true;
}

int Level2::getLevel() {
    return 2;
}

shared_ptr<Block> Level2::generateBlock() {
    vector<int> v;

    for(int i = 1; i <= 7; ++i) {
        v.emplace_back(i);
    }

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine eng{seed};

    std::shuffle( v.begin(), v.end(), eng );

    // Creates a vector int {1,..,7} where 1 is mapped to S-MyBlocks, 2 is mapped to Z-MyBlocks,
    // 3 is mapped to I-MyBlocks, 4 is mapped to J-MyBlocks, 5 is mapped to L-MyBlocks,
    // 6 is mapped to O-MyBlocks, 7 is mapped to T-MyBlocks
    if (1 == v[0]) {
        shared_ptr<SBlock> b {new SBlock(myLevel)};
        return b;
    } else if (2 == v[0]) {
        shared_ptr<ZBlock> b {new ZBlock(myLevel)};
        return b;
    } else if (3 == v[0]) {
        shared_ptr<IBlock> b {new IBlock(myLevel)};
        return b;
    } else if (4 == v[0]) {
        shared_ptr<JBlock> b {new JBlock(myLevel)};
        return b;
    } else if (5 == v[0]) {
        shared_ptr<LBlock> b {new LBlock(myLevel)};
        return b;
    } else if (6 == v[0]) {
        shared_ptr<OBlock> b {new OBlock(myLevel)};
        return b;
    } else {
        shared_ptr<TBlock> b {new TBlock(myLevel)};
        return b;
    }
}

