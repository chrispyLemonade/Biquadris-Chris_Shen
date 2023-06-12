#ifndef _I_BLOCK_
#define _I_BLOCK_

#include <iostream>
#include <memory>
#include <vector>
#include "myBlock.h"
#include "direction.h"

class IBlock : public Block {
public:
    IBlock(int level, bool heavy = false);
    void spin(bool isClockwise) override;

};

#endif
