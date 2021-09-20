//
// Created by alessandro on 19/09/21.
//

#ifndef PROGRESSBAR_MAINWINDOW_H
#define PROGRESSBAR_MAINWINDOW_H

#include "LoadFiles.h"
#include "Observer.h"
#include <memory>
#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QWidget>
#include <QPushButton>

class MainWindow : public Observer, public QMainWindow {
public:
    MainWindow(LoadFiles *lF, QWidget *parent = 0);

    virtual ~MainWindow() {
        loadFiles->removeObserver(this);
    }

    virtual void update() override;

    const LoadFiles *getLoadFiles() const {
        return loadFiles;
    }

    void load();


private:
    LoadFiles *loadFiles;
    QProgressBar *fileProgressBar;
    QLabel *title;
    QProgressBar *overallProgressBar;
    QPushButton *browseButton;


};


#endif //PROGRESSBAR_MAINWINDOW_H
