#ifndef _Z_BLOCK_
#define _Z_BLOCK_

#include <iostream>
#include <memory>
#include <vector>
#include "myBlock.h"
#include "direction.h"

class ZBlock : public Block {
public:
    ZBlock(int level, bool heavy = false);
    void spin(bool isClockwise) override;
};

#endif
