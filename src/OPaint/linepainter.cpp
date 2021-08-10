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

#include "linepainter.h"

using namespace opaint;

LinePainter::LinePainter(QObject *parent) : PaintEvent(parent)
{

}

void LinePainter::connect()
{
    QObject::connect(mouseButton(), &MouseButton::pressed, this, &LinePainter::drawDot);
    QObject::connect(mouse(), &Mouse::moveEvent, this, &LinePainter::drawLine);
}

void LinePainter::drawDot(QMouseEvent *ev)
{
    startingPoint = ev->localPos();

    if(ptrcheck(painter())) painter()->drawPoint(startingPoint);

    if(ptrcheck(labelPixmap())) labelPixmap()->update();
}

void LinePainter::drawLine(QMouseEvent *ev)
{
    if(ptrcheck(mouseButton()) && ev->buttons() == mouseButton()->qtButton())
    {
        if(ptrcheck(painter())) painter()->drawLine(startingPoint, ev->localPos());

        startingPoint = ev->localPos();
        if(ptrcheck(labelPixmap())) labelPixmap()->update();
    }
}
