#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QCameraDevice>
#include <QAudioDevice>
#include "controller.h"

class QCamera;
class QMediaCaptureSession;
class QImageCapture;
class QMediaRecorder;
class QAudioInput;
//class QMediaFormat;


class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);
    friend class Controller;
private:
    QList<QCameraDevice> mCameraDevices;
    QList<QAudioDevice> mMicrophoneDevices;
    QCamera* mCamera;
    QAudioInput* mMicrophone;
    QMediaCaptureSession* mCaptureSession;
    QImageCapture* mImageCapture;
    QMediaRecorder* mRecorder;
    //QMediaFormat* mFormat;
    int mCurrentCameraI;
    QString mCurrentCameraName;
    QString mCurrentMicrophoneName;
    void findAllCameras();
    void findAllMicrophones();

    void changeCameraDevice(const QString&);
    void changeMicrophoneDevice(const QString&);
};

#endif // MODEL_H
