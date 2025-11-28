#ifndef NUMPADDIALOG_H
#define NUMPADDIALOG_H

#include <QDialog>

namespace Ui {
class NumPadDialog;
}

class NumPadDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NumPadDialog(QWidget *parent = 0);
    ~NumPadDialog();
signals:
    void digitPressed(const QString &value);
    void backSpaceClicked();
    void AcceptClicked();
    void Onbtn_tochkaClicked();
    void closed();
private slots:
    void onDigitClicked();
private:
    Ui::NumPadDialog *ui;
};

#endif // NUMPADDIALOG_H
