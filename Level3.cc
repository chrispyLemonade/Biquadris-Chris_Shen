#include <vector>
#include "Level3.h"
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

Level3::Level3(unsigned seed): seed{seed} {
    isRandom = true;
    myLevel = 3;
}

int Level3::getLevel() {
    return 3;
}

shared_ptr<Block> Level3::generateRandomBlock() {
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
    if (1 == v[0] || 2 == v[0]) {  //NEEDS DIFF CONSTRUCTOR TO MAKE ALL BLOCKS "HEAVY"
        shared_ptr<Block> b(new SBlock(myLevel, true));
        return b;
    } else if (3 == v[0] || 4== v[0]) {
        shared_ptr<Block> b {new ZBlock(myLevel, true)};
        
        return b;
    } else if (5 == v[0]) {
        shared_ptr<Block> b {new IBlock(myLevel, true)};
        
        return b;
    } else if (6 == v[0]) {
        shared_ptr<Block> b {new JBlock(myLevel, true)};
        
        return b;
    } else if (7 == v[0]) {
        shared_ptr<Block> b {new LBlock(myLevel, true)};
        
        return b;
    } else if (8 == v[0]) {
        shared_ptr<Block> b {new OBlock(myLevel, true)};
        
        return b;
    } else {
        shared_ptr<Block> b {new TBlock(myLevel, true)};
        
        return b;
    }
}

std::shared_ptr<Block> Level3::generateBlock() {
    if (isRandom) {
        return generateRandomBlock();
    }
    else {
        return generateSequencedBlock();
    }
}

