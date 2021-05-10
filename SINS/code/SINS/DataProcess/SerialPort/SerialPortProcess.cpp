#include "SerialPortProcess.h"

SerialPortProcess::SerialPortProcess()
{

}

/**
 * @brief SerialPortProcess::GetCanUsePortNameList : 获取当前系统可使用的串口列表
 * @return ： 返回列表
 */
QStringList SerialPortProcess::GetCanUsePortNameList()
{
    QStringList Temp_Ret_List;
    QSerialPort Temp_Seach_Port;
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        Temp_Seach_Port.setPort(info);
        if (Temp_Seach_Port.open(QIODevice::ReadWrite))
        {
            Temp_Ret_List.append(info.portName());
            Temp_Seach_Port.close();
        }
    }
    return Temp_Ret_List;
}

/**
 * @brief SerialPortProcess::SetPort :设置串口的相关参数
 * @param PortName
 * @param BaudRate
 */
void SerialPortProcess::SetPort(QString PortName, unsigned int BaudRate)
{
    if (!PortName.isEmpty())
        m_PortInfo.m_PortName = PortName;
    m_PortInfo.m_BaudRate = BaudRate;
}

/**
 * @brief SerialPortProcess::SetPort : 设置串口的相关参数
 * @param info
 */
void SerialPortProcess::SetPort(SerialPortInfo info)
{
    m_PortInfo.m_BaudRate = info.m_BaudRate;
    m_PortInfo.m_PortName = info.m_PortName;
}

/**
 * @brief SerialPortProcess::GetPortInfo : 获取串口的相关参数
 * @return
 */
SerialPortInfo SerialPortProcess::GetPortInfo()
{
    return m_PortInfo;
}

/**
 * @brief SerialPortProcess::Open ： 打开串口
 * @return 返回打开是否成功
 */
bool SerialPortProcess::Open()
{
    if(!m_PortInfo.m_PortName.isEmpty() && m_PortInfo.m_BaudRate != 0)
    {

    }
    return false;
}

/**
 * @brief SerialPortProcess::Close
 * @return
 */
bool SerialPortProcess::Close()
{
    bool ret = true;

    return ret;
}

/**
 * @brief SerialPortProcess::SendData
 * @param data
 * @return
 */
bool SerialPortProcess::SendData(QString data)
{
    bool ret = true;

    return ret;
}

/**
 * @brief SerialPortProcess::ReadDate
 * @return
 */
QString SerialPortProcess::ReadDate()
{
    QString Temp_Ret_Data;
    return Temp_Ret_Data;
}

/**
 * @brief SerialPortProcess::ReadData
 * @return
 */
QByteArray SerialPortProcess::ReadData()
{
    QByteArray Temp_data;
    return Temp_data;
}

/**
 * @brief SerialPortProcess::run
 */
void SerialPortProcess::run()
{
    m_Port = new QSerialPort();
    QSerialPortInfo Temp_Set_Port_Info;
//    m_Port->setPort()
    while(!isInterruptionRequested())
    {

    }
}
