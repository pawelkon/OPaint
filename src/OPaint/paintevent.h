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

#ifndef OPAINT_ABSTRACTPAINTEVENT_H
#define OPAINT_ABSTRACTPAINTEVENT_H

#include <QObject>

#include <opaint/Mouse>
#include <opaint/MouseButton>
#include <opaint/LabelPixmap>

namespace opaint {
class PaintEvent : public QObject
{
    Q_OBJECT

private:
    const Mouse *mous = nullptr;
    const MouseButton *mousBtn = nullptr;
    LabelPixmap *lblpix = nullptr;

public:
    void setMouse(const Mouse*);
    void setMouseButton(const MouseButton*);
    void setLabelPixmap(LabelPixmap*);

    virtual void connect() = 0;

protected:
    explicit PaintEvent(QObject *parent = nullptr);

    const Mouse * mouse();
    const MouseButton * mouseButton();
    LabelPixmap * labelPixmap();

signals:

};
} // namespace opaint

#endif // OPAINT_ABSTRACTPAINTEVENT_H
