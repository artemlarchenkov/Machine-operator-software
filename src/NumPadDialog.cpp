#include "NumPadDialog.h"
#include "ui_NumPadDialog.h"
#include <QDebug>

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

    auto digitButtons = ui->frame_buttons->findChildren<QPushButton*>(QRegularExpression("^btn_[0-9]$"));
    for (auto btn : digitButtons) {
            connect(btn,  &QPushButton::clicked, this, &NumPadDialog::onDigitClicked);
    }

    connect(ui->button_delete_symbol, &QPushButton::clicked, this, &NumPadDialog::backSpaceClicked);
    connect(ui->btn_okey, &QPushButton::clicked, this, &NumPadDialog::accept);
    connect(ui->btn_tochka, &QPushButton::clicked, this, &NumPadDialog::Onbtn_tochkaClicked);
    connect(ui->btn_not__okey, &QPushButton::clicked, this, &NumPadDialog::closed);
}

NumPadDialog::~NumPadDialog()
{
    delete ui;
}

void NumPadDialog::onDigitClicked()
{
    auto btn = qobject_cast<QPushButton*>(sender());
    if (!btn) return;

    QString digit = btn->text();

    emit digitPressed(digit);
}
