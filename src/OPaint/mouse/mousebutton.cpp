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

#include "mousebutton.h"

using namespace opaint;

MouseButton::MouseButton(QObject *parent) : QObject(parent)
{

}

MouseButton::MouseButton(const Qt::MouseButton &button)
{
    this->button = button;
}

bool MouseButton::isPressed()
{
    return buttonPress;
}

bool MouseButton::eventFilter(QObject *obj, QEvent *ev)
{
    pressEventFilter(ev);
    releaseEventFilter(ev);

    return QObject::eventFilter( obj, ev );
}

void MouseButton::pressEventFilter(QEvent *ev)
{
    if(ev->type() == QEvent::MouseButtonPress)
        properPressed(static_cast<QMouseEvent*>(ev));
}

void MouseButton::releaseEventFilter(QEvent *ev)
{
    if(ev->type() == QEvent::MouseButtonPress)
        properReleased(static_cast<QMouseEvent*>(ev));
}

void MouseButton::properPressed(QMouseEvent *ev)
{
    if(ev->buttons() == button)
    {
        buttonPress = true;
        emit pressed(ev);
    }
}

void MouseButton::properReleased(QMouseEvent *ev)
{
    if(ev->buttons() == button)
    {
        buttonPress = false;
        emit released(ev);
    }
}
