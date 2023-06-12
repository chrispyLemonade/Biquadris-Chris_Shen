#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H

#include <string>
#include <iostream>
#include <map>
class Game;

class CommandInterpreter {
    std::map<std::string, std::string> commandMap;
    bool isRestart;
    Game* myGame;

  public:
    CommandInterpreter(Game *myGame);
    bool getRestart();
    void registerCommand(std::string line);
    void updateMyGame(Game* myGame);
    
    void rename(std::string newName, std::string oldName);
};

#endif