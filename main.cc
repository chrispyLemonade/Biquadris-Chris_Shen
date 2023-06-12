#include "CommandInterpreter.h"
#include <sstream>
#include <fstream>
#include "Game.h"

using namespace std;


int main(int argc, char *argv[]) {
    bool textOnly = false;
    unsigned seed = 0;
    string scriptFile1 = "sequence1.txt";
    string scriptFile2 = "sequence2.txt";
    int startLevel = 0;

    string each;

    for (int i = 1; i < argc; ++i) {
        each = argv[i];
        if (each == "-text") {
            textOnly = true;
        } else if (each == "-seed") {
            istringstream num {argv[i + 1]};
            num >> seed;
        } else if (each == "-scriptfile1") {
            scriptFile1 = argv[i + 1];
        } else if (each == "-scriptfile2") {
            scriptFile2 = argv[i + 1];
        } else if (each == "-startlevel") {
            istringstream num {argv[i + 1]};
            num >> startLevel;
        }
    }


    int highScore = 0;
    std::unique_ptr<Game> oneGame = std::make_unique<Game>(textOnly, seed, scriptFile1, scriptFile2, highScore, startLevel);

    string command;
    CommandInterpreter ci{oneGame.get()};

    while (getline(cin, command)) {
        ci.registerCommand(command);
        if (ci.getRestart() && !cin.eof()) {
            oneGame = std::make_unique<Game>(textOnly, seed, scriptFile1, scriptFile2, highScore, startLevel);
            ci.updateMyGame(oneGame.get());
            cout << "High score: " << highScore << std::endl;
        }
    }
}
