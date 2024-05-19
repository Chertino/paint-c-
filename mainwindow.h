#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QMainWindow>

class ProyectoPaint;
class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    // Creación de evento para cerrar la aplicación
    void closeEvent(QCloseEvent *Event) override;

public:
    MainWindow();

private slots:
    // Slots de funciones puntuales
    void abrir();
    void guardar();
    void color();
    void borrador();
    void grosor();
    void lapiz();
    void informacion();
    void drawRectangle();
    void drawCircle();
    void drawTriangle();
    void drawLine();

private:
    // Funciones adicionales
    void crearAcciones();
    void crearMenus();
    bool guardadoextra();
    bool guardarArchivo(const QByteArray &fileFormat);
    ProyectoPaint *Proyectopaint;

    // Creación de menús dependiendo de su utilidad
    QMenu *MenuGuardarComo;
    QMenu *MenuDeArchivo;
    QMenu *MenuDeAjustes;
    QMenu *MenuDeInformacion;
    QMenu *MenuDeGraficos;

    // Creación de acciones dentro de la aplicación
    QAction *AccionAbrir;
    QList<QAction *> AccionesGuardarComo;
    QAction *AccionSalir;
    QAction *Accioncolor;
    QAction *Accionborrador;
    QAction *Acciongrosor;
    QAction *AccionlimpiarVentana;
    QAction *AccionInformacion;
    QAction *AccionQtInformacion;
    QAction *AccionLapiz;

    QAction *AccionDrawRectangle;
    QAction *AccionDrawCircle;
    QAction *AccionDrawTriangle;
    QAction *AccionDrawLine;
};

#endif // MAINWINDOW_H
