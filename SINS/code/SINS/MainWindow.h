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
    bool SerialPortInit();

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SerialPortProcess m_Port;
};

#endif // MAINWINDOW_H
