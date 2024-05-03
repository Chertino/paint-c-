#ifndef PROYECTOPAINT_H
#define PROYECTOPAINT_H

#include <QPoint>
#include <QColor>
#include <QImage>
#include <QWidget>
class ProyectoPaint : public QWidget
{
   Q_OBJECT

public:
   ProyectoPaint(QWidget *parent = 0);
    bool abrirImagen(const QString &fileName);
    bool guardarImagen(const QString &fileName, const char *fileFormat);
    void cambiarColor(const QColor &newColor);
    void cambiarGrosor(int newWidth);

    // Funcion para saber que hacer con el archivo si el usuario cierra el programa
    bool modificaciones() const {return modificado;}
    QColor color() const {return myPenColor;}
    int grosor() const {return myPenWidth;}


public slots:
    void clearImage();


protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void Trazarlinea(const QPoint &endPoint);
    void cambiarTamanoimagen(QImage *image, const QSize &newSize);
    //Hay cambios en el programa
    bool modificado;

    //El usuario está dibujando
    bool dibujando;
    int myPenWidth;
    QColor myPenColor;
    QImage image;
    QPoint lastPoint;

};


#endif // PROYECTOPAINT_H
