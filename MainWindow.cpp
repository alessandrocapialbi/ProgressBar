//
// Created by alessandro on 19/09/21.
//

#include "MainWindow.h"

MainWindow::MainWindow(LoadFiles *lF, QWidget *parent) : QMainWindow(parent), loadFiles(lF) {
    loadFiles->registerObserver(this);

    this->setWindowTitle("Progress Bar for loading files");
    this->setFixedSize(QSize(800, 600));

    title = new QLabel("Load your PC files!", this);
    title->setGeometry(QRect(QPoint(100, 60), QSize(400, 100)));
    title->setWordWrap(true);
    title->setAlignment(Qt::AlignCenter);
    QFont font = title->font();
    font.setPointSize(20);
    title->setFont(font);

    fileProgressBar = new QProgressBar(this);
    fileProgressBar->setGeometry(QRect(QPoint(190, 170), QSize(400, 30)));
    fileProgressBar->setMinimum(0);
    fileProgressBar->setMaximum(100);

    browseButton = new QPushButton("Browse file", this);
    browseButton->setGeometry(QRect(QPoint(190, 220), QSize(200, 30)));

    // Connect button signal to appropriate slot
    connect(browseButton, SIGNAL (released()), this, SLOT (load()));


};

void MainWindow::update() {

}

void MainWindow::load() {

    QString fileName = QFileDialog::getOpenFileName(this, "Open a file", "C://");

}
