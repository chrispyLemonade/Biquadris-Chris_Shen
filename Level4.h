#ifndef LEVEL4_H
#define LEVEL4_H

#include <string>
#include <vector>
#include <utility>
#include "Level.h"
#include <algorithm>
#include <random>
#include <memory>


class Level4 : public Level {
    int numBlock;
    unsigned seed;
    std::shared_ptr<Block> generateRandomBlock();
  public: 
    Level4(unsigned seed);
    
    virtual int getLevel() override;
    virtual std::shared_ptr<Block> generateBlock() override;
    // std::shared_ptr<MyBlocks> generateStar();
};

#endif
