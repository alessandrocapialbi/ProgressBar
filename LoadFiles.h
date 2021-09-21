//
// Created by alessandro on 19/09/21.
//

#ifndef PROGRESSBAR_LOADFILES_H
#define PROGRESSBAR_LOADFILES_H

#include "Subject.h"
#include "File.h"
#include <QStringList>
#include <iostream>
#include <list>

using namespace std;

class LoadFiles : public Subject {
public:
    void registerObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notifyObservers() const override;

    void load(QStringList fileName);

    void handleFile(const QString &it);

    const QString &getFilename() const {
        return filename;
    };

    int getFileSize() const {
        return fileSize;
    };

    bool isLoaded() const {
        return loaded;
    }

private:
    list<Observer *> observers;
    bool loaded;
    int filesNumber, fileSize;
    QString filename;


};


#endif //PROGRESSBAR_LOADFILES_H
