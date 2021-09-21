//
// Created by alessandro on 19/09/21.
//

#ifndef PROGRESSBAR_LOADFILES_H
#define PROGRESSBAR_LOADFILES_H

#include "Subject.h"
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

    void handleFile(QString file);

private:
    list<Observer *> observers;
    QStringList files;
    bool loaded;
    int filesNumber;


};


#endif //PROGRESSBAR_LOADFILES_H
