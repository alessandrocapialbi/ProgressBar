//
// Created by alessandro on 19/09/21.
//

#include "MainWindow.h"

MainWindow::MainWindow(LoadFiles *lF, QWidget *parent) : QMainWindow(parent), loadFiles(lF) {
    loadFiles->registerObserver(this);

    this->setWindowTitle("Progress Bar for loading files");
    this->setFixedSize(QSize(800, 600));

    fileProgressBar = new QProgressBar(this);
    fileProgressBar->setGeometry(QRect(QPoint(150, 170), QSize(300, 30)));
    fileProgressBar->setMinimum(0);
    fileProgressBar->setMaximum(100);


};

void MainWindow::update() {

}
