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

#include "program.h"

using namespace opaint;

Program::Program(int argc, char **argv) : QApplication( argc, argv ) {}

Program::~Program()
{
    delete penEvent;
    delete painter;
    delete labelPixmap;
    delete pixmap;
    delete image;
    delete mw;
}

void Program::start()
{
    mw = new ui::MainWindow;
    init();
    mw->show();
}

void Program::init()
{
    initImage();
    initPixmap();
    initDrawingArea();
    initLabelPixmap();
    initPainter();
    initPenEvent();
}

void Program::initImage()
{
    image = new QImage(800, 600, QImage::Format_ARGB32);
    image->fill(Qt::white);
}

void Program::initPixmap()
{
    pixmap = new QPixmap(QPixmap::fromImage(*image));
}

void Program::initDrawingArea()
{
    mw->drawingArea()->setPixmap(*pixmap);
}

void Program::initLabelPixmap()
{
    labelPixmap = new LabelPixmap;
    labelPixmap->setLabel(mw->drawingArea());
    labelPixmap->setPixmap(pixmap);
}

void Program::initPainter()
{
    painter = new QPainter(labelPixmap->pixmap());
}

void Program::initPenEvent()
{
    penEvent = new PenEvent;
    penEvent->setMouse(mw->drawingArea()->mouse());
    penEvent->setMouseButton(mw->drawingArea()->mouse()->leftButton());
    penEvent->setLabelPixmap(labelPixmap);
    penEvent->setPainter(painter);
    penEvent->connect();
}
