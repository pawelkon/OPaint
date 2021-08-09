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

#ifndef OPAINT_TEST_PAINTING_H
#define OPAINT_TEST_PAINTING_H

#include <QTest>

#include <QColor>
#include <QObject>
#include <QPoint>
#include <QLabel>

#include <opaint/ui/ColorWidget>

namespace opaint {
namespace test {

class DrawLine : public QObject
{
    Q_OBJECT

private:
    QColor color;
    QPoint startPoint, endPoint;

    ui::ColorWidget *colorWidget = nullptr;
    QLabel *drawingArea = nullptr;

public:
    explicit DrawLine(QObject *parent = nullptr);

    void setColor(const QColor&);
    void setStartPoint(const QPoint&);
    void setEndPoint(const QPoint&);

    void setColorWidget(ui::ColorWidget*);
    void setDrawingArea(QLabel*);

    void exec();

private:
    QImage prepareRefImage(const QImage&);
    void sendMouseEvents();

signals:

};

} // namespace test
} // namespace opaint

#endif // OPAINT_TEST_PAINTING_H
