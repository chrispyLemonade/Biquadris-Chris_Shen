#include <memory>
#include <string>
#include <vector>
#include <utility>
#include "Decorator.h"
using namespace std;

Decorator::Decorator(shared_ptr<BoardAbstract> component) : myBoard{component} {}

Decorator::~Decorator() {}

char Decorator::charAt(int row, int col) {
    return myBoard->charAt(row, col);
}
