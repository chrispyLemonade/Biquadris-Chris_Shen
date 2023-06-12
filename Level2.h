#ifndef LEVEL2_H
#define LEVEL2_H

#include <string>
#include <vector>
#include <utility>
#include "Level.h"
#include <algorithm>
#include <random>
#include <memory>

class Level2 : public Level {
  public: 
    Level2();

    virtual int getLevel() override;
    virtual std::shared_ptr<Block> generateBlock() override;
};


#endif
