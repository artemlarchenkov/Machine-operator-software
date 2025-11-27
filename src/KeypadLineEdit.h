#ifndef KEYPADLINEEDIT_H
#define KEYPADLINEEDIT_H

#include <QObject>
#include <QLineEdit>

class KeypadLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit KeypadLineEdit(QWidget* parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // KEYPADLINEEDIT_H
