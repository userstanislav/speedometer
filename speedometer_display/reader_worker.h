#ifndef READERWORKER_H
#define READERWORKER_H

#include "ipc_reader.h"
#include "ipc_settings.h"
#include <QObject>

class ReaderWorker : public QObject
{
    Q_OBJECT

public slots:
    void startReading()
    {
        IPCReader reader{speedometer_data_init, fps, [this](int value)
                         {
                             emit speedChanged(value);
                         }};
        reader.receiveMessages();
    }

signals:
    void speedChanged(int value);
};

#endif // READERWORKER_H
