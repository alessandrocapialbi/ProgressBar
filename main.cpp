#include <QApplication>
#include <QPushButton>
#include <memory>
#include "LoadFiles.h"
#include "MainWindow.h"

using namespace std;

int main(int argc, char *argv[]) {

    QApplication *app = new QApplication(argc, argv);

    LoadFiles loader;

    MainWindow mainWindow(&loader, app);

    mainWindow.show();

    return app->exec();


}
