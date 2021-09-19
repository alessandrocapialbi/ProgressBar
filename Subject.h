//
// Created by alessandro on 19/09/21.
//

#ifndef PROGRESSBAR_SUBJECT_H
#define PROGRESSBAR_SUBJECT_H

#endif //PROGRESSBAR_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual void registerObserver(Observer *o) = 0;

    virtual void removeObserver(Observer *o) = 0;

    virtual void notifyObservers() const = 0;

};