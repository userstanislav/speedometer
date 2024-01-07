#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "speedometerwidget.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    SpeedometerWidget *speedometer_;

public slots:
    void setSpeed(int value);
};
#endif // MAINWINDOW_H
