//
// Created by Dillon Liu on 2022-11-26.
//

#include "Level1.h"
#include "Level0.h"
#include "BoardConcrete.h"
#include "SingleTetrisGame.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"
#include "Blind.h"
#include <iostream>
#include "IBlock.h"
#include "JBlock.h"
#include "LBlock.h"
#include "OBlock.h"
#include "SBlock.h"
#include "ZBlock.h"
#include "TBlock.h"
#include "StarBlock.h"

SingleTetrisGame::SingleTetrisGame(std::string level0File, unsigned seed, int startLevel):
level0File{level0File}, seed{seed}, score{0}, board{new BoardConcrete}, end{false}, prevLevel{-1}, blinded{false} {
    switch(startLevel) {
        case 0:
            level = std::shared_ptr<Level>{new Level0{level0File}};
            break;
        case 1:
            level = std::shared_ptr<Level>{new Level1{}};
            break;
        case 2:
            level = std::shared_ptr<Level>{new Level2{}};
            break;
        case 3:
            level = std::shared_ptr<Level>{new Level3{seed}};
            break;
        case 4:
            level = std::shared_ptr<Level>{new Level4{seed}};
            break;
    }
    block = level->generateBlock();
    nextBlock = level->generateBlock();
    board->addBlock(block);

}

int SingleTetrisGame::getLevel() {
    return level->getLevel();
}

int SingleTetrisGame::getScore() {
    return score;
}

char SingleTetrisGame::getState(int row, int col) {
    return board->charAt(row, col);
}

std::shared_ptr<Block> createBlock(char c);

bool SingleTetrisGame::moveBlock(Direction dir, bool heavyMove) {
    promptSpecialEffect = false;
    std::shared_ptr<Block> testBlock = createBlock(block->getC());
    *testBlock = *block;
    testBlock->move(dir);

    if (validPos(testBlock)) {
        block->move(dir);

        // level heavy
        if (block->getHeavy() && !heavyMove) {
            return moveBlock(down, true);
        }

        // special effect heavy
        if (block->getSpecialEffectHeavy() && (dir == left || dir == right) && !heavyMove) {
            if (moveBlock(down, true)) return true;
            if (moveBlock(down, true)) return true;
        }
    }

    return checkTouchGround();
}

void SingleTetrisGame::spinBlock(bool isClockwise) {
    std::shared_ptr<Block> testBlock = createBlock(block->getC());
    *testBlock = *block;
    testBlock->spin(isClockwise);
    if (validPos(testBlock)) {
        block->spin(isClockwise);
        // level heavy
        if (block->getHeavy()) {
            moveBlock(down, true);
        }
    }
}

void SingleTetrisGame::changeLevel(bool isUp) {
    if (level->getLevel() == 0 && !isUp) {
        std::cerr << "Already Level 0, cannot level down!" << std::endl;
    }
    else if (level->getLevel() == 4 && isUp) {
        std::cerr << "Already Level 4, cannot level Up!" << std::endl;
    }
    else if (isUp) {
        switch(level->getLevel()) {
            case 0:
                level = std::shared_ptr<Level1>{new Level1};
                break;
            case 1:
                level = std::shared_ptr<Level2>{new Level2};
                break;
            case 2:
                level = std::shared_ptr<Level3>{new Level3{seed}};
                break;
            case 3:
                level = std::shared_ptr<Level4>{new Level4{seed}};
                break;
        }
    }
    else {
        switch (level->getLevel()) {
            case 1:
                level = std::shared_ptr<Level0>(new Level0{level0File});
                break;
            case 2:
                level = std::shared_ptr<Level1>(new Level1);
                break;
            case 3:
                level = std::shared_ptr<Level2>(new Level2);
                break;
            case 4:
                level = std::shared_ptr<Level3>{new Level3{seed}};
                break;
        }
    }
}

void SingleTetrisGame::replaceBlock(char block) {
    promptSpecialEffect = false;
    this->block = board->force(block, getLevel());
}

bool SingleTetrisGame::checkTouchGround() {
    bool touch = false;
    // get the lowest point
    for (auto pos: block->getAllPixels()) {
        bool ownBlockUnder = false;
        for (auto blockPos: block->getAllPixels()) {
            if (pos.x+1 == blockPos.x && pos.y == blockPos.y) {
                ownBlockUnder = true;
                break;
            }
        }
        if (pos.x == 17) {
            touch = true;
            break;
        }
        if (!ownBlockUnder && board->actualCharAt(pos.x+1, pos.y) != ' ') {
            touch = true;
            break;
        }
    }

    if (touch) {
        ++blocksDropedSinceLastClear;
        clearFilledRows();
        if (blocksDropedSinceLastClear == 5 && level->getLevel() == 4) {
            block = std::shared_ptr<Block>{new StarBlock{4}};
            board->addBlock(block);
            drop();
            blocksDropedSinceLastClear = 0;
            return true;
        }
        block = nextBlock;
        nextBlock = level->generateBlock();
        checkEndGame();
        board->addBlock(block);
        endAfterAddNewBlock();
        if (blinded) {
            board = unDecoratedBoard;
            blinded = false;
        }
    }
    return touch;
}

bool SingleTetrisGame::endAfterAddNewBlock() {
    bool touch = false;
    // get the lowest point
    for (auto pos: block->getAllPixels()) {
        bool ownBlockUnder = false;
        for (auto blockPos: block->getAllPixels()) {
            if (pos.x+1 == blockPos.x && pos.y == blockPos.y) {
                ownBlockUnder = true;
                break;
            }
        }
        if (pos.x == 17) {
            touch = true;
            break;
        }
        if (!ownBlockUnder && board->actualCharAt(pos.x+1, pos.y) != ' ') {
            touch = true;
            break;
        }
    }
    end = touch;
    return end;
}

bool SingleTetrisGame::checkEndGame(bool afterNewBlock) {
    // some block is over the height limit
    for (int row = 0; row <= 2; ++row) {
        for (int col = 0; col <= 17; ++col) {
            if (board->actualCharAt(row, col) != ' ') {
                end = true;
                return true;
            }
        }
    }
    if (afterNewBlock) return false;

    // the new block is overlapping some block
    for (auto pos: block->getAllPixels()) {
        if (board->actualCharAt(pos.x, pos.y) != ' ') {
            end = true;
            return true;
        }
    }
    return false;
}

bool SingleTetrisGame::validPos(std::shared_ptr<Block> block) {
    bool valid = true;
    for (auto pos: block->getAllPixels()) {
        // out of bounds
        if ((pos.x < 0 || pos.y < 0 || pos.x > 17 || pos.y > 10) && pos.x > -1000 && pos.y > -1000) return false;
        if (board->actualCharAt(pos.x, pos.y) != ' ') {
            valid = false;
            for (auto blockPos: this->block->getAllPixels()) {
                if (pos.x == blockPos.x && pos.y == blockPos.y) {
                    valid = true;
                    break;
                }
            }
            if (!valid) return false;
        }
    }
    return valid;
}

std::shared_ptr<Block> SingleTetrisGame::getNextBlock() {
    return nextBlock;
}

Direction SingleTetrisGame::reverseDir(Direction dir) {
    switch (dir) {
        case left:
            return right;
        case right:
            return left;
        case up:
            return down;
        case down:
            return up;
    }
    return up;
}

void SingleTetrisGame::clearFilledRows() {
    int counter = 0;
    for (int row = 0; row < 18; ++row) {
        bool clear = true;
        for (int col = 0; col <= 10; ++col) {
            if (board->actualCharAt(row, col) == ' ') {
                clear = false;
                break;
            }
        }
        if (clear) {
            score += board->removeRow(row);
            ++counter;
            blocksDropedSinceLastClear = 0;
        }
    }

    if (counter > 0) {
        score += (counter + level->getLevel()) * (counter + level->getLevel());
    }
    if (counter >= 2) promptSpecialEffect = true;
    else promptSpecialEffect = false;
}

bool SingleTetrisGame::ended() {
    return end;
}

void SingleTetrisGame::noRandom(std::string file) {
    if (level->getLevel() >= 3) {
        level->changeRandom(false, file);
        std::cout << file;
    }
}

void SingleTetrisGame::random() {
    if (level->getLevel() >= 3) level->changeRandom(true);
}

void SingleTetrisGame::drop() {
    while (!moveBlock(down));
}

void SingleTetrisGame::heavy() {
    promptSpecialEffect = false;
    block->setSpecialEffectHeavy(true);
}

void SingleTetrisGame::blind() {
    promptSpecialEffect = false;
    unDecoratedBoard = board;
    board = std::shared_ptr<BoardAbstract> {new Blind{board}};
    blinded = true;
}

bool SingleTetrisGame::shouldPromptSpecialEffect() {
    return promptSpecialEffect;
}

std::shared_ptr<Block> createBlock(char c) {
    using namespace std;
    if (c == 'I') {
        shared_ptr<IBlock> b {new IBlock(0)};
        return b;
    } else if (c == 'J') {
        shared_ptr<JBlock> b {new JBlock(0)};
        return b;
    } else if (c == 'L') {
        shared_ptr<LBlock> b {new LBlock(0)};
        return b;
    } else if (c == 'O') {
        shared_ptr<OBlock> b {new OBlock(0)};
        return b;
    } else if (c == 'S') {
        shared_ptr<SBlock> b {new SBlock(0)};
        return b;
    } else if (c == 'Z') {
        shared_ptr<ZBlock> b {new ZBlock(0)};
        return b;
    } else if (c == 'T') {
        shared_ptr<TBlock> b {new TBlock(0)};
        return b;
    } else if (c == '*') {
        shared_ptr<StarBlock> b{new StarBlock(0)};
        return b;
    }
    return nullptr;
}


