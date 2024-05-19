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
    enum Shape { None, Rectangle, Circle, Triangle, Line };

    ProyectoPaint(QWidget *parent = 0);
    bool abrirImagen(const QString &fileName);
    bool guardarImagen(const QString &fileName, const char *fileFormat);
    void cambiarColor(const QColor &newColor);
    void cambiarGrosor(int newWidth);
    bool modificaciones() const { return modificado; }
    QColor color() const { return myPenColor; }
    int grosor() const { return myPenWidth; }
    void setShape(Shape shape);

public slots:
    void clearImage();
    void cambiarBorrador();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void Trazarlinea(const QPoint &endPoint);
    void cambiarTamanoimagen(QImage *image, const QSize &newSize);
    void drawShape(QPainter &painter, const QPoint &startPoint, const QPoint &endPoint);

    bool modificado;
    bool dibujando;
    int myPenWidth;
    QColor myPenColor;
    QImage image;
    QPoint lastPoint;
    Shape currentShape;
    QPoint shapeStartPoint;
};

#endif // PROYECTOPAINT_H
