//
// Created by alessandro on 19/09/21.
//

#include "MainWindow.h"

MainWindow::MainWindow(LoadFiles *lF, QWidget *parent) : QMainWindow(parent), loadFiles(lF) {
    loadFiles->registerObserver(this);

    this->setWindowTitle("Progress Bar for loading files - Powered by QT");
    this->setFixedSize(QSize(800, 600));
    QPixmap bkgnd("resources/bkngd.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    title = new QLabel("Load your PC files!", this);
    title->setGeometry(QRect(QPoint(100, 60), QSize(400, 100)));
    title->setWordWrap(true);
    title->setAlignment(Qt::AlignCenter);
    QFont font = title->font();
    font.setPointSize(20);
    title->setFont(font);

    fileProgressBar = new QProgressBar(this);
    fileProgressBar->setGeometry(QRect(QPoint(190, 170), QSize(400, 30)));
    fileProgressBar->setRange(0, 100);
    fileProgressBar->setValue(0);

    browseButton = new QPushButton("Browse file", this);
    browseButton->setGeometry(QRect(QPoint(190, 220), QSize(200, 30)));

    textArea = new QTextEdit(this);
    textArea->setGeometry(QRect(QPoint(190, 275), QSize(500, 140)));
    textArea->setText("---> File log\n");
    textArea->setReadOnly(true);

    // Connect button signal to appropriate slot
    connect(browseButton, SIGNAL (released()), this, SLOT (load()));


};

void MainWindow::update() {

    QString log;
    if (loadFiles->isLoaded()) {
        textArea->setTextColor(QColorConstants::Svg::green);
        log = "✅ Loaded file '" + QString(loadFiles->getFilename()) + QString("' successfully (") +
              QString::number(loadFiles->getFileSize()) + QString(" bytes).") + "\n";
    } else {
        textArea->setTextColor(QColorConstants::Svg::red);
        log = "❌ Could not load file '" + loadFiles->getFilename();
    }
    textArea->append(log);

}

void MainWindow::load() {

    browseWindow = new QFileDialog(this);
    QStringList fileNames = browseWindow->getOpenFileNames(this, "Open a file", "C://", "*.txt");
    loadFiles->load(fileNames);
}
