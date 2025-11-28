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

    connect(ui->pushButton_up, &QPushButton::clicked,
            this, &FisrtScreen::onBtnUpClicked);
    connect(ui->pushButton_down, &QPushButton::clicked,
            this, &FisrtScreen::onBtnDownClicked);
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

void FisrtScreen::onBtnUpClicked()
{
    bool ok;

    double step = ui->step->text().toDouble(&ok);
    if(!ok || step <= 0.0) step = 0.01;

    double value = ui->label_abs_->text().toDouble(&ok);
    if (!ok) value = 0.0;

    value -= step;
    ui->label_abs_->setText(QString::number(value, 'f', 3));
}

void FisrtScreen::onBtnDownClicked()
{
    bool ok;

    double step = ui->step->text().toDouble(&ok);
    if(!ok || step <= 0.0) step = 0.01;

    double value = ui->label_abs_->text().toDouble(&ok);
    if (!ok) value = 0.0;

    value += step;
    ui->label_abs_->setText(QString::number(value, 'f', 3));
}
