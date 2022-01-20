#include "buttonswidget.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QComboBox>
#include <QLabel>


ButtonsWidget::ButtonsWidget(QWidget *parent)
    : QWidget{parent}
{
    cameraChooseBox = new QComboBox(this);

    mStartCameraBut = new QPushButton("Start camera", this);
    mStartCameraBut->setStyleSheet( "QPushButton{border: 2px solid blue;}" );

    mPhotoBut = new QPushButton("Make photo", this);
    mPhotoBut->setStyleSheet( "QPushButton{border: 2px solid green;}" );
    mPhotoBut->setEnabled(false);

    mStartRecBut = new QPushButton("Start record", this);
    mStartRecBut->setStyleSheet( "QPushButton{border: 2px solid blue;}" );
    mStartRecBut->setEnabled(false);

    mStopRecBut = new QPushButton("Stop record", this);
    mStopRecBut->setStyleSheet( "QPushButton{border: 2px solid red;}" );
    mStopRecBut->setEnabled(false);

    mStopCameraBut = new QPushButton("Stop camera", this);
    mStopCameraBut->setStyleSheet( "QPushButton{border: 2px solid red;}" );
    mStopCameraBut->setEnabled(false);

    QVBoxLayout* mButtonsLayout = new QVBoxLayout;
    QLabel* lab = new QLabel("Choose Camera Device:", this);

    mButtonsLayout->addWidget(lab, 1, Qt::AlignBottom);
    mButtonsLayout->addWidget(cameraChooseBox, 3);
    mButtonsLayout->addWidget(mStartCameraBut, 3);
    mButtonsLayout->addWidget(mPhotoBut, 3);
    mButtonsLayout->addWidget(mStartRecBut, 3);
    mButtonsLayout->addWidget(mStopRecBut, 3);
    mButtonsLayout->addWidget(mStopCameraBut, 3);

    setLayout(mButtonsLayout);

}
