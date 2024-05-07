#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QMainWindow>

class ProyectoPaint;
class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    //Creacion de evento para cerrar la aplicacion
    void closeEvent(QCloseEvent *Event) override;

public:
  MainWindow();
private slots:
    //Slots de funciones puntuales
    void abrir();
    void guardar();
    void color();
    void borrador();
    void grosor();
    void informacion();
private:
    //Funciones adicionales
    void crearAcciones();
    void crearMenus();
    bool guardadoextra();
    bool guardarArchivo(const QByteArray &fileFormat);
    ProyectoPaint *Proyectopaint;
    //Creacion de menus dependiendo de su utilidad
    QMenu *MenuGuardarComo;
    QMenu *MenuDeArchivo;
    QMenu *MenuDeAjustes;
    QMenu *MenuDeInformacion;
    QMenu *MenuDeGraficos;
    //Creacion de acciones dentro de la aplicacion

    QAction *AccionAbrir;
    QList<QAction *> AccionesGuardarComo;
    QAction *AccionSalir;
    QAction *Accioncolor;
    QAction *Accionborrador;
    QAction *Acciongrosor;
    QAction *AccionlimpiarVentana;
    QAction *AccionInformacion;
    QAction *AccionQtInformacion;









};
#endif // MAINWINDOW_H
