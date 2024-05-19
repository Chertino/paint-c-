

#include <QtWidgets>
#include "Proyectopaint.h"

             ProyectoPaint::ProyectoPaint(QWidget *parent) : QWidget(parent), modificado(false), dibujando(false), myPenWidth(1), myPenColor(Qt::black), currentShape(None)
{
    setAttribute(Qt::WA_StaticContents);
}

bool ProyectoPaint::abrirImagen(const QString &fileName){
    QImage loadedImage;
    if(!loadedImage.load(fileName)){
        return false;
    }
    QSize newSize = loadedImage.size().expandedTo(size());
    cambiarTamanoimagen(&loadedImage, newSize);
    image = loadedImage;
    modificado = false;
    update();
    return true;
}

bool ProyectoPaint::guardarImagen(const QString &fileName, const char *fileFormat){
    QImage visibleImage = image;
    cambiarTamanoimagen(&visibleImage, size());
    if(visibleImage.save(fileName, fileFormat)){
        modificado = false;
        return true;
    } else{
        return false;
    }
}

void ProyectoPaint::cambiarBorrador(){
    myPenWidth = 10;
    myPenColor = Qt::white;
}

void ProyectoPaint::cambiarColor(const QColor &newColor){
    myPenColor = newColor;
}

void ProyectoPaint::cambiarGrosor(int newWidth){
    myPenWidth = newWidth;
}

void ProyectoPaint::clearImage(){
    image.fill(qRgb(255, 255, 255));
    modificado = true;
    update();
}

void ProyectoPaint::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        lastPoint = event->pos();
        dibujando = true;
        shapeStartPoint = event->pos();
    }
}

void ProyectoPaint::mouseMoveEvent(QMouseEvent *event){
    if ((event->buttons() & Qt::LeftButton) && dibujando && currentShape == None)
        Trazarlinea(event->pos());
}

void ProyectoPaint::mouseReleaseEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton && dibujando) {
        if (currentShape != None) {
            QPainter painter(&image);
            painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
            drawShape(painter, shapeStartPoint, event->pos());
        } else {
            Trazarlinea(event->pos());
        }
        dibujando = false;
    }
}

void ProyectoPaint::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
}

void ProyectoPaint::resizeEvent(QResizeEvent *event){
    if (width() > image.width() || height() > image.height()) {
        int newWidth = qMax(width() + 128, image.width());
        int newHeight = qMax(height() + 128, image.height());
        cambiarTamanoimagen(&image, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}

void ProyectoPaint::Trazarlinea(const QPoint &endPoint){
    QPainter painter(&image);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.drawLine(lastPoint, endPoint);
    modificado = true;

    int rad = (myPenWidth / 2) + 2;
    update(QRect(lastPoint, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));
    lastPoint = endPoint;
}

void ProyectoPaint::cambiarTamanoimagen(QImage *image, const QSize &newSize){
    if (image->size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

void ProyectoPaint::drawShape(QPainter &painter, const QPoint &startPoint, const QPoint &endPoint){
    switch (currentShape) {
    case Rectangle:
        painter.drawRect(QRect(startPoint, endPoint));
        break;
    case Circle: {
        int radius = qMin(abs(endPoint.x() - startPoint.x()), abs(endPoint.y() - startPoint.y())) / 2;
        painter.drawEllipse(startPoint, radius, radius);
        break;
    }
    case Triangle: {
        QPolygon triangle;
        triangle << startPoint << QPoint(endPoint.x(), startPoint.y()) << QPoint((startPoint.x() + endPoint.x()) / 2, endPoint.y());
        painter.drawPolygon(triangle);
        break;
    }
    case Line:
        painter.drawLine(startPoint, endPoint);
        break;
    default:
        break;
    }
    modificado = true;
    update();
}

void ProyectoPaint::setShape(Shape shape){
    currentShape = shape;
}

