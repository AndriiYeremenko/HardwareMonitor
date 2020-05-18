#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent,Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint)
    , ui(new Ui::MainWindow)
{
    setAttribute(Qt::WA_TranslucentBackground);
    QAction *quitAction = new QAction(tr("E&xit"), this);
    quitAction->setShortcut(tr("Ctrl+Q"));
    connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);
    addAction(quitAction);
    startClock();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    mpos = event->pos();
}

void MainWindow::startClock()
{
    QTimer *t = new QTimer(this);

    int intervalTick = 0;
    t->setInterval(1000);

    connect(t, &QTimer::timeout, [&]() {
       intervalTick++;
       QString time1 = QTime::currentTime().toString();
       if(intervalTick >= UpdateInterval){
           intervalTick = 0;
           UpdateCpu();
           UpdateRam();
       }
       ui->time->setText(time1);
    } );

       t->start();
}

void MainWindow::UpdateCpu()
{
    datareciever data = *new datareciever();
    int cpu_used_now = data.CPUPercents();
    QString cpu_text = "CPU usage: " + QString::number(cpu_used_now);
    ui->cpu_lbl->setText(cpu_text);
}

void MainWindow::UpdateRam()
{
     //datareciever data = *new datareciever();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
    if (event->buttons() & Qt::LeftButton) {
        QPoint diff = event->pos() - mpos;
        QPoint newpos = this->pos() + diff;

        this->move(newpos);
    }
}

