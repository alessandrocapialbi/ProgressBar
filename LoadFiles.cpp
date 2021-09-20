//
// Created by alessandro on 19/09/21.
//

#include "LoadFiles.h"

void LoadFiles::registerObserver(Observer *o) {
    observers.push_back(o);

}

void LoadFiles::removeObserver(Observer *o) {
    observers.remove(o);

}

void LoadFiles::notifyObservers() const {

}

void LoadFiles::load(list<char *> filenames) {

}
