#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class MainWindow;
class Model;
class ButtonsWidget;

class Controller : public QObject
{
public:
    Controller(MainWindow* view, Model* model);
private:
    MainWindow* mView;
    ButtonsWidget* bw;
    Model* mModel;

    void setupConnections();
    void findAllCameras();

    void changeCamera();
    void startCamera();
    void makePhoto();
    void startRec();
    void stopRec();
    void stopCamera();
};

#endif // CONTROLLER_H
