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

#include "colorwidget.h"

using namespace opaint::ui;

ColorWidget::ColorWidget(QWidget *parent) : QWidget(parent)
{
    this->setMinimumSize(500,50);
    this->setMaximumSize(500,50);

    lay = new QHBoxLayout;
    setLayout(lay);

    rSlider = new QSlider();
    setSlider(rSlider);

    gSlider = new QSlider();
    setSlider(gSlider);

    bSlider = new QSlider();
    setSlider(bSlider);

    colView = new QLabel;
    colView->setMinimumSize(30,30);
    colView->setMaximumSize(30,30);
    updateColorView(currentColor());
    lay->addWidget(colView);

    connect();
}

ColorWidget::~ColorWidget()
{
    delete colView;

    delete bSlider;
    delete gSlider;
    delete rSlider;

    delete lay;
}

QSlider * ColorWidget::redSlider() { return rSlider; }

QSlider * ColorWidget::greenSlider() { return gSlider; }

QSlider * ColorWidget::blueSlider() { return bSlider; }

QLabel * ColorWidget::colorView() { return colView; }

void ColorWidget::connect()
{
    QObject::connect(rSlider, &QSlider::valueChanged, this, &ColorWidget::sliderValueChanged);
    QObject::connect(gSlider, &QSlider::valueChanged, this, &ColorWidget::sliderValueChanged);
    QObject::connect(bSlider, &QSlider::valueChanged, this, &ColorWidget::sliderValueChanged);
}

QColor ColorWidget::currentColor() const
{
    auto red = rSlider->value();
    auto green = gSlider->value();
    auto blue = bSlider->value();

    QColor color(red, green, blue);
    return color;
}

void ColorWidget::setSliderValues(int red, int green, int blue)
{
    rSlider->setValue(red);
    gSlider->setValue(green);
    bSlider->setValue(blue);
}

void ColorWidget::setSlider(QSlider *slider)
{
    slider->setOrientation(sliderOrientation);
    slider->setMinimum(minSlider);
    slider->setMaximum(maxSlider);

    this->lay->addWidget(slider);
}

void ColorWidget::sliderValueChanged(int)
{
    updateColorView(currentColor());
    emit colorChanged(currentColor());
}

void ColorWidget::updateColorView(QColor color)
{
    colView->setStyleSheet(QString("background-color: rgb(%1, %2, %3)")
                             .arg(color.red())
                             .arg(color.green())
                             .arg(color.blue())
                            );
}
