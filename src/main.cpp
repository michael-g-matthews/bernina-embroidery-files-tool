#include <QtWidgets>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.show(); // Show main window
    return app.exec();
}