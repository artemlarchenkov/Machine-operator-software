#include "KeypadLineEdit.h"
#include "NumPadDialog.h"
KeypadLineEdit::KeypadLineEdit(QWidget *parent) :
    QLineEdit(parent)
{
    setReadOnly(true);
}

void KeypadLineEdit::mousePressEvent(QMouseEvent *event)
{
    QLineEdit::mousePressEvent(event);

    NumPadDialog dlg;
    dlg.setModal(true);

    QString cur = this->text();
    this->clear();

    connect(&dlg, &NumPadDialog::digitPressed,
            [this] (const QString &val)
    {
        this->insert(val);
    });

    connect(&dlg, &NumPadDialog::backSpaceClicked, this, [&]() {
        QString t = this->text();
        if (!t.isEmpty())
            t.chop(1);
        this->setText(t);
    });

    connect(&dlg, &NumPadDialog::Onbtn_tochkaClicked, this, [&] () {
        QString cur = this->text();
        if (!cur.contains("."))
            this->setText(cur + ".");
    });

    connect(&dlg, &NumPadDialog::closed, this, [&]() {
        this->setText(cur);
    });

    dlg.exec();
}
