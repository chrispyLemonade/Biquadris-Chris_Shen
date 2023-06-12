#ifndef _S_BLOCK_
#define _S_BLOCK_

#include <iostream>
#include <memory>
#include <vector>
#include "myBlock.h"
#include "direction.h"

class SBlock : public Block {
public:
    SBlock(int level, bool heavy = false);
    void spin(bool isClockwise) override;
};

#endif
