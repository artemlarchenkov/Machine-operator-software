#ifndef DIGITALKEYBOARD_H
#define DIGITALKEYBOARD_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class DigitalKeyboard;
}

class DigitalKeyboard : public QDialog
{
    Q_OBJECT

public:
    explicit DigitalKeyboard(QWidget *parent = 0);
    ~DigitalKeyboard();

private:
    Ui::DigitalKeyboard *ui;
};

#endif // DIGITALKEYBOARD_H
