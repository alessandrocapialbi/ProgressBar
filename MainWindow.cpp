//
// Created by alessandro on 19/09/21.
//

#include "MainWindow.h"

MainWindow::MainWindow(LoadFiles *lF, QWidget *parent) : QMainWindow(parent), loadFiles(lF) {
    loadFiles->registerObserver(this);

    this->setWindowTitle("Progress Bar for loading files");
    this->setFixedSize(800, 600);

    fileProgressBar->setMinimum(0);
    fileProgressBar->setMaximum(100);


};

void MainWindow::update() {

}
