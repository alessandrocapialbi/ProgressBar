//
// Created by alessandro on 19/09/21.
//

#ifndef PROGRESSBAR_MAINWINDOW_H
#define PROGRESSBAR_MAINWINDOW_H

#include "LoadFiles.h"
#include "Observer.h"
#include <memory>
#include <QMainWindow>
#include <QWidget>

class MainWindow : public Observer, public QMainWindow {
public:
    MainWindow(LoadFiles *lF, QWidget *parent = 0);

    ~MainWindow() {
        loadFiles->removeObserver(this);
    }

    void update() override;

    const LoadFiles *getLoadFiles() const {
        return loadFiles;
    }


private:
    LoadFiles *loadFiles;


};


#endif //PROGRESSBAR_MAINWINDOW_H
