//
// Created by Dillon Liu on 2022-11-26.
//

#ifndef BIQUADRIS_SUBJECT_H_1
#define BIQUADRIS_SUBJECT_H_1
#include <memory>
#include <vector>
#include "Observer.h"

class Subject {
protected:
    std::vector<Observer *> observers;

public:
    void notifyObservers();
    void attach(Observer *obs);
    void detach(Observer *obs);
};


#endif //BIQUADRIS_SUBJECT_H
