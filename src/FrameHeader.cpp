#include "FrameHeader.h"
#include "ui_FrameHeader.h"

FrameHeader::FrameHeader(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FrameHeader)
{
    ui->setupUi(this);

    ui->label->setObjectName("label_header");
    ui->label->setStyleSheet("");
    ui->label_time->setObjectName("label_header");
    ui->label_time->setStyleSheet("");
    ui->frame_info->setObjectName("frame_info");
    ui->frame_info->setStyleSheet("");
    ui->frame_info->setFixedSize(25,25);

}

FrameHeader::~FrameHeader()
{
    delete ui;
}
