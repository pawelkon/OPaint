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

#include "drawlinetest.h"
#include "gui.h"

Gui::Gui() {}

Gui::~Gui()
{
    delete prog;
}

void Gui::start(int argc, char **argv)
{
    prog = new opaint::Program( argc, argv);
    prog->start();
}

void Gui::ColorChoice()
{
    class ColorChoice cch(prog->mainWindow()->colorWidget());
    cch.test();
}

void Gui::drawLine(const QColor &color)
{
    DrawLineTest test;
    test.setLabel(prog->mainWindow()->drawingArea());
    test.setColorWidget(prog->mainWindow()->colorWidget());
    test.setColor(color);
    test.exec();
}

void Gui::drawBlackLine() { drawLine(Qt::black); }

void Gui::drawRedLine() { drawLine(Qt::red); }

void Gui::drawGreenLine() { drawLine(Qt::green); }

void Gui::drawBlueLine() { drawLine(Qt::blue); }

void Gui::drawWhiteLine() { drawLine(Qt::white); }

int main(int argc, char** argv)
{
    Gui m;
    m.start( argc, argv );
    return QTest::qExec( &m, argc, argv );
}

