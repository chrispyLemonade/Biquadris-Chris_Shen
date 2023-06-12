#ifndef _J_BLOCK_
#define _J_BLOCK_

#include <iostream>
#include <memory>
#include <vector>
#include "myBlock.h"
#include "direction.h"

class JBlock : public Block {
    void clockwiseSpin();
public:
    JBlock(int level, bool heavy = false);
    void spin(bool isClockwise) override;
};

#endif
