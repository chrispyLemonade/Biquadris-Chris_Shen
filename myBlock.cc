#include "myBlock.h"
#include <utility>
using namespace std;

void Block::updateDirection(bool isClockwise) {
    int i = 0;
    int numOfClockwiseSpin;
    if (isClockwise) {
        numOfClockwiseSpin = 1;
    } else {
        numOfClockwiseSpin = 3;
    }
    while (i < numOfClockwiseSpin) {
        if (dir == Direction::up) {
            dir = Direction::right;
        } else if (dir == Direction::right) {
            dir = Direction::down;
        } else if (dir == Direction::down) {
            dir = Direction::left;
        } else if (dir == Direction::left) {
            dir = Direction::up;
        }
        ++i;
    }
}

Block::Block(int level, bool heavy) : level{level}, heavy{heavy} {}

int Block::getLevel() {
    return level;
}

bool Block::getHeavy() {
    return heavy;
}

vector<Coordinate> &Block::getAllPixels() {
    return allPixels;
}

char Block::getC() const {
    return c;
}

void Block::move(Direction d) {
    const int numOfPixel = 4;
    for (int i = 0; i < numOfPixel; ++i) {
        if (d == Direction::left) {
            --allPixels[i].y;
        } else if (d == Direction::right) {
            ++allPixels[i].y;
        } else if (d == Direction::down) {
            ++allPixels[i].x;
        }
        else if (d == Direction::up) {
            --allPixels[i].x;
        }
    }
}



Block &Block::operator=(const Block &other) {
    if (this == &other) return *this;
    allPixels = other.allPixels;
    dir = other.dir;
    return *this;
}

void Block::setSpecialEffectHeavy(bool boo) {
    specialEffectHeavy = boo;
}

bool Block::getSpecialEffectHeavy() {
    return specialEffectHeavy;
}
