#include <string>
#include <vector>
#include <utility>
#include "BoardConcrete.h"
using namespace std;

char BoardConcrete::charAt(int row, int col) {
    for (auto block : blocksVec) {
        for (auto coord : block->getAllPixels()) {
            if ((coord.x == row) && (coord.y == col)) {
                return block->getC();
            } else {
                continue;
            }
        }
    }
    return ' ';
}
