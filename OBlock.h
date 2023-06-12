#ifndef _O_BLOCK_
#define _O_BLOCK_

#include <iostream>
#include <memory>
#include <vector>
#include "myBlock.h"
#include "direction.h"

class OBlock : public Block {
public:
    OBlock(int level, bool heavy = false);
    void spin(bool isClockwise) override;
};

#endif
