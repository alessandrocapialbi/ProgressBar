//
// Created by alessandro on 19/09/21.
//

#include "MainWindow.h"

MainWindow::MainWindow(LoadFiles *lF, QWidget *parent) : QMainWindow(parent), loadFiles(lF) {
    loadFiles->registerObserver(this);

};
