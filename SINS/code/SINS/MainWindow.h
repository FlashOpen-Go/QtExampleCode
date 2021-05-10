#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DataProcess/SerialPort/SerialPortProcess.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    bool Init();
    bool UIInit();
    bool SerialPortUIInit();
    bool SetUIInit();
    bool SerialPortInit();

    ~MainWindow();

private slots:
    void onOpenBtnClicked();
    void onReLoadBtnClicked();

private:
    Ui::MainWindow *ui;
    SerialPortProcess m_Port;
};

#endif // MAINWINDOW_H
