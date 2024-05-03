#include <QtWidgets>
#include "Proyectopaint.h"

ProyectoPaint::ProyectoPaint(QWidget *parent) : QWidget (parent)
{

    setAttribute(Qt::WA_StaticContents);
    modificado = false;
    dibujando = false;
    myPenWidth = 1;
    myPenColor = Qt::black;
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

bool ProyectoPaint::guardarImagen(const QString &fileName,const char *fileFormat){
    QImage visibleImage = image;
    cambiarTamanoimagen(&visibleImage, size());
    if(visibleImage.save(fileName, fileFormat)){
        modificado = false;
        return true;
    } else{
        return false;
    }

}

void ProyectoPaint::cambiarColor(const QColor &newColor){
    myPenColor = newColor;

}

void ProyectoPaint::cambiarGrosor(int newWidth){
    myPenWidth = newWidth;
}

void ProyectoPaint::clearImage(){
    image.fill(qRgb(255,255,255));
    modificado = true;
    update();

}

void ProyectoPaint::mousePressEvent(QMouseEvent *event){
    if(event->button()== Qt::LeftButton){
        lastPoint = event->pos();
        dibujando = true;
    }
}

void ProyectoPaint::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && dibujando)
        Trazarlinea(event->pos());
}

// Si se suelta el botón configuramos variables para dejar de dibujar.
void ProyectoPaint::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && dibujando) {
        Trazarlinea(event->pos());
        dibujando = false;
    }
}

// QPainter proporciona funciones para dibujar en el widget
// El QPaintEvent se envía a los widgets que necesitan
// actualizarse
void ProyectoPaint::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // Devuelve el rectangulo que necesita ser actualizado
    QRect dirtyRect = event->rect();

    // Dibuja el rectangulo en donde la imagen necesita
    // ser actualizada
    painter.drawImage(dirtyRect, image, dirtyRect);
}

// Cambie el tamaño de la imagen para que sea un poco más grande que la ventana principal
// para reducir la necesidad de cambiar el tamaño de la imagen
void ProyectoPaint::resizeEvent(QResizeEvent *event)
{
    if (width() > image.width() || height() > image.height()) {
        int newWidth = qMax(width() + 128, image.width());
        int newHeight = qMax(height() + 128, image.height());
        cambiarTamanoimagen(&image, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}

void ProyectoPaint::Trazarlinea(const QPoint &endPoint)
{
    // Se usa para dibujar en el widget
    QPainter painter(&image);

    // Configurar la configuración actual del lápiz.
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));

    // Dibuja una línea desde el último punto registrado hasta el actual
    painter.drawLine(lastPoint, endPoint);

    // Establecer que la imagen no ha sido guardada
    modificado = true;

    int rad = (myPenWidth / 2) + 2;

    // Call to update the rectangular space where we drew
    update(QRect(lastPoint, endPoint).normalized()
               .adjusted(-rad, -rad, +rad, +rad));

    // Llama para actualizar el espacio rectangular donde dibujamos.
    lastPoint = endPoint;
}

// Cuando se cambia el tamaño de la aplicación, cree una nueva imagen usando
// los cambios realizados en la imagen
void ProyectoPaint::cambiarTamanoimagen(QImage *image, const QSize &newSize)
{
    // Comprueba si necesitamos volver a dibujar la imagen.
    if (image->size() == newSize)
        return;

    // Crea una nueva imagen blanca para rellenar el espacio
    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));

    // dibuja la imagen
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}



