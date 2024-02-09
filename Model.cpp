#include "Model.h"

Model::Model() : dashboard(new SensorsDashboard) {}

Model::~Model()
{
    delete dashboard;
}

void Model::addElettroSensor(const std::string &name, const std::string &model, const std::string &description, const std::vector<double> &misurations) const
{
    CreatorSensors *create = new CreatorSensors();
    dashboard->addSensor(create->createElettroSensor(name, model, description, misurations));
    delete create;
}

void Model::addNewGiroscopeSensor(const std::string &name, const std::string &model, const std::string &description, const std::vector<double> &misurations) const
{
    CreatorSensors *create = new CreatorSensors();
    dashboard->addSensor(create->createGiroscopeSensor(name, model, description, misurations));
    delete create;
}

void Model::addNewAccelerometerSensor(const std::string &name, const std::string &model, const std::string &description, const std::vector<double> &misurations) const
{
    CreatorSensors *create = new CreatorSensors();
    dashboard->addSensor(create->createAccellSensor(name, model, description, misurations));
    delete create;
}

void Model::addNewTermoCouplesSensor(const std::string &name, const std::string &model, const std::string &description, const std::vector<double> &misurations) const
{
    CreatorSensors *create = new CreatorSensors();
    dashboard->addSensor(create->createTermocouplesSensor(name, model, description, misurations));
    delete create;
}

void Model::addTermoResistance(const std::string &name, const std::string &model, const std::string &description, const std::vector<double> &misurations) const
{
    CreatorSensors *create = new CreatorSensors();
    dashboard->addSensor(create->createTermoresistanceSensor(name, model, description, misurations));
    delete create;
}

void Model::addNewSemiSensor(const std::string &name, const std::string &model, const std::string &description, const std::vector<double> &misurations) const
{
    CreatorSensors *create = new CreatorSensors();
    dashboard->addSensor(create->createSemiSensor(name, model, description, misurations));
    delete create;
}

void Model::removeSensor(unsigned int index)
{
    dashboard->removeSensor(index);
}

void Model::nextSensor(const unsigned int& index) const
{
    dashboard->setCurrentIndex(index);
    dashboard->next();
}

void Model::previousSensor(const unsigned int& index) const
{ 
    dashboard->setCurrentIndex(index);
    dashboard->previous();
}

void Model::nextSensorTyped(const unsigned int &index) const
{
    dashboard->setCurrentIndex(index);
    dashboard->nextTyped(index);
}

void Model::previousSensorTyped(const unsigned int &index) const
{
    dashboard->setCurrentIndex(index);
    dashboard->previousTyped(index);
}

void Model::modifySensor(const unsigned int& index, const std::string &name, const std::string &model, const std::string &descritpion)
{
    dashboard->modifySensor(index, name, model, descritpion);
}

Sensor *Model::getSensor(unsigned int index) const
{
    return dashboard->getSensor(index);
}

unsigned int Model::getCurrentSensor() const
{
    return dashboard->getCurrentSensor();
}

unsigned int Model::getSensorsSize() const
{
    return dashboard->getSize();
}

std::vector<Sensor *> Model::getGasSensors() const
{
    return dashboard->getSensorsOfGasType();
}

std::vector<Sensor *> Model::getMovmentSensors() const
{
    return dashboard->getSensorsOfMovmentType();
}

std::vector<Sensor *> Model::getTemperatureSensors() const
{
    return dashboard->getSensorsOfTemperatureType();
}

std::vector<Sensor *> Model::getSensors() const
{
    return dashboard->getSensors();
}

void Model::load(const std::string &filename)
{
    std::ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        throw std::runtime_error("Impossible to open file");
    }

    std::string line;

    while (std::getline(inputFile >> std::ws, line))
    {
        if (line.find("{") == std::string::npos)
        {
            continue;
        }

        std::string category;
        std::string name;
        std::string model;
        std::string desc;
        std::vector<double> misurations;

        while (std::getline(inputFile >> std::ws, line))
        {
            if (line.find("}") != std::string::npos)
            {
                break;
            }

            size_t colonPos = line.find(":");
            size_t quotePos1 = line.find("\"", colonPos + 1);
            size_t quotePos2 = line.find("\"", quotePos1 + 1);

            std::string key = line.substr(0, colonPos);
            std::string value = line.substr(quotePos1 + 1, quotePos2 - quotePos1 - 1);
            if (key == "\"Categoria\"")
            {
                category = value;
            }
            else if (key == "\"Name\"")
            {
                name = value;
            }
            else if (key == "\"Model\"")
            {
                model = value;
            }
            else if (key == "\"Description\"")
            {
                desc = value;
            }
            else if (key == "\"Misuration\"")
            {
                value = value.substr(1, value.size() - 2);
                std::istringstream ss(value);
                double numero;
                while (ss >> numero) {
                    misurations.push_back(numero);
                    ss.ignore();
                }

            }
        }

        if (category == "Accellerometer")
            addNewAccelerometerSensor(name, model, desc, misurations);
        else if (category == "SemiConductors")
            addNewSemiSensor(name, model, desc, misurations);
        else if (category == "ElettroSensor")
            addElettroSensor(name, model, desc, misurations);
        else if (category == "Giroscope")
            addNewGiroscopeSensor(name, model, desc, misurations);
        else if (category == "TermoResistance")
            addTermoResistance(name, model, desc, misurations);
        else if (category == "TermoCouples")
            addNewTermoCouplesSensor(name, model, desc, misurations);
    }
    inputFile.close();
}

void Model::save(const std::string &filename)
{
    std::ofstream outputFile(filename);
    if (outputFile.is_open())
    {
        outputFile << "[\n";
        std::string sensorData;
        std::string category;
        std::vector<Sensor *> sensors = dashboard->getSensors();
        size_t lastSensorIndex = sensors.size() - 1;

        for (size_t i = 0; i < sensors.size(); ++i)
        {
            if (dynamic_cast<Accellerometer *>(sensors[i]))
            {
                category = "Accellerometer";
            }
            else if (dynamic_cast<ElettroSensor *>(sensors[i]))
            {
                category = "ElettroSensor";
            }
            else if (dynamic_cast<SemiConductors *>(sensors[i]))
            {
                category = "SemiConductors";
            }
            else if (dynamic_cast<Giroscope *>(sensors[i]))
            {
                category = "Giroscope";
            }
            else if (dynamic_cast<TermoResistance *>(sensors[i]))
            {
                category = "TermoResistance";
            }
            else if (dynamic_cast<TermoCouples *>(sensors[i]))
            {
                category = "TermoCouples";
            }
            sensorData += "{\n";
            sensorData += "  \"Categoria\": \"" + category + "\"" + ",\n";
            sensorData += "  \"Name\": \"" + sensors[i]->getName() + "\"" + ",\n";
            sensorData += "  \"Model\": \"" + sensors[i]->getModel() + "\"" + ",\n";
            sensorData += "  \"Description\": \"" + sensors[i]->getDescription() + "\"" + ",\n";
            sensorData +="  \"Misuration\": \"[";
            unsigned int size = sensors[i]->getMisurations().size();
            for (double misuration : sensors[i]->getMisurations())
            {
                sensorData += std::to_string(misuration) + ", ";
            }
            if(size!=0)
                sensorData = sensorData.substr(0, sensorData.size() - 2);
            sensorData += "]\"";
            sensorData += "\n}";

            if (i < lastSensorIndex)
            {
                sensorData += ",";
            }
            sensorData += "\n";
        }
        outputFile << sensorData;
        outputFile << "]\n";
        outputFile.close();
    }
    else
    {
        throw std::runtime_error("Impossible to open file");
    }
}
