#ifndef SPEEDOMETERWIDGET_H
#define SPEEDOMETERWIDGET_H

#include <QWidget>

class SpeedometerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SpeedometerWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int speed_;

public slots:
    void setSpeed(int value);
};

#endif // SPEEDOMETERWIDGET_H
