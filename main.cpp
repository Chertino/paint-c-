#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //La aplicacion principal
    QApplication app(argc, argv);

    // Crea y abre la ventana principal
    MainWindow window;
    window.show();

    // Mostrar la ventana principal
    return app.exec();
}
