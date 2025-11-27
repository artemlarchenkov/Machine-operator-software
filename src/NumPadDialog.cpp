#include "NumPadDialog.h"
#include "ui_NumPadDialog.h"

NumPadDialog::NumPadDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NumPadDialog)
{
    ui->setupUi(this);
}

NumPadDialog::~NumPadDialog()
{
    delete ui;
}
