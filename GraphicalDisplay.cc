//
// Created by Dillon Liu on 2022-11-26.
//

#include "GraphicalDisplay.h"
#include "window.h"
#include "Game.h"

void GraphicalDisplay::notify() {
    w.fillRectangle(25 , 0, 500, 500, Xwindow::White);
    w.drawString(20, 20, "Level: " + std::to_string(game->getLevel(1)));
    w.drawString(20, 40, "Score: " + std::to_string(game->getScore(1)));

    w.drawString(250, 20, "Level: " + std::to_string(game->getLevel(2)));
    w.drawString(250, 40, "Score: " + std::to_string(game->getScore(2)));

    int windowX = 25;
    int windowY = 80;

    if (game->getSingleGameEnd(1)) {
        w.drawString(26, 74, "Game Over!");
    }
    w.fillRectangle(25, 80, 165, 270, Xwindow::Black);
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j <= 10; ++j) {
            char c = game->getState(1, i, j);
            if (c != ' ') {
                w.fillRectangle(windowX, windowY, 15, 15, getColor(c));
            }

            windowX += 15;
        }
        windowY += 15;
        windowX = 25;
    }

    windowX = 255;
    windowY = 80;

    if (game->getSingleGameEnd(2)) {
        w.drawString(246, 74, "Game Over!");
    }
    w.fillRectangle(255, 80, 165, 270, Xwindow::Black);
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j <= 10; ++j) {
            char c = game->getState(2, i, j);
            if (c != ' ') {
                w.fillRectangle(windowX, windowY, 15, 15, getColor(c));
            }

            windowX += 15;
        }
        windowY += 15;
        windowX = 255;
    }

    std::shared_ptr<Block> block = game->getNextBlock();
    if (game->getCurBoard() == 1) {
        w.drawString(30, 400, "Next:");
        for (int i = 0; i < 4; ++i) {
            Coordinate pos = block->getAllPixels()[i];
            w.fillRectangle(30 + (pos.y * 15), 420 + (pos.x - 3) * 15, 15, 15, getColor(block->getC()));
        }
    }
    else {
        w.drawString(265, 400, "Next:");
        for (int i = 0; i < 4; ++i) {
            Coordinate pos = block->getAllPixels()[i];
            w.fillRectangle(265 + (pos.y * 15), 420 + (pos.x - 3) * 15, 15, 15, getColor(block->getC()));
        }
    }
}

Xwindow::Color GraphicalDisplay::getColor(char c) {
    if (c == 'I') {
        return w.Cyan;
    }
    else if (c == 'J') return w.Blue;
    else if (c == 'L') return w.Orange;
    else if (c == 'O') return w.Yellow;
    else if (c == 'S') return w.Green;
    else if (c == 'Z') return w.Red;
    else if (c == 'T') return w.Magenta;
    else if (c == '*') return w.Brown;
    else return w.White;
}

GraphicalDisplay::GraphicalDisplay(Game* game): game{game} {
    game->attach(this);
}

GraphicalDisplay::~GraphicalDisplay() {
    game->detach(this);
}

