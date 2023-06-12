#ifndef LEVEL0_H
#define LEVEL0_H
#include <memory>
#include <string>
#include <vector>
#include <utility>
#include "Level.h"

class Level0 : public Level {
    std::string fileName;

  public: 
    Level0(std::string file);
    virtual int getLevel() override;
    virtual std::shared_ptr<Block> generateBlock() override;


};


#endif
