//
// Created by Dillon Liu on 2022-11-26.
//

#ifndef BIQUADRIS_GRAPHICALDISPLAY_H
#define BIQUADRIS_GRAPHICALDISPLAY_H


#include "Observer.h"
#include <memory>
#include "window.h"
#include "window.h"
class Game;


class GraphicalDisplay: public Observer {
    Game* game;
    Xwindow w;
    Xwindow::Color getColor(char c);
public:
    GraphicalDisplay(Game *game);
    void notify() override;
    ~GraphicalDisplay();
};


#endif //BIQUADRIS_GRAPHICALDISPLAY_H
