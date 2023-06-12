#include <iostream>
#include <memory>
#include <vector>
#include "OBlock.h"
using namespace std;

OBlock::OBlock(int level, bool heavy) : Block{level, heavy} {
    // shared_ptr<Coordinate> first {new Coordinate{3, 0}};
    // shared_ptr<Coordinate> second {new Coordinate{3, 1}};
    // shared_ptr<Coordinate> third {new Coordinate{4, 0}};
    // shared_ptr<Coordinate> forth {new Coordinate{4, 1}};
    allPixels.emplace_back(Coordinate{3, 0});
    allPixels.emplace_back(Coordinate{3, 1});
    allPixels.emplace_back(Coordinate{4, 0});
    allPixels.emplace_back(Coordinate{4, 1});
    c = 'O';
}

void OBlock::spin(bool isClockwise) {updateDirection(isClockwise);}
