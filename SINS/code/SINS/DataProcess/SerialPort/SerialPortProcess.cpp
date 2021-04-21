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
