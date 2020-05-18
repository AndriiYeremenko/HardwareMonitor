#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "datareciever.h"
#include <QAction>
#include <QGraphicsBlurEffect>
#include <QTime>
#include <QTimer>
#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int const UpdateInterval = 3;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    QPoint mpos;

private slots:

private:
    Ui::MainWindow *ui;
    void startClock();
    void UpdateCpu();
    void UpdateRam();
};
#endif // MAINWINDOW_H
