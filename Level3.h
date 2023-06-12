#ifndef LEVEL3_H
#define LEVEL3_H

#include <string>
#include <vector>
#include <utility>
#include "Level.h"
#include <algorithm>
#include <random>
#include <memory>

class Level3 : public Level {
    unsigned seed;
  public: 
    Level3(unsigned seed);

    virtual int getLevel() override;
    virtual std::shared_ptr<Block> generateBlock() override;
    std::shared_ptr<Block> generateRandomBlock();
};

#endif
