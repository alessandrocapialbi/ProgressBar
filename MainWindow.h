//
// Created by alessandro on 19/09/21.
//

#ifndef PROGRESSBAR_MAINWINDOW_H
#define PROGRESSBAR_MAINWINDOW_H

#include "LoadFiles.h"
#include "Observer.h"
#include <memory>
#include <unistd.h>
#include <cfloat>
#include <iostream>
#include <QMainWindow>
#include <QApplication>
#include <QProcess>
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
    MainWindow(LoadFiles *lF, QApplication *app, QWidget *parent = 0);

    virtual ~MainWindow() {
        loadFiles->removeObserver(this);
    }

    virtual void update() override;

    const LoadFiles *getLoadFiles() const {
        return loadFiles;
    }

private slots:

    void load();

    void resetWindow();


private:
    LoadFiles *loadFiles;
    QApplication *application;
    unique_ptr<QProgressBar> fileProgressBar;
    unique_ptr<QTextEdit> textArea;
    unique_ptr<QLabel> title, fileProgress, overallProgress;
    unique_ptr<QProgressBar> overallProgressBar;
    QPushButton *browseButton, *reset;
    unique_ptr<QFileDialog> browseWindow;


};


#endif //PROGRESSBAR_MAINWINDOW_H
