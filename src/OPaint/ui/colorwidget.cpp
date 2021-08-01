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

    redSlider = new QSlider();
    setSlider(redSlider);

    greenSlider = new QSlider();
    setSlider(greenSlider);

    blueSlider = new QSlider();
    setSlider(blueSlider);

    colorView = new QLabel;
    colorView->setMinimumSize(30,30);
    colorView->setMaximumSize(30,30);
    updateColorView(currentColor());
    lay->addWidget(colorView);

    connect();
}

ColorWidget::~ColorWidget()
{
    delete colorView;

    delete blueSlider;
    delete greenSlider;
    delete redSlider;

    delete lay;
}

void ColorWidget::connect()
{
    QObject::connect(redSlider, &QSlider::valueChanged, this, &ColorWidget::sliderValueChanged);
    QObject::connect(greenSlider, &QSlider::valueChanged, this, &ColorWidget::sliderValueChanged);
    QObject::connect(blueSlider, &QSlider::valueChanged, this, &ColorWidget::sliderValueChanged);
}

QColor ColorWidget::currentColor() const
{
    auto red = redSlider->value();
    auto green = greenSlider->value();
    auto blue = blueSlider->value();

    QColor color(red, green, blue);
    return color;
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
    colorView->setStyleSheet(QString("background-color: rgb(%1, %2, %3)")
                             .arg(color.red())
                             .arg(color.green())
                             .arg(color.blue())
                            );
}
