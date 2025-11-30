#ifndef FISRTSCREEN_H
#define FISRTSCREEN_H

#include <QFrame>

namespace Ui {
class FisrtScreen;
}

class FisrtScreen : public QFrame
{
    Q_OBJECT

public:
    explicit FisrtScreen(QWidget *parent = 0);
    ~FisrtScreen();

private:
    Ui::FisrtScreen *ui;
};

#endif // FISRTSCREEN_H
