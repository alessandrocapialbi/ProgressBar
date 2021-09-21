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

    for (const auto &i: observers) {
        i->update();
    }
}

void LoadFiles::load(QStringList fileName) {


    try {
        filesNumber = static_cast<int>(files.size());
        if (!filesNumber) {
            throw runtime_error("No files provided.");
        }
    } catch (runtime_error &e) {
        cerr << e.what() << endl;
    }

    for (auto &itr: files) {
        handleFile(itr);
    }

}

void LoadFiles::handleFile(QString file) {


}
