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

#ifndef OPAINT_UI_COLORWIDGET_H
#define OPAINT_UI_COLORWIDGET_H

#include <QLabel>
#include <QSlider>
#include <QVBoxLayout>
#include <QWidget>

namespace opaint {
namespace ui {
class ColorWidget : public QWidget
{
    Q_OBJECT

public:
    const static Qt::Orientation sliderOrientation = Qt::Horizontal;
    const static int minSlider = 0;
    const static int maxSlider = 255;

private:
    QHBoxLayout *lay = nullptr;
    QSlider *rSlider = nullptr, *gSlider = nullptr, *bSlider = nullptr;
    QLabel *colView = nullptr;

public:
    explicit ColorWidget(QWidget *parent = nullptr);
    ~ColorWidget();

    QSlider * redSlider();
    QSlider * greenSlider();
    QSlider * blueSlider();
    QLabel * colorView();

    void connect();
    QColor currentColor() const;

    void setSliderValues(int, int, int);

private:
    void setSlider(QSlider*);

private slots:
    void sliderValueChanged(int);
    void updateColorView(QColor);

signals:
    void colorChanged(QColor);

};
} // namespace ui
} // namespace opaint

#endif // OPAINT_UI_COLORWIDGET_H
