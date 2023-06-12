//
// Created by Dillon Liu on 2022-11-26.
//

#include "Subject.h"
#include <iostream>

void Subject::notifyObservers() {
    for (auto i = observers.begin(); i != observers.end(); ++i) {
        (*i)->notify();
    }
}

void Subject::attach(Observer *obs) {
    observers.emplace_back(obs);
}

void Subject::detach(Observer *obs) {
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        if (*it == obs) {
            observers.erase(it);
            break;
        }
    }
}
