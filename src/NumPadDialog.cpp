#include "NumPadDialog.h"
#include "ui_NumPadDialog.h"

NumPadDialog::NumPadDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NumPadDialog)
{
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowTitleHint);

    ui->setupUi(this);

    connect(ui->pushButton_43, &QPushButton::clicked,
            [=] () {
        this->close();
    });

//    for (find)
}

NumPadDialog::~NumPadDialog()
{
    delete ui;
}
