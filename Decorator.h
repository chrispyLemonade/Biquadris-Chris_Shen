#ifndef DECORATOR_H
#define DECORATOR_H
#include <memory>
#include <string>
#include <vector>
#include <utility>
#include "BoardAbstract.h"

class Decorator : public BoardAbstract {
 public:
    std::shared_ptr<BoardAbstract> myBoard;
    Decorator(std::shared_ptr<BoardAbstract> component );
    virtual ~Decorator();

    virtual char charAt(int row, int col) override;
};

#endif
