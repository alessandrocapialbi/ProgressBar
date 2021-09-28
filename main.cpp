#include <QApplication>
#include <QPushButton>
#include <memory>
#include "LoadFiles.h"
#include "MainWindow.h"

using namespace std;

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    LoadFiles loader;

    MainWindow mainWindow(&loader);

    mainWindow.show();

    return app.exec();


}
