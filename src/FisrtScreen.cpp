#include "FisrtScreen.h"
#include "FisrtScreen.h"
#include "ui_FisrtScreen.h"
#include <QTimer>

FisrtScreen::FisrtScreen(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FisrtScreen)
{
    ui->setupUi(this);

    // Инициализация стилей
    ui->pushButton_poroshok->setProperty("hover", false);
    updateButtonStyle(); // Вызов функции обновления стиля

    ui->frame_MainImage->setObjectName("Image_First_Screen");
    ui->frame_MainImage->setStyleSheet("");
    ui->frame_MainImage->setFixedSize(972, 688);

    connect(ui->pushButton_poroshok, &QPushButton::clicked,
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

void FisrtScreen::updateButtonStyle()
{
    bool isHover = ui->pushButton_poroshok->property("hover").toBool();

    if (isHover) {
        ui->pushButton_poroshok->setStyleSheet(
            "QPushButton {"
            "   background-color: #E6E7EC;"  // цвет при hover
            "   color: #4D505F;"
            "   border: 2px solid #E6E7EC;"
            "}"
        );
    } else {
        ui->pushButton_poroshok->setStyleSheet(
            "QPushButton {"
            "   background-color: #81869F;"  // цвет по умолчанию
            "   color: #FFFFFF;"
            "   border: 2px solid #81869F;"
            "}"
        );
    }
}

void FisrtScreen::onPushButtonPoroschokClicked()
{
    emit signalPushButtonPoroschokClicked();
    ui->pushButton_poroshok->setProperty("hover", true);
    updateButtonStyle(); // Обновляем стиль

    QTimer::singleShot(15000, this, [this]() {
        ui->pushButton_poroshok->setProperty("hover", false);
        updateButtonStyle(); // Возвращаем исходный стиль
        emit signalPushButtonPoroschokStop();
    });
}

void FisrtScreen::onBtnUpClicked()
{
    bool ok;

    double step = ui->step->text().toDouble(&ok);
    if(!ok || step <= 0.0) step = 0.00;

    double value = ui->label_abs_->text().toDouble(&ok);
    if (!ok) value = 0.0;

    value -= step;
    ui->label_abs_->setText(QString::number(value, 'f', 3));
}

void FisrtScreen::onBtnDownClicked()
{
    bool ok;

    double step = ui->step->text().toDouble(&ok);
    if(!ok || step <= 0.0) step = 0.00;

    double value = ui->label_abs_->text().toDouble(&ok);
    if (!ok) value = 0.0;

    value += step;
    ui->label_abs_->setText(QString::number(value, 'f', 3));
}
