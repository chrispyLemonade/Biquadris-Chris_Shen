#ifndef _T_BLOCK_
#define _T_BLOCK_

#include <iostream>
#include <memory>
#include <vector>
#include "myBlock.h"
#include "direction.h"

class TBlock : public Block {
    void clockwiseSpin();
public:
    TBlock(int level, bool heavy = false);
    void spin(bool isClockwise) override;
};

#endif
