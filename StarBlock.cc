#include <iostream>
#include <memory>
#include <vector>
#include "StarBlock.h"
using namespace std;

StarBlock::StarBlock(int level, bool heavy) : Block{level, heavy} {
    // shared_ptr<Coordinate> first {new Coordinate{0, 0}};
    // shared_ptr<Coordinate> second {new Coordinate{0, 0}};
    // shared_ptr<Coordinate> third {new Coordinate{0, 0}};
    // shared_ptr<Coordinate> forth {new Coordinate{0, 0}};

    allPixels.emplace_back(Coordinate{-10000, -10000});
    allPixels.emplace_back(Coordinate{-10000, -10000});
    allPixels.emplace_back(Coordinate{-10000, -10000});
    allPixels.emplace_back(Coordinate{3, 5});
    c = '*';
}

void StarBlock::spin(bool isClockwise) {updateDirection(isClockwise);}
