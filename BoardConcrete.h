#ifndef BOARD_CONCRETE_H
#define BOARD_CONCRETE_H
#include <memory>
#include <string>
#include <vector>
#include <utility>
#include "BoardAbstract.h"

class BoardConcrete : public BoardAbstract {
  public:
    char charAt(int row, int col) override;
};


#endif
