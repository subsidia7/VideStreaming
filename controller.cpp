#include "controller.h"
#include "model.h"
#include "UI/cameraviewwidget.h"
#include "UI/buttonswidget.h"
#include "mainwindow.h"
#include <QTextStream>
#include <QCamera>
#include <QMediaCaptureSession>
#include <QPushButton>
#include <QCameraDevice>
#include <QMediaDevices>
#include <QWidget>
#include <QVideoWidget>
#include <QImageCapture>
#include <QFileDialog>
#include <QComboBox>
#include <QMediaRecorder>
#include <QAudioDevice>


QTextStream out(stdout);

Controller::Controller(MainWindow* view, Model* model)
    : mView(view), mModel(model)
{
    bw = mView->buttonsWidget;

    fillCameraChooseBox();
    fillMicrophoneChooseBox();

    changeCamera();

    mModel->mCaptureSession->setVideoOutput(mView->mCameraView);

    setupConnections();
}

void Controller::fillCameraChooseBox()
{
    QStringList items;
    for (const QCameraDevice& device : mModel->mCameraDevices)
    {
        QString s_device = device.description();
        items.append(s_device);
    }
    bw->fillCameraChooseBox(items);
}

void Controller::fillMicrophoneChooseBox()
{
    QStringList items;
    for (const QAudioDevice& device : mModel->mMicrophoneDevices)
    {
        QString s_device = device.description();
        items.append(s_device);
    }
    bw->fillMicrophoneChooseBox(items);
}

void Controller::setupConnections()
{
    connect(bw->mStartCameraBut, &QPushButton::clicked, this,
            &Controller::startCamera);

    connect(bw->mPhotoBut, &QPushButton::clicked, this,
            &Controller::makePhoto);

    connect(bw->mStartRecBut, &QPushButton::clicked, this,
            &Controller::startRec);

    connect(bw->mStopRecBut, &QPushButton::clicked, this,
            &Controller::stopRec);

    connect(bw->mStopCameraBut, &QPushButton::clicked, this,
            &Controller::stopCamera);

    connect(bw->cameraChooseBox, &QComboBox::currentTextChanged, this,
            &Controller::changeCamera);

    connect(bw->microphoneChooseBox, &QComboBox::currentTextChanged, this,
            &Controller::changeMicrophone);
}

void Controller::changeCamera()
{
    QString cameraName = bw->cameraChooseBox->currentText();
    mModel->changeCameraDevice(cameraName);
}

void Controller::changeMicrophone()
{
    QString microphoneName = bw->microphoneChooseBox->currentText();
    mModel->changeMicrophoneDevice(microphoneName);
}

void Controller::startCamera()
{
    mModel->mCamera->start();
    bw->mStartCameraBut->setEnabled(false);
    bw->mPhotoBut->setEnabled(true);
    bw->mStartRecBut->setEnabled(true);
    bw->mStopCameraBut->setEnabled(true);
    //bw->cameraChooseBox->setEnabled(false);
}

void Controller::makePhoto()
{
    QString fileName = QFileDialog::getSaveFileName(mView, "Save image", \
                                 "C:/Users/mi/Desktop/untitled",
                                 "Images (*.jpg)");
    out << fileName << Qt::endl;
    mModel->mImageCapture->captureToFile(fileName);
}

void Controller::startRec()
{
    QString fileName = "C:/Users/mi/Desktop";
    QUrl url(fileName);
    mModel->mRecorder->setOutputLocation(url);
    mModel->mRecorder->record();
    url = mModel->mRecorder->outputLocation();
    bw->mStartRecBut->setEnabled(false);
    bw->mStopRecBut->setEnabled(true);
}

void Controller::stopRec()
{
    mModel->mRecorder->stop();
    bw->mStopRecBut->setEnabled(false);
    bw->mStartRecBut->setEnabled(true);
}

void Controller::stopCamera()
{
    mModel->mCamera->stop();
    bw->mStopCameraBut->setEnabled(false);
    bw->mPhotoBut->setEnabled(false);
    bw->mStartRecBut->setEnabled(false);
    bw->mStartCameraBut->setEnabled(true);

    //bw->cameraChooseBox->setEnabled(true);
}
