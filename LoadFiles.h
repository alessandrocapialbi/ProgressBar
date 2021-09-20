//
// Created by alessandro on 19/09/21.
//

#ifndef PROGRESSBAR_LOADFILES_H
#define PROGRESSBAR_LOADFILES_H

#include "Subject.h"
#include <list>

using namespace std;

class LoadFiles : public Subject {
public:
    void registerObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notifyObservers() const override;

    void load(list<char *> filenames);

private:
    list<Observer *> observers;
    list<char *> files;
    bool loaded;


};


#endif //PROGRESSBAR_LOADFILES_H
