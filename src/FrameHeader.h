#ifndef FRAMEHEADER_H
#define FRAMEHEADER_H

#include <QFrame>

namespace Ui {
class FrameHeader;
}

class FrameHeader : public QFrame
{
    Q_OBJECT

public:
    explicit FrameHeader(QWidget *parent = 0);
    ~FrameHeader();

private:
    Ui::FrameHeader *ui;
};

#endif // FRAMEHEADER_H
