#include <iostream>
#include <memory>
#include <vector>
#include "LBlock.h"
using namespace std;

LBlock::LBlock(int level, bool heavy) : Block{level, heavy} {
    // shared_ptr<Coordinate> first {new Coordinate{4, 0}};
    // shared_ptr<Coordinate> second {new Coordinate{4, 1}};
    // shared_ptr<Coordinate> third {new Coordinate{4, 2}};
    // shared_ptr<Coordinate> forth {new Coordinate{3, 2}};
    allPixels.emplace_back(Coordinate{4, 0});
    allPixels.emplace_back(Coordinate{4, 1});
    allPixels.emplace_back(Coordinate{4, 2});
    allPixels.emplace_back(Coordinate{3, 2});
    c = 'L';
}

void LBlock::clockwiseSpin() {
    if (dir == Direction::up) {
        allPixels[0].x += -2;
        allPixels[0].y += 0;
        allPixels[1].x += -1;
        allPixels[1].y += -1;
        allPixels[2].x += 0;
        allPixels[2].y += -2;
        allPixels[3].x += 1;
        allPixels[3].y += -1;
        // dir = Direction::right;
    } else if (dir == Direction::right) {
        allPixels[0].x += 1;
        allPixels[0].y += 2;
        allPixels[1].x += 0; 
        allPixels[1].y += 1;
        allPixels[2].x += -1;
        allPixels[2].y += 0;
        allPixels[3].x += 0;
        allPixels[3].y += -1;
        // dir = Direction::down;
    } else if (dir == Direction::down) {
        allPixels[0].x += 1;
        allPixels[0].y += -1;
        allPixels[1].x += 0;
        allPixels[1].y += 0;
        allPixels[2].x += -1;
        allPixels[2].y += 1;
        allPixels[3].x += -2;
        allPixels[3].y += 0;
        // dir = Direction::left;
    } else if (dir == Direction::left) {
        allPixels[0].x += 0;
        allPixels[0].y += -1;
        allPixels[1].x += 1;
        allPixels[1].y += 0;
        allPixels[2].x += 2;
        allPixels[2].y += 1;
        allPixels[3].x += 1;
        allPixels[3].y += 2;
        // dir = Direction::up;
    }
    updateDirection(true);
}

void LBlock::spin(bool isClockwise) {
    if (isClockwise) {
        clockwiseSpin();
    } else {
        for (int i = 0; i < 3; ++i) {
            clockwiseSpin();
        }
    }
}
