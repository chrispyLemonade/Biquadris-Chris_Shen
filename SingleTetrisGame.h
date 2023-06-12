//
// Created by Dillon Liu on 2022-11-27.
//

#ifndef BIQUADRIS_SINGLETETRISGAME_H
#define BIQUADRIS_SINGLETETRISGAME_H
#include "Level1.h"
#include "Level0.h"
#include "BoardConcrete.h"

class SingleTetrisGame {
    std::string level0File;
    unsigned seed;
    std::shared_ptr<Level> level;
    int score;
    std::shared_ptr<BoardAbstract> board, unDecoratedBoard;
    std::shared_ptr<Block> block, nextBlock;
    bool checkTouchGround();
    bool endAfterAddNewBlock();
    bool validPos(std::shared_ptr<Block> block);
    Direction reverseDir(Direction dir);
    void clearFilledRows();
    bool end;
    int prevLevel;
    bool blinded;
    bool promptSpecialEffect;
    int blocksDropedSinceLastClear = 0;


public:
    SingleTetrisGame(std::string level0File, unsigned seed, int startLevel);
    int getLevel();
    int getScore();
    std::shared_ptr<Block> getNextBlock();
    char getState(int row, int col);
    bool moveBlock(Direction dir, bool heavyMove = false); // returns true if it lands
    void spinBlock(bool isClockwise);
    void changeLevel(bool isUp);
    void replaceBlock(char block);
    bool ended();
    void noRandom(std::string file);
    void random();
    void drop();
    void heavy();
    void blind();
    bool checkEndGame(bool afterNewBlock=false);
    bool shouldPromptSpecialEffect();

};


#endif //BIQUADRIS_SINGLETETRISGAME_H
