#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    speedometer_ = new SpeedometerWidget(this);
    setCentralWidget(speedometer_);

    speedometer_->setSpeed(0);
}

MainWindow::~MainWindow()
{
}

void MainWindow::setSpeed(int value)
{
    speedometer_->setSpeed(value);
}
