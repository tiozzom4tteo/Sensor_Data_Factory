#include "Controller.h"

Controller::Controller(QWidget *parent) : QWidget(parent), model(new Model) {}

Controller::~Controller()
{
    delete viewer;
    delete model;
}

void Controller::setModel(Model *model) { this->model = model; }
void Controller::setViewer(SensorsViewerManager *view) { viewer = view; }

void Controller::getSensors(const std::string &type) const
{
    viewer->getSensorView()->setView(type);
    viewer->showSensorsView(model->getSensors());
}

void Controller::createSensors(const unsigned int& index, const std::string& name, const std::string& model, const std::string& description) const
{
    try
    {
        switch (index)
        {
        case 0:
            this->model->addNewAccelerometerSensor(name, model, description);
            break;
        case 1:
            this->model->addElettroSensor(name, model, description);
            break;
        case 2:
            this->model->addNewGiroscopeSensor(name, model, description);
            break;
        case 3:
            this->model->addNewSemiSensor(name, model, description);
            break;
        case 4:
            this->model->addTermoResistance(name, model, description);
            break;
        case 5:
            this->model->addNewTermoCouplesSensor(name, model, description);
            break;
        }
        // delete ptr;
    }
    catch (const std::exception &e)
    {
        // qInfo() << e.what();
        QMessageBox *errorMessage = new QMessageBox();
        errorMessage->setIcon(QMessageBox::Critical);
        errorMessage->setWindowTitle("Errore");
        errorMessage->setText(e.what());
        errorMessage->setStandardButtons(QMessageBox::Ok);
        errorMessage->exec();
    }
    viewer->showCreateSensorsView();
}

void Controller::removeSensor(const unsigned int &index)
{
    try {
        model->removeSensor(index);
        viewer->showSensorsView(model->getSensors());
    }  catch (const std::exception &e) {
        QMessageBox *errorMessage = new QMessageBox();
        errorMessage->setIcon(QMessageBox::Critical);
        errorMessage->setWindowTitle("Errore");
        errorMessage->setText(e.what());
        errorMessage->setStandardButtons(QMessageBox::Ok);
        errorMessage->exec();
    }

}

void Controller::modifySensor(const std::string &name, const std::string &model, const std::string &description)
{
    try
    {
        this->model->modifySensor(viewer->getModifyView()->getSensorRef(), name, model, description);
        viewer->showSensorsView(this->model->getSensors());
    }
    catch (const std::exception &e)
    {
        QMessageBox *errorMessage = new QMessageBox();
        errorMessage->setIcon(QMessageBox::Critical);
        errorMessage->setWindowTitle("Errore");
        errorMessage->setText(e.what());
        errorMessage->setStandardButtons(QMessageBox::Ok);
        errorMessage->exec();
    }
}

void Controller::load(const unsigned int &index)
{
    QString percorsoFile = QFileDialog::getOpenFileName(this, "Apri File", "", "Testo (*.json);;Tutti i file (*.*)");
    if (percorsoFile.isEmpty())
    {
        return;
    }
    try
    {
        model->load(percorsoFile.toStdString());
    }
    catch (const std::exception &e)
    {
        QMessageBox *errorMessage = new QMessageBox();
        errorMessage->setIcon(QMessageBox::Critical);
        errorMessage->setWindowTitle("Errore");
        errorMessage->setText(e.what());
        errorMessage->setStandardButtons(QMessageBox::Ok);
        errorMessage->exec();
    }

    if (index == 1)
        viewer->showSensorsView(model->getSensors());
}

void Controller::save()
{
    QString percorsoFile = QFileDialog::getSaveFileName(this, "Salva File", "", "Testo (*.json);;Tutti i file (*.*)");
    if (percorsoFile.isEmpty())
    {
        return;
    }
    try
    {
        model->save(percorsoFile.toStdString());
    }
    catch (const std::exception &e)
    {
        QMessageBox *errorMessage = new QMessageBox();
        errorMessage->setIcon(QMessageBox::Critical);
        errorMessage->setWindowTitle("Errore");
        errorMessage->setText(e.what());
        errorMessage->setStandardButtons(QMessageBox::Ok);
        errorMessage->exec();
    }
}

void Controller::next() const
{
    std::string type = viewer->getGraphView()->getCurrentType();

    if(type=="")
    {
        model->nextSensor(viewer->getGraphView()->getCurrentIndex());

    }
   else
    {
        model->nextSensorTyped(viewer->getGraphView()->getCurrentIndex());
    }
    unsigned int index = model->getCurrentSensor();
    viewer->showGraphSensorView(model->getSensor(index),index, type);
}

void Controller::previous() const
{
    std::string type = viewer->getGraphView()->getCurrentType();

    if(type=="")
    {
        model->previousSensor(viewer->getGraphView()->getCurrentIndex());
    }
   else
    {
        model->previousSensorTyped(viewer->getGraphView()->getCurrentIndex());
    }
    unsigned int index = model->getCurrentSensor();
    viewer->showGraphSensorView(model->getSensor(index),index, type);
}
