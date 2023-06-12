//
// Created by Dillon Liu on 2022-11-26.
//

#include "Game.h"
#include "GraphicalDisplay.h"


Game::Game(bool textOnly, unsigned seed, std::string scriptFile1, std::string scriptFile2, int &highScore, int startLevel):
textOnly{textOnly}, seed{seed}, scriptFile1{std::move(scriptFile1)}, scriptFile2{std::move(scriptFile2)}, startLevel{startLevel},
td{std::make_unique<TextDisplay>(this)}, gd{!textOnly? std::make_unique<GraphicalDisplay>(this) : nullptr}, end{false}, highScore{highScore}
{
    tGame1 = std::make_shared<SingleTetrisGame> (this->scriptFile1, seed, startLevel);
    tGame2 =std::make_shared<SingleTetrisGame>(this->scriptFile2, seed, startLevel);
    curGame = tGame1;
    notifyObservers();
}

int Game::getLevel(int board) {
    if (board == 1) return tGame1->getLevel();
    else return tGame2->getLevel();
}

int Game::getScore(int board) {
    if (board == 1) return tGame1->getScore();
    else return tGame2->getScore();
}

char Game::getState(int board, int row, int col) {
    if (board == 1) {
        return tGame1->getState(row, col);
    }
    else return tGame2->getState(row, col);
}

void Game::moveBlock(Direction dir) {
    if (curGame->moveBlock(dir)) {
        // update high score
        if (tGame1->getScore() > highScore) highScore = tGame1->getScore();
        if (tGame2->getScore() > highScore) highScore = tGame2->getScore();

        curGame = curGame == tGame1 ? tGame2 : tGame1;
        didPromptSpecialEffect = false;
        if (curGame->ended()) {
            curGame = curGame == tGame1 ? tGame2 : tGame1;
        }
        if (curGame->ended()){ // the game is done
            std::cout << "The Game is Done with final states: " << std::endl;
            if (tGame1->getScore() > tGame2->getScore()) {
                std::cout << "Player 1 wins!";
            }
            else if (tGame1->getScore() < tGame2->getScore()) {
                std::cout << "Player 2 wins!";
            }
            else {
                std::cout << "Tie";
            }
            std::cout << "The updated high score is " << highScore << std::endl;
            end = true;
        }
    }
    notifyObservers();
    if ((curGame == tGame1? tGame2 : tGame1) ->shouldPromptSpecialEffect() && !didPromptSpecialEffect) {
        std::cout << "What special effect would you like to apply to the current player? (blind, force, heavy)" << std::endl;
        didPromptSpecialEffect = true;
        getSpecialEffectInput = true;
    }

}

void Game::spinBlock(bool isClockwise) {
    curGame->spinBlock(isClockwise);
    notifyObservers();
}

void Game::changeLevel(bool isUp) {
    curGame->changeLevel(isUp);
    notifyObservers();
}

void Game::replaceBlock(char block) {
    curGame->replaceBlock(block);
    notifyObservers();
}

int Game::getCurBoard() {
    return curGame == tGame1 ? 1 : 2;
}

std::shared_ptr<Block> Game::getNextBlock() {
    return curGame == tGame1 ? tGame1->getNextBlock() : tGame2->getNextBlock();
}

void Game::noRandom(std::string file) {
    if (curGame == tGame1) tGame1->noRandom(file);
    else tGame2->noRandom(file);
}

void Game::random() {
    if (curGame == tGame1) tGame1->random();
    else tGame2->random();
}

void Game::drop() {
    curGame->drop();
    didPromptSpecialEffect = false;
    // update high score
    if (tGame1->getScore() > highScore) highScore = tGame1->getScore();
    if (tGame2->getScore() > highScore) highScore = tGame2->getScore();
    curGame = curGame == tGame1 ? tGame2 : tGame1;
    if (curGame->ended()) {
        curGame = curGame == tGame1 ? tGame2 : tGame1;
    }
    if (curGame->ended()){ // the game is done
        std::cout << "The Game is Done with final states: " << std::endl;
        std::cout << "The updated high score is " << highScore << std::endl;
        end = true;
    }
    notifyObservers();
    if ((curGame == tGame1? tGame2 : tGame1) ->shouldPromptSpecialEffect() && !didPromptSpecialEffect) {
        std::cout << "What special effect would you like to apply to the current player? (blind, force, heavy)" << std::endl;
        didPromptSpecialEffect = true;
        getSpecialEffectInput = true;
    }
}

void Game::heavy() {
    curGame->heavy();
}

void Game::blind() {
    curGame->blind();
    notifyObservers();
}

bool Game::getEnd() {
    return end;
}

bool Game::getSingleGameEnd(int board) {
    if (board == 1) {
        return tGame1->ended();
    }
    if (board == 2) {
        return tGame2->ended();
    }
    return false;
}

bool &Game::shouldGetSpecialEffectInput() {
    return getSpecialEffectInput;
}





