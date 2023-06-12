#include "CommandInterpreter.h"
#include "direction.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "Game.h"
using namespace std;

CommandInterpreter::CommandInterpreter(Game *myGame) : isRestart{false}, myGame{myGame} {
    // setting the key-value pairs in commandMap

    commandMap["left"] = "left";
    commandMap["right"] = "right";
    commandMap["down"] = "down";
    commandMap["clockwise"] = "clockwise";
    commandMap["counterclockwise"] = "counterclockwise";
    commandMap["drop"] = "drop";
    commandMap["levelup"] = "levelup";
    commandMap["leveldown"] = "leveldown";
    commandMap["norandom"] = "norandom";
    commandMap["random"] = "random";
    commandMap["rename"] = "rename";
    commandMap["sequence"] = "sequence";
    commandMap["restart"] = "restart";
    commandMap["heavy"] = "heavy";
    commandMap["force"] = "force";
    commandMap["blind"] = "blind";
    commandMap["I"] = "I";
    commandMap["J"] = "J";
    commandMap["S"] = "S";
    commandMap["Z"] = "Z";
    commandMap["T"] = "T";
    commandMap["O"] = "O";
    commandMap["L"] = "L";

}

bool CommandInterpreter::getRestart() {
   return isRestart;
}

void CommandInterpreter::registerCommand(std::string line) {
    istringstream myLine {line};
    string myCommand;
    int multiplier = 0;
    string functionToCall;

    isRestart = false;  

    myLine >> multiplier;
    
    if (myLine.fail()) {     //if no multiplier are read
        multiplier = 1;
        myLine.clear();
    }

    myLine >> myCommand;

    int count = 0;
    vector<string> possibleCmds;
    for (int i = 1; i <= static_cast<int>(myCommand.size()); i++) {
        count = 0;
        possibleCmds.clear();
        for (auto &p: commandMap) {
            if (myCommand.substr(0, i) == p.second.substr(0, i)) {  // checks if the substring in mycommand is a match for every key in commandMap
                count++;
                functionToCall = p.first;
                possibleCmds.emplace_back(functionToCall);
                //cerr << p.second.substr(0, i) << " ";
            }
        }

        if (count == 1) {
            break;
        }
    }

    if (myGame->shouldGetSpecialEffectInput()) {
        if (functionToCall == "heavy") {
            myGame->heavy();
        }
        else if (functionToCall == "force") {
            char myChar;
            myLine >> myChar;
            myGame->replaceBlock(myChar);
        }
        else if (functionToCall == "blind") {
            myGame->blind();
        }
        else {
            cout << "That wasn't one of the options..." << endl;
            return;
        }
        myGame->shouldGetSpecialEffectInput() = false;
        return;
    }

    else if (count > 1) {
        cout << "Did you mean ";
        for (auto it = possibleCmds.begin(); it != possibleCmds.end(); ++it) {
            if (*it != possibleCmds.at(possibleCmds.size()-1)) {
                cout << *it << " / ";
            }
            else {
                cout << *it << "? Please be more specific!" << endl;
            }
        }
    }

    else if (count == 0) {
        cout << "You have entered an invalid command! Please enter a valid one, thanks :)" << endl;
    }

    else {
        if (functionToCall == "random") {
            myGame->random();
        }
        else if (functionToCall == "restart") {
            isRestart = true;
        }
        else if (functionToCall == "noramdom") {
            string file;
            myLine >> file;

            myGame->noRandom(file);
        }

        else {
            for (int i = 0; i < multiplier; i++) {
                if (functionToCall == "left") {
                    myGame->moveBlock(Direction::left);
                } else if (functionToCall == "levelup") {
                    myGame->changeLevel(true);
                } else if (functionToCall == "leveldown") {
                    myGame->changeLevel(false);
                } else if (functionToCall == "right") {
                    myGame->moveBlock(Direction::right);
                } else if (functionToCall == "rename") {
                    string originalCom;
                    string newCom;
                    myLine >> originalCom;
                    myLine >> newCom;

                    for (auto &p:commandMap) {
                        if (p.second == originalCom) {
                            p.second = newCom;
                        }
                    }
                } else if (functionToCall == "down") {
                    myGame->moveBlock(Direction::down);
                } else if (functionToCall == "drop") {
                    myGame->drop();
                } else if (functionToCall == "clockwise") {
                    myGame->spinBlock(true);
                } else if (functionToCall == "counterclockwise") {
                    myGame->spinBlock(false);
                } else if (functionToCall == "sequence") {
                    string file;
                    myLine >> file;
                    ifstream ifs(file);
                    string input;

                    while (getline(ifs, input)) {
                        registerCommand(input);
                    }
                }
                else if (functionToCall == "I") {
                    myGame->replaceBlock('I');
                } else if (functionToCall == "J") {
                    myGame->replaceBlock('J');
                } else if (functionToCall == "L") {
                    myGame->replaceBlock('L');
                } else if (functionToCall == "O") {
                    myGame->replaceBlock('O');
                } else if (functionToCall == "S") {
                    myGame->replaceBlock('S');
                } else if (functionToCall == "Z") {
                    myGame->replaceBlock('Z');
                } else if (functionToCall == "T") {
                    myGame->replaceBlock('T');
                }
            }
        }
    }

    if (myGame->getEnd()) {
        cout << "Press [ENTER] to continue playing, or abort the program." << std::endl;
        string input;
        getline(cin, input);
        isRestart = true;
        return;
    }
}

void CommandInterpreter::updateMyGame(Game *myGame) {
    this->myGame = myGame;
}

/*  left        lef
    levelup     levelu
    leveldown   leveld

    right
    random
    rename
    restart

    down
    drop

    clockwise
    counterclockwise

    norandom file
    sequence file
    heavy
    force
    blind
    I, J, L, ...
    EOF
*/

// special effect

// only as much as is necessary to distinguish from other cmds is required
// multiplier prefix ex: 3ri ==> right, right, right EXCEPT: restart, norandom, random

//invalid input case
// void CommandInterpreter::rename(std::string newName, std::string oldName) {
//     commandMap.at(oldName) = newName;
// }
