#include "DigitalKeyboard.h"
#include "ui_DigitalKeyboard.h"

DigitalKeyboard::DigitalKeyboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DigitalKeyboard)
{
    ui->setupUi(this);
}

DigitalKeyboard::~DigitalKeyboard()
{
    delete ui;
}
