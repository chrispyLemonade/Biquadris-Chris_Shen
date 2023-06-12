#ifndef _L_BLOCK_
#define _L_BLOCK_

#include <iostream>
#include <memory>
#include <vector>
#include "myBlock.h"
#include "direction.h"

class LBlock : public Block {
    void clockwiseSpin();
public:
    LBlock(int level, bool heavy = false);
    void spin(bool isClockwise) override;
};

#endif
