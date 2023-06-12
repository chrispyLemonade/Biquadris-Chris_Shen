//
// Created by Dillon Liu on 2022-11-26.
//

#ifndef BIQUADRIS_OBSERVER_H
#define BIQUADRIS_OBSERVER_H


class Observer {
public:
    virtual void notify() = 0;
    virtual ~Observer() = default;
};


#endif //BIQUADRIS_OBSERVER_H
