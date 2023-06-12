//
// Created by Dillon Liu on 2022-11-26.
//

#ifndef BIQUADRIS_GAME_H
#define BIQUADRIS_GAME_H

#include <memory>
#include "direction.h"
#include "Subject.h"
#include "BoardAbstract.h"
#include "Level.h"
#include "SingleTetrisGame.h"
#include "TextDisplay.h"
#include "GraphicalDisplay.h"

class Game: public Subject {
    bool textOnly;
    unsigned seed;
    std::string scriptFile1, scriptFile2;
    int startLevel;
    std::shared_ptr<SingleTetrisGame> tGame1, tGame2, curGame;
    std::unique_ptr<TextDisplay> td;
    std::unique_ptr<GraphicalDisplay> gd;
    bool end;
    bool didPromptSpecialEffect;
    bool getSpecialEffectInput = false;
    int &highScore;

public:
    Game(bool textOnly, unsigned seed, std::string scriptFile1, std::string scriptFile2, int &highScore, int startLevel);
    int getLevel(int board);
    int getScore(int board);
    int getCurBoard();
    std::shared_ptr<Block> getNextBlock();
    char getState(int board, int row, int col);
    void moveBlock(Direction dir);
    void spinBlock(bool isClockwise);
    void changeLevel(bool isUp);
    void replaceBlock(char block);
    void noRandom(std::string file);
    void random();
    void drop();
    void heavy();
    void blind();
    bool getEnd();
    bool getSingleGameEnd(int board);
    bool &shouldGetSpecialEffectInput();
};


#endif //BIQUADRIS_GAME_H
