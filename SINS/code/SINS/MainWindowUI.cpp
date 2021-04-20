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
