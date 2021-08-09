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

#include "ts_drawingarea.h"
#include "ts_drawline.h"

namespace opaint {
namespace test {

DrawingArea::DrawingArea()
{

}

void DrawingArea::DrawLine(QColor color, QPoint start = QPoint(5,5), QPoint end = QPoint(50,50))
{
    class DrawLine dl;
    dl.setColor(color);
    dl.setStartPoint(start);
    dl.setEndPoint(end);
    dl.setColorWidget(progTest.program()->mainWindow()->colorWidget());
    dl.setDrawingArea(progTest.program()->mainWindow()->drawingArea());
    dl.exec();
}

void DrawingArea::initTestCase()
{
    progTest.start();
}

void DrawingArea::drawBlackLine() { DrawLine(Qt::black); }

void DrawingArea::drawWhiteLine() { DrawLine(Qt::white); }

void DrawingArea::drawRedLine() { DrawLine(Qt::red); }

void DrawingArea::drawGreenLine() { DrawLine(Qt::green); }

void DrawingArea::drawBlueLine() { DrawLine(Qt::blue); }

} // namespace test
} // namespace opaint

QTEST_APPLESS_MAIN(opaint::test::DrawingArea);
