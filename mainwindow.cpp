#include <QtWidgets>
#include "mainwindow.h"
#include "Proyectopaint.h"



MainWindow::MainWindow()
{
    Proyectopaint = new ProyectoPaint;
    setCentralWidget(Proyectopaint);
    crearAcciones();
    crearMenus();
    setWindowTitle(tr ("Proyecto paint programacion 2"));
    resize(1080, 720);
}
void MainWindow::closeEvent(QCloseEvent *event){
    if(guardadoextra()){
        event->accept();
    }else{
        event->ignore();
    }
}

void MainWindow::abrir(){
    if(guardadoextra()){
        QString fileName = QFileDialog::getOpenFileName(this,
                                                        tr("Abrir archivo"), QDir::currentPath());
        if(!fileName.isEmpty()){
            Proyectopaint->abrirImagen(fileName);
        }
    }
}

void MainWindow::guardar(){
    QAction *action = qobject_cast<QAction *>(sender());
    QByteArray fileFormat = action->data().toByteArray();
    guardarArchivo(fileFormat);

}

void MainWindow::color(){
    QColor newColor = QColorDialog::getColor(Proyectopaint->color());
    if(newColor.isValid()){
        Proyectopaint->cambiarColor(newColor);
    }

}

void MainWindow::grosor(){
    bool ok;
    int newWidth = QInputDialog::getInt(this, tr("Proyecto paint"), tr("Selecciona el grosor : "),
                                           Proyectopaint->grosor(),
                                           1, 50, 1, &ok );
    if(ok){
        Proyectopaint->cambiarGrosor(newWidth);
    }
}

void MainWindow::informacion(){
    QMessageBox::about(this, tr("Sobre Proyecto Paint"),
                       tr("<p> All the <b>(Proyecto Paint)<b> inspiration came from <b> Derek Banas on youtube<b> </p>"));
}

void MainWindow::crearAcciones(){
    AccionAbrir = new QAction(tr ("&Abrir"), this);
    AccionAbrir->setShortcuts(QKeySequence::Open);
    connect(AccionAbrir, SIGNAL(triggered()), this, SLOT(abrir()));

    foreach(QByteArray format, QImageWriter::supportedImageFormats()){
        QString text = tr("%1...").arg(QString(format).toUpper());
        QAction *action = new QAction(text, this );
        action->setData(format);
        connect(action, SIGNAL(triggered()), this, SLOT(guardar()));
        AccionesGuardarComo.append(action);
    }

    AccionSalir = new QAction(tr("&Salir"), this);
    AccionSalir->setShortcuts(QKeySequence::Quit);

    Accioncolor = new QAction(tr("&Color..."), this); // Conectar a MainWindow
    connect(Accioncolor, SIGNAL(triggered()), this, SLOT(color()));
    Accioncolor->setShortcut(tr("Ctrl+c"));

    Acciongrosor = new QAction(tr("&Grosor..."), this); // Conectar a MainWindow
    Acciongrosor->setShortcut(tr("Ctrl++"));
    connect(Acciongrosor, SIGNAL(triggered()), this, SLOT(grosor()));

    AccionlimpiarVentana = new QAction(tr("&Limpiar lienzo..."), this);
    AccionlimpiarVentana->setShortcut(tr("Ctrl+L"));
    connect(AccionlimpiarVentana, SIGNAL(triggered()), Proyectopaint, SLOT(clearImage()));

    AccionInformacion = new QAction(tr("&Aceca de..."), this); // Conectar a MainWindow
    connect(AccionInformacion, SIGNAL(triggered()), this, SLOT(informacion()));

    AccionQtInformacion = new QAction(tr("&Aceca de..."), this);
    connect(AccionQtInformacion, SIGNAL(triggered()),qApp, SLOT(aboutQt()));
}

void MainWindow::crearMenus(){

    MenuGuardarComo = new QMenu(tr("&Guardar como"),this);
    foreach(QAction *action, AccionesGuardarComo)
        MenuGuardarComo->addAction(action);

    MenuDeArchivo = new QMenu(tr("&Archivo"), this);
    MenuDeArchivo->addAction(AccionAbrir);
    MenuDeArchivo->addMenu(MenuGuardarComo);

    MenuDeArchivo->addSeparator();
    MenuDeArchivo->addAction(AccionSalir);

    MenuDeAjustes = new QMenu(tr("&Ajustes"), this);
    MenuDeAjustes->addAction(Accioncolor);
    MenuDeAjustes->addAction(Acciongrosor);
    MenuDeAjustes->addSeparator();
    MenuDeAjustes->addAction(AccionlimpiarVentana);

    MenuDeInformacion = new QMenu(tr("&Acerca de"), this);
    MenuDeInformacion->addAction(AccionInformacion);
    MenuDeInformacion->addAction(AccionQtInformacion);

    menuBar()->addMenu(MenuDeArchivo);
    menuBar()->addMenu(MenuDeAjustes);
    menuBar()->addMenu(MenuDeInformacion);



}

//Cerrar la aplicacion sin guardar

bool MainWindow::guardadoextra(){
    if(Proyectopaint->modificaciones()){
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, tr("Proyecto Paint"),
                                   tr("Hay modificaciones en la imagen. \n"
                                      "Desea guardar los cambios?"),
                                   QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel );

        if (ret == QMessageBox::Save) {
            return guardarArchivo("png");


        } else if (ret == QMessageBox::Cancel) {
            return false;
        }
    }
    return true;
}


bool MainWindow::guardarArchivo(const QByteArray &fileFormat){
    QString initialPath = QDir::currentPath() + "/lienzo." + fileFormat;
    QString fileName = QFileDialog::getSaveFileName(this, tr("Guardar como"),
                                                    initialPath,
                                                    tr("%1 Files (* .%2);; All Files(*)")
                                                        .arg(QString::fromLatin1(fileFormat.toUpper()))
                                                        .arg(QString::fromLatin1(fileFormat)));
    if(fileName.isEmpty()){
        return false;

    } else {
        return Proyectopaint->guardarImagen(fileName, fileFormat.constData());
    }
}



