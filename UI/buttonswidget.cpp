#include "buttonswidget.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QComboBox>
#include <QLabel>

QString buttonStyle = "QPushButton {\n"
                      "background-color: green;\n"
                      "border-style: outset;\n"
                      "border-width: 2px;\n"
                      "border-radius: 10px;\n"
                      "border-color: beige;\n"
                      "font: bold 14px;\n"
                      "min-width: 10em;\n"
                      "padding: 6px;\n"
                      "}\n";


ButtonsWidget::ButtonsWidget(QWidget *parent)
    : QWidget{parent}
{
    cameraChooseBox = new QComboBox(this);

    microphoneChooseBox = new QComboBox(this);

    mStartCameraBut = new QPushButton("Start camera", this);
    mStartCameraBut->setStyleSheet(buttonStyle);

    mPhotoBut = new QPushButton("Make photo", this);
    mPhotoBut->setStyleSheet(buttonStyle);
    mPhotoBut->setEnabled(false);

    mStartRecBut = new QPushButton("Start record", this);
    mStartRecBut->setStyleSheet(buttonStyle);
    mStartRecBut->setEnabled(false);

    mStopRecBut = new QPushButton("Stop record", this);
    mStopRecBut->setStyleSheet(buttonStyle);
    mStopRecBut->setEnabled(false);

    mStopCameraBut = new QPushButton("Stop camera", this);
    mStopCameraBut->setStyleSheet(buttonStyle);
    mStopCameraBut->setEnabled(false);

    QVBoxLayout* mButtonsLayout = new QVBoxLayout;
    QLabel* camLabel = new QLabel("Choose Camera Device:", this);
    QLabel* micLabel = new QLabel("Choose Microphone Device:", this);

    mButtonsLayout->addWidget(camLabel);
    mButtonsLayout->addWidget(cameraChooseBox);
    mButtonsLayout->addWidget(micLabel);
    mButtonsLayout->addWidget(microphoneChooseBox);
    mButtonsLayout->addStretch(1);
    mButtonsLayout->addWidget(mStartCameraBut);
    mButtonsLayout->addWidget(mPhotoBut);
    mButtonsLayout->addWidget(mStartRecBut);
    mButtonsLayout->addWidget(mStopRecBut);
    mButtonsLayout->addWidget(mStopCameraBut);

    setLayout(mButtonsLayout);

}

void ButtonsWidget::fillCameraChooseBox(const QStringList& items)
{
    cameraChooseBox->addItems(items);
}
void ButtonsWidget::fillMicrophoneChooseBox(const QStringList& items)
{
    microphoneChooseBox->addItems(items);
}















