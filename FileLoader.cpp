//
// Created by alessandro on 19/09/21.
//

#include "FileLoader.h"

void FileLoader::registerObserver(Observer *o) {
    observers.push_back(o);
}

void FileLoader::removeObserver(Observer *o) {
    observers.remove(o);
}

void FileLoader::notifyObservers() const {

    for (const auto &i: observers) {
        i->update();
    }
}

void FileLoader::load(QStringList fileNames) {
    try {
        filesNumber = static_cast<int>(fileNames.size()); //Number of files open by the user during browsing.
        if (!filesNumber) {
            throw runtime_error("No files provided.");
        }
    } catch (runtime_error &exc) {
        cerr << exc.what() << endl;
    }

    for (auto &it: fileNames) {
        handleFile(it);
    }
}

void FileLoader::handleFile(const QString &it) {
    try {
        File file(it);
        filename = QString(it);
        fileSize = file.getSize();
        loaded = true;
        notifyObservers();
    } catch (runtime_error &exc) {
        cerr << exc.what() << endl << endl;
        filename = QString(it);
        loaded = false;
        notifyObservers();
    } catch (...) {
        cerr << "Unknown exception caught!" << endl;
    }
}

