#ifndef LEVEL1_H
#define LEVEL1_H
#include <algorithm>
#include <random>
#include <memory>
#include <string>
#include <vector>
#include <utility>
#include "Level.h"

class Level1 : public Level {
  public: 
    Level1();

    virtual int getLevel() override;
    virtual std::shared_ptr<Block> generateBlock() override;
};


#endif
