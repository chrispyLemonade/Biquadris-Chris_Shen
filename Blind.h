#ifndef BLIND_H
#define BLIND_H
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "Decorator.h"

class Blind : public Decorator {
 public:
    virtual ~Blind();

    Blind(std::shared_ptr<BoardAbstract> myBoard);
    virtual char charAt(int row, int col) override;
    char actualCharAt(int row, int col) override;
    void addBlock(std::shared_ptr<Block> block) override;
    std::shared_ptr<Block> force(char block, int level) override;
};

#endif
