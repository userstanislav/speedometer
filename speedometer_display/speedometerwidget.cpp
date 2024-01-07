#include "speedometerwidget.h"
#include "display_settings.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QtMath>

SpeedometerWidget::SpeedometerWidget(QWidget *parent) : QWidget(parent), speed_(0) {}

void SpeedometerWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    int const side = width();
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Draw background arc
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
    painter.drawPie(QRectF(0, 0, side, side), 0 * 16, 180 * 16);

    // Draw speedometer arc
    painter.setBrush(Qt::white);
    painter.drawPie(QRectF(5, 5, side - 10, side - 10), 0 * 16, 180 * 16);

    // Draw numbers for every 20 km/h
    painter.setPen(Qt::black);
    QFont font = painter.font();
    font.setPointSize(10);
    painter.setFont(font);
    painter.setRenderHint(QPainter::TextAntialiasing);

    for (int i = 0; i < numSteps + 1; ++i)
    {
        // Starting at 180 degrees and decrementing by degreeStep
        double const degree = 180 - degreeStep * i;
        double const radian = degree * M_PI / 180.0;
        int const x = side / 2 + (side / 2 - 20) * qCos(radian);
        int const y = side / 2 + (side / 2 - 20) * qSin(-radian);
        // Calculate the speed in the opposite direction in degrees
        int const speedNum = maxSpeed - (degree / 15 * speedStep);
        painter.drawText(x - 8, y - 8, QString::number(speedNum));
    }

    // Draw needle
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::black);
    painter.translate(width() / 2, height());
    painter.rotate(180 * speed_ / 240 - 90);
    QPointF const needle[3] = {
        QPointF(-5, 0),
        QPointF(0, -side / 2),
        QPointF(5, 0)};
    painter.drawConvexPolygon(needle, 3);
}

void SpeedometerWidget::setSpeed(int value)
{
    speed_ = value;
    update();
}
