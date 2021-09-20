#include <QApplication>
#include <QPushButton>
#include "LoadFiles.h"
#include "MainWindow.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    LoadFiles loader;

    MainWindow mainWindow(&loader);

    mainWindow.show();

    return app.exec();


}
