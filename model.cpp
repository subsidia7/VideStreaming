#include "model.h"
#include <QCamera>
#include <QMediaCaptureSession>
#include <QPushButton>
#include <QMediaDevices>
#include <QImageCapture>
#include <QMediaRecorder>
#include <QMediaFormat>
#include <QAudioInput>
#include <QAudioFormat>


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

    mMicrophone = new QAudioInput;
    QAudioFormat format;
    // Set up the desired format, for example:
    format.setSampleRate(8000);
    format.setChannelCount(1);
    mCaptureSession->setAudioInput(mMicrophone);


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

void Model::changeMicrophoneDevice(const QString& microphoneName)
{
    if (microphoneName == mCurrentMicrophoneName)
        return;
    for (const QAudioDevice& device : mMicrophoneDevices)
    {
        QString s_device = device.description();
        if (s_device == microphoneName)
        {
            mMicrophone->setDevice(device);
            mCurrentMicrophoneName = s_device;
        }
    }
}
