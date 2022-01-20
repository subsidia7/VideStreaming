#include "model.h"
#include <QCamera>
#include <QMediaCaptureSession>
#include <QPushButton>
#include <QMediaDevices>
#include <QImageCapture>
#include <QMediaRecorder>
#include <QMediaFormat>


Model::Model(QObject *parent)
    : QObject{parent}
{
    findAllCameras();

    findAllMicrophones();

    mCamera = new QCamera;

    mImageCapture = new QImageCapture(this);

    mCaptureSession = new QMediaCaptureSession;
    mCaptureSession->setCamera(mCamera);
    mCaptureSession->setImageCapture(mImageCapture);

    mRecorder = new QMediaRecorder(mCamera);
    mCaptureSession->setRecorder(mRecorder);

    QMediaFormat mFormat(QMediaFormat::MPEG4);
    mFormat.setVideoCodec(QMediaFormat::VideoCodec::H264);
    mFormat.setAudioCodec(QMediaFormat::AudioCodec::MP3);

    mRecorder->setMediaFormat(mFormat);


}

void Model::findAllCameras()
{
    mCameraDevices = QMediaDevices::videoInputs();
}

void Model::findAllMicrophones()
{
    mMicrophoneDevices = QMediaDevices::audioInputs();
}

void Model::changeCameraDevice(const QString& cameraName)
{
    if (cameraName == mCurrentCameraName)
        return;
    for (const QCameraDevice& device : mCameraDevices)
    {
        QString s_device = device.description();
        if (s_device == cameraName)
        {
            mCamera->setCameraDevice(device);
            mCurrentCameraName = s_device;
        }
    }
}
