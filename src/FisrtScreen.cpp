#include "FisrtScreen.h"
#include "ui_FisrtScreen.h"
#include <QTimer>

FisrtScreen::FisrtScreen(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FisrtScreen)
{
    ui->setupUi(this);

    ui->frame_MainImage->setObjectName("Image_First_Screen");
    ui->frame_MainImage->setStyleSheet("");
    ui->frame_MainImage->setFixedSize(972, 688);

    connect(ui->pushButton_3, &QPushButton::clicked,
            this, &FisrtScreen::onPushButtonPoroschokClicked);
//    connect(ui->botton_up, &Q)
}

FisrtScreen::~FisrtScreen()
{
    delete ui;
}

void FisrtScreen::onPushButtonPoroschokClicked()
{
    emit signalPushButtonPoroschokClicked();

    QTimer::singleShot(15000, [=](){
        emit signalPushButtonPoroschokStop();
    });
}
