//
// Created by Dillon Liu on 2022-11-26.
//

#include "TextDisplay.h"
#include <iomanip>
#include <memory>
#include "Game.h"

void TextDisplay::notify() {
    out << std::setw(9) << std::left << "Level:   " << std::setw(3) << std::right << game->getLevel(1) << std::setw(21) << std::right << "Level:     " << std::right << game->getLevel(2)<< std::endl;
    out << std::setw(9) << std::left << "Score:   " << std::setw(3) << std::right << game->getScore(1) << std::setw(21) << std::right << "Score:     " << std::right << game->getScore(2) << std::endl;
    if (game->getCurBoard() == 1) {
        out << "P1 Your Turn!" << std::endl;
    }
    else if (game->getCurBoard() == 2) {
        out << std::setw(35) << std::right << "P2 Your Turn!" << std::endl;
    }
    out << "-------------" << std::setw(22) << "-------------" << std::endl;
    for (int i = 0; i < 18; ++i) {
        // board 1
        out << "|";
        if (i == 0 && game->getSingleGameEnd(1)) {
            out << " Game Over ";
        }
        else {
            for (int j = 0; j <= 10; ++j) {
                out << game->getState(1, i, j);
            }
        }

        out << "|";
        out << std::setw(10);

        // board 2

            out << "|";
            if (i == 0 && game->getSingleGameEnd(2)) {
                out << " Game Over ";
            }
            else {
                for (int j = 0; j <= 10; ++j) {
                    out << game->getState(2, i, j);
                }
            }
            out << "|";
            out << std::endl;
    }
    out << "-------------" << std::setw(22) << "-------------" << std::endl;
    std::shared_ptr<Block> nextBlock = game->getNextBlock();
    std::vector<Coordinate> blockPos = nextBlock->getAllPixels();

    if (!game->getEnd()) {
        out << "Next:";
        out << std::setw(22) << "Next:" << std::endl;

        if (game->getCurBoard() == 1) {
            for (int x = 3; x <= 4; ++x) {
                for (int y = 0; y <= 3; ++y) {
                    bool printedChar = false;
                    for (int index = 0; index < 4; ++index) {
                        if (blockPos[index].x == x && blockPos[index].y == y) {
                            out << nextBlock->getC();
                            printedChar = true;
                        }
                    }
                    if (!printedChar) out << " ";
                }
                out << std::endl;
            }
        }

        if (game->getCurBoard() == 2) {
            for (int x = 3; x <= 4; ++x) {
                out << std::setw(27);
                for (int y = 0; y <= 3; ++y) {
                    bool printedChar = false;
                    for (int index = 0; index < 4; ++index) {
                        if (blockPos[index].x == x && blockPos[index].y == y) {
                            out << nextBlock->getC();
                            printedChar = true;
                        }
                    }
                    if (!printedChar) out << " ";
                }
                out << std::endl;
            }

        }
    }
}

TextDisplay::TextDisplay(Game* game): game{game} {
    game->attach(this);
}

TextDisplay::~TextDisplay() {
    game->detach(this);
}
