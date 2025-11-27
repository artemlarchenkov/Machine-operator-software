#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDir>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->frame_header_2->setFixedSize(1922, 76);

    connect(ui->frame_firstScreen, &FisrtScreen::signalPushButtonPoroschokClicked,
            ui->frame_buttom, &FrameBottom::showloading);
    connect(ui->frame_firstScreen, &FisrtScreen::signalPushButtonPoroschokStop,
            ui->frame_buttom, &FrameBottom::stoploading);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init(QApplication *_app)
{
    move(0,0);

    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
//    show();
//    showMaximized();
    showFullScreen();

    QFile file(QCoreApplication::applicationDirPath()+ QString("/styles/AllFrames.css"));
    if(file.open(QFile::ReadOnly))
    {
        QTextStream stream(&file);
        QString styleSheet = stream.readAll();
        this->setStyleSheet(styleSheet);
        file.close();
    }
}


