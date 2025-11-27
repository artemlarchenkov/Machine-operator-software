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

    dlg.exec();

//    if (dlg.exec() == QDialog::Accepted) {
//        setText(dlg.getText());
//    }
}
