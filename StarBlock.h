#ifndef _STAR_BLOCK_
#define _STAR_BLOCK_

#include <iostream>
#include <memory>
#include <vector>
#include "myBlock.h"
#include "direction.h"

class StarBlock : public Block {
public:
    StarBlock(int level, bool heavy = false);
    void spin(bool isClockwise) override;
};

#endif
