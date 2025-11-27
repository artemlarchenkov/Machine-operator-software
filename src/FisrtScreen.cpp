#include "FisrtScreen.h"
#include "ui_FisrtScreen.h"

FisrtScreen::FisrtScreen(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FisrtScreen)
{
    ui->setupUi(this);

    ui->frame_MainImage->setObjectName("Image_First_Screen");
    ui->frame_MainImage->setStyleSheet("");
    ui->frame_MainImage->setFixedSize(972, 688);
}

FisrtScreen::~FisrtScreen()
{
    delete ui;
}
