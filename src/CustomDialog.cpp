#include "CustomDialog.h"
#include "ui_CustomDialog.h"

CustomDialog::CustomDialog(const QString &title, const QString &message, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomDialog)
{
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowTitleHint);
    ui->setupUi(this);

    ui->title->setText(title);
    ui->message->setText(message);

    connect(ui->pushButton_understand, &QPushButton::clicked,
            this, &CustomDialog::onPushButtonUnderstandClicked);

    connect(ui->pushButton, &QPushButton::clicked, [=]() {
        emit onpushButton_understandClicked();
        this->close();
    });
}

CustomDialog::~CustomDialog()
{
    delete ui;
}

void CustomDialog::onPushButtonUnderstandClicked()
{
    this->close();
}
