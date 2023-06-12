#include <iostream>
#include <memory>
#include <vector>
#include "SBlock.h"
using namespace std;

SBlock::SBlock(int level, bool heavy) : Block{level, heavy} {
    // shared_ptr<Coordinate> first {new Coordinate{4, 0}};
    // shared_ptr<Coordinate> second {new Coordinate{4, 1}};
    // shared_ptr<Coordinate> third {new Coordinate{3, 1}};
    // shared_ptr<Coordinate> forth {new Coordinate{3, 2}};
    allPixels.emplace_back(Coordinate{4, 0});
    allPixels.emplace_back(Coordinate{4, 1});
    allPixels.emplace_back(Coordinate{3, 1});
    allPixels.emplace_back(Coordinate{3, 2});
    c = 'S';
}

void SBlock::spin(bool isClockwise) {
    // get the left bottom coor
    int leftCoor = 100;
    int bottomCoor = -100;
    for (int i = 0; i < 4; ++i) {
        if (allPixels[i].y < leftCoor) {
            leftCoor = allPixels[i].y;
        }

        if (allPixels[i].x > bottomCoor) {
            bottomCoor = allPixels[i].x;
        }
    }

    if (dir == Direction::up || dir == Direction::down) {
        allPixels[0].x = bottomCoor - 2;
        allPixels[0].y = leftCoor;
        allPixels[1].x = bottomCoor - 1;
        allPixels[1].y = leftCoor;
        allPixels[2].x = bottomCoor - 1;
        allPixels[2].y = leftCoor + 1;
        allPixels[3].x = bottomCoor;
        allPixels[3].y = leftCoor + 1;
    } else {
        allPixels[0].x = bottomCoor;
        allPixels[0].y = leftCoor;
        allPixels[1].x = bottomCoor;
        allPixels[1].y = leftCoor + 1;
        allPixels[2].x = bottomCoor - 1;
        allPixels[2].y = leftCoor + 1;
        allPixels[3].x = bottomCoor - 1;
        allPixels[3].y = leftCoor + 2;
    }
    updateDirection(isClockwise);
}
