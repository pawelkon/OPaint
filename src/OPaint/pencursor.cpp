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

#include "pencursor.h"

using namespace opaint;

PenCursor::PenCursor(QObject *parent) : QObject(parent)
{
    size = QSize( 10, 10 );
}

void PenCursor::setWidget(QWidget *widget) { widg = widget; }

void PenCursor::changeColor(const QColor &color)
{
    this->color = color;
    repaint();
}

void PenCursor::changeSize(const QSize &size)
{
    this->size = size;
    repaint();
}

void PenCursor::repaint()
{
    QImage img(size, QImage::Format_ARGB32);
    img.fill(color);

    QCursor cur( QPixmap::fromImage(img) );

    if(ptrcheck(widg))
        widg->setCursor(cur);
}
