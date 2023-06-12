#ifndef _BLOCK_
#define _BLOCK_

#include <iostream>
#include <memory>
#include <vector>
#include "direction.h"

struct Coordinate {
    int x, y;
};

class Block {
protected:
    std::vector<Coordinate> allPixels;
    Direction dir = Direction::up;
    char c;
    int level;
    bool heavy;
    bool specialEffectHeavy;
    void updateDirection(bool isClockwise);

public:
    // you are not able to determin if it could move or spin
    // this if flow should be in class Game
    explicit Block(int level, bool heavy = false);

    int getLevel();
    bool getHeavy();
    void setSpecialEffectHeavy(bool boo);
    bool getSpecialEffectHeavy();
    virtual char getC() const;
    virtual std::vector<Coordinate> &getAllPixels();
    virtual void move(Direction d);
    virtual void spin(bool isClockwise) = 0;
    virtual ~Block() = default;
    Block &operator=(const Block &other);
};

#endif
