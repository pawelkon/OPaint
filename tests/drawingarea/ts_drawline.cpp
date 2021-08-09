/*******************************************************************************
MIT License

Copyright (c) 2021 pawelkon

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
********************************************************************************/

#include "ts_drawline.h"

#include <QApplication>
#include <QMouseEvent>
#include <QPainter>

namespace opaint {
namespace test {

DrawLine::DrawLine(QObject *parent) : QObject(parent)
{

}

void DrawLine::setColor(const QColor &color)
{
    this->color = color;
}

void DrawLine::setStartPoint(const QPoint &point)
{
    startPoint = point;
}

void DrawLine::setEndPoint(const QPoint &point)
{
    endPoint = point;
}

void DrawLine::setColorWidget(ui::ColorWidget *widget)
{
    colorWidget = widget;
}

void DrawLine::setDrawingArea(QLabel *label)
{
    drawingArea = label;
}

void DrawLine::exec()
{
    colorWidget->setColor(color);

    auto daImage = drawingArea->pixmap()->toImage();
    auto refImage = prepareRefImage(daImage);

    sendMouseEvents();
    daImage = drawingArea->pixmap()->toImage();

    QCOMPARE(daImage, refImage);
}

QImage DrawLine::prepareRefImage(const QImage &original)
{
    QImage img(original);

    QPainter p;
    p.begin(&img);
    p.setPen(color);
    p.setBrush(color);
    p.drawLine(startPoint, endPoint);
    p.end();

    return img;
}

void DrawLine::sendMouseEvents()
{
    QMouseEvent press(QEvent::MouseButtonPress, startPoint, Qt::NoButton, Qt::LeftButton, Qt::NoModifier);
    QApplication::sendEvent(drawingArea, &press);

    QMouseEvent move(QEvent::MouseMove, endPoint, Qt::NoButton, Qt::LeftButton, Qt::NoModifier);
    QApplication::sendEvent(drawingArea, &move);
}

} // namespace test
} // namespace opaint
