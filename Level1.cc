#include <string>
#include <vector>
#include <utility>
#include "Level1.h"
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

Level1::Level1() {
    myLevel = 1;
    isRandom = true;
}

int Level1::getLevel() {
    return 1;
}

shared_ptr<Block> Level1::generateBlock() {
    vector<int> v;

    for(int i = 1; i <= 12; ++i) {
        v.emplace_back(i);
    }

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine eng{seed};

    std::shuffle( v.begin(), v.end(), eng );

    // Creates a vector int {1,..,12} where 1 is mapped to S-MyBlocks, 2 is mapped to Z-MyBlocks,
    // 3-4 are mapped to I-MyBlocks, 5-6 are mapped to J-MyBlocks, 7-8 are mapped to L-MyBlocks,
    // 9-10 are mapped to O-MyBlocks, 11-12 are mapped to T-MyBlocks
    if (1 == v[0]) {
        shared_ptr<SBlock> b {new SBlock(myLevel)};
        return b;
    } else if (2 == v[0]) {
        shared_ptr<ZBlock> b {new ZBlock(myLevel)};
        return b;
    } else if (3 == v[0] || v[0] == 4) {
        shared_ptr<IBlock> b {new IBlock(myLevel)};
        return b;
    } else if (5 == v[0] || v[0] == 6) {
        shared_ptr<JBlock> b {new JBlock(myLevel)};
        return b;
    } else if (7 == v[0] || v[0] == 8) {
        shared_ptr<LBlock> b {new LBlock(myLevel)};
        return b;
    } else if (9 == v[0] || v[0] == 10) {
        shared_ptr<OBlock> b {new OBlock(myLevel)};
        return b;
    } else {
        shared_ptr<TBlock> b {new TBlock(myLevel)};
        return b;
    }
}

