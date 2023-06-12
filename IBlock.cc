#include <iostream>
#include <memory>
#include <vector>
#include "IBlock.h"
using namespace std;

//TODO: change to this format in all block classes
IBlock::IBlock(int level, bool heavy) : Block{level, heavy} {
    //TODO: delete
/*    shared_ptr<Coordinate> first {new Coordinate{3, 0}};
    shared_ptr<Coordinate> second {new Coordinate{3, 1}};
    shared_ptr<Coordinate> third {new Coordinate{3, 2}};
    shared_ptr<Coordinate> forth {new Coordinate{3, 3}};*/
    allPixels.emplace_back(Coordinate{3, 0});
    allPixels.emplace_back(Coordinate{3, 1});
    allPixels.emplace_back(Coordinate{3, 2});
    allPixels.emplace_back(Coordinate{3, 3});
    c = 'I';
}

void IBlock::spin(bool isClockwise) {
    int xPiviot = allPixels[0].x;
    int yPiviot = allPixels[0].y;
    // cout << "xPiviot: " << xPiviot << endl;
    // cout << "yPiviot: " << yPiviot << endl;
    if (dir == Direction::up || dir == Direction::down) {
        allPixels[1].x = xPiviot - 1;
        allPixels[2].x = xPiviot - 2;
        allPixels[3].x = xPiviot - 3;
        allPixels[1].y = yPiviot;
        allPixels[2].y = yPiviot;
        allPixels[3].y = yPiviot;
        // if (dir == Direction::up) {
        //     if (isClockwise) {
        //         dir = Direction::right;
        //     } else {
        //         dir == Direction::left;
        //     }
        // } else if (dir == Direction::down) {
        //     if (isClockwise) {
        //         dir == Direction::left;
        //     } else {
        //         dir = Direction::right;
        //     }
        // }
    } else {
        allPixels[1].x = xPiviot;
        allPixels[2].x = xPiviot;
        allPixels[3].x = xPiviot;
        allPixels[1].y = yPiviot + 1;
        allPixels[2].y = yPiviot + 2;
        allPixels[3].y = yPiviot + 3;
        // if (dir == Direction::left) {
        //     if (isClockwise) {
        //         dir = Direction::up;
        //     } else {
        //         dir = Direction::down;
        //     }
        // } else if (dir == Direction::right) {
        //     if (isClockwise) {
        //         dir = Direction::down;
        //     } else {
        //         dir = Direction::up;
        //     }
        // }
    }
    updateDirection(isClockwise);
}
