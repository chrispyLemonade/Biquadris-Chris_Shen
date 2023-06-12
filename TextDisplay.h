//
// Created by Dillon Liu on 2022-11-26.
//

#ifndef BIQUADRIS_TEXTDISPLAY_H
#define BIQUADRIS_TEXTDISPLAY_H
#include <memory>
#include "Observer.h"
#include <iostream>
class Game;
class TextDisplay: public Observer {
    Game* game;
    std::ostream &out = std::cout;
public:
    TextDisplay(Game *game);
    void notify() override;
    ~TextDisplay();
};


#endif //BIQUADRIS_TEXTDISPLAY_H
