#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::Init : 软件整体初始化函数
 * @return ： 是否完成整体初始化
 */
bool MainWindow::Init()
{
    bool ret = true;

    ret &= UIInit();
    ret &= SerialPortInit();
    ret &= SerialPortUIInit();

    return ret;
}

/**
 * @brief MainWindow::UIInit : UI 界面部分初始化
 * @return ： 是否执行成功
 */
bool MainWindow::UIInit()
{
   bool ret = true;
   ui->ReceiveText->setReadOnly(true);
   ui->SerialPortNameLabel->setText("ComNum");
   ui->OpenBtn->setText("OpenCom");
   ui->OpenStatusLabel->setText("+");
   ui->ReLoadBtn->setText("RL");
   ui->MoreSetBtn->setText("MoreSet");
   ui->BaudRateLabel->setText("BaudRate");
   ui->SendBtn->setText("Send");
   ui->isShowHexCbox->setText("showHEX");
   ui->isSendByHexCbox->setText("SendByHEX");
   ui->isSendInTimeCbox->setText("SendEvery");
   ui->SendTimeLedt->setText("10");
   ui->TimeLabel->setText("ms/Time");
   ui->isAddCrLf->setText("AddCrLf");
   ui->isShowTimeAndPackeCbox->setText("ShowTimeAndPacke");
   ui->OverTimeLabel->setText("OverTime:");
   ui->OverTimeLedit->setText("20");

   return ret;
}

/**
 * @brief MainWindow::SerialPortInit : 串口部分信息初始化
 * @return 是否初始化成功
 */
bool MainWindow::SerialPortInit()
{
    bool ret = true;
    QStringList Temp_Port_List = m_Port.GetCanUsePortNameList();
    ui->SerialPortCbx->addItems(Temp_Port_List);
    return ret;
}

/**
 * @brief MainWindow::SerialPortUIInit : 串口打开设置相关UI界面初始化，并连接相关槽函数
 * @return
 */
bool MainWindow::SerialPortUIInit()
{
    bool ret = true;
    QStringList Temp_BaudRateList;
    Temp_BaudRateList.append("115200");
    Temp_BaudRateList.append("460800");
    ui->BaudRateCbx->addItems(Temp_BaudRateList);
    connect(ui->OpenBtn, &QPushButton::clicked, this, &MainWindow::onOpenBtnClicked);
    connect(ui->ReLoadBtn, &QPushButton::clicked, this, &MainWindow::onReLoadBtnClicked);
    return ret;
}

/**
 * @brief MainWindow::SetUIInit : 数据接收和发送部分相关设置UI初始化
 * @return
 */
bool MainWindow::SetUIInit()
{
    bool ret = true;

    return ret;
}
