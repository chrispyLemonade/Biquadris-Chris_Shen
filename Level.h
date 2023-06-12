#ifndef LEVEL_H
#define LEVEL_H
#include <memory>
#include <string>
#include <vector>
#include <utility>
#include "myBlock.h"

class Level {
  protected:
    bool isRandom;
    std::vector<char> blockSequence;
    int index = 0;
    std::shared_ptr<Block> generateSequencedBlock();
    int myLevel;

public:
    ~Level();
    Level(); 
    // Level(bool israndom); Do we need this? Probably not
    virtual int getLevel() = 0;
    virtual std::shared_ptr<Block> generateBlock() = 0;
    void changeRandom(bool rand, std::string file = "");
};

#endif
