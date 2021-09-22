//
// Created by alessandro on 19/09/21.
//

#ifndef PROGRESSBAR_MAINWINDOW_H
#define PROGRESSBAR_MAINWINDOW_H

#include "LoadFiles.h"
#include "Observer.h"
#include <memory>
#include <iostream>
#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QWidget>
#include <QFileDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QPropertyAnimation>

using namespace std;

class MainWindow : public QMainWindow, public Observer {
Q_OBJECT

public:
    MainWindow(LoadFiles *lF, QWidget *parent = 0);

    virtual ~MainWindow() {
        loadFiles->removeObserver(this);
    }

    virtual void update() override;

    const LoadFiles *getLoadFiles() const {
        return loadFiles;
    }

private slots:

    void load();


private:
    LoadFiles *loadFiles;
    unique_ptr<QProgressBar> fileProgressBar;
    unique_ptr<QTextEdit> textArea;
    unique_ptr<QLabel> title;
    unique_ptr<QProgressBar> overallProgressBar;
    QPushButton *browseButton;
    unique_ptr<QFileDialog> browseWindow;
    unique_ptr<QPropertyAnimation> progressBarAnimation;


};


#endif //PROGRESSBAR_MAINWINDOW_H
