#ifndef SERIALPORTPROCESS_H
#define SERIALPORTPROCESS_H

#include <QSerialPort>
#include <QSerialPortInfo>

class SerialPortProcess : public QObject
{
public:
    SerialPortProcess();
    QStringList GetCanUsePortNameList();
};

#endif // SERIALPORTPROCESS_H
