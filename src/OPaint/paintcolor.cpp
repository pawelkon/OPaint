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

#include "paintcolor.h"

using namespace opaint;

PaintColor::PaintColor(QObject *parent) : QObject(parent)
{

}

void PaintColor::setColorWidget(ui::ColorWidget *widget)
{
    colWidget = widget;
}

void PaintColor::setPen(QPen *pen) { this->pen = pen; }

void PaintColor::setBrush(QBrush *brush) { this->brush = brush; }

void PaintColor::connect()
{
    if(ptrcheck(colWidget))
        QObject::connect(colWidget, &ui::ColorWidget::colorChanged, this, &PaintColor::changeColor);
}

void PaintColor::changeColor(QColor color)
{
    if(ptrcheck(pen))
        pen->setColor(color);

    if(ptrcheck(brush))
        brush->setColor(color);
}
