#ifndef SERIALPORTPROCESS_H
#define SERIALPORTPROCESS_H

#include <QThread>
#include <QSerialPort>
#include <QSerialPortInfo>

class SerialPortInfo
{
public:
    QString m_PortName;
    unsigned int m_BaudRate;
    SerialPortInfo(){m_PortName = "";m_BaudRate = 115200;}
};

//class SerialPortProcess : public QObject
class SerialPortProcess : public QThread
{
public:
    SerialPortProcess();
    QStringList GetCanUsePortNameList();

protected:
    void run();

private:
    SerialPortInfo m_PortInfo;
    QSerialPort* m_Port;
};

#endif // SERIALPORTPROCESS_H
