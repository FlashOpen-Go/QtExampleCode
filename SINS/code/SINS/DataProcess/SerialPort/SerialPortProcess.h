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
    Q_OBJECT
public:
    SerialPortProcess();
    QStringList GetCanUsePortNameList();
    void SetPort(QString PortName, unsigned int BaudRate);
    void SetPort(SerialPortInfo info);
    SerialPortInfo GetPortInfo();
    bool Open();
    bool Close();
    bool SendData(QString data);
    QString ReadDate();
    QByteArray ReadData();

signals:
    void ReadyReadData();

protected:
    void run();

private:
    SerialPortInfo m_PortInfo;
    QSerialPort* m_Port;
};

#endif // SERIALPORTPROCESS_H
