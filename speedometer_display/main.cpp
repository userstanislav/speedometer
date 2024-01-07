#include "ipc_reader.h"
#include "ipc_settings.h"
#include "mainwindow.h"
#include "reader_worker.h"
#include "display_settings.h"
#include <QApplication>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w{};
    w.setFixedSize(windowWidth, windowHeight);
    w.show();

    QThread workerThread{};
    ReaderWorker worker = ReaderWorker();
    worker.moveToThread(&workerThread);

    QObject::connect(&workerThread, &QThread::started, &worker, &ReaderWorker::startReading);
    QObject::connect(&worker, &ReaderWorker::speedChanged, &w, &MainWindow::setSpeed);

    workerThread.start();

    int const exit_code = a.exec();

    // TODO (fix): It will not finish by closing window, only by process termination
    workerThread.quit();
    workerThread.wait();

    return exit_code;
}

#include "main.moc"
