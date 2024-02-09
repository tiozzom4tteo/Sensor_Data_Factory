#include "SensorsDashboard.h"

SensorsDashboard::SensorsDashboard() : currentSensor(0), sensors() {}

SensorsDashboard::~SensorsDashboard()
{
    for (auto i : sensors)
        delete i;
}

void SensorsDashboard::addSensor(Sensor *sensor)
{
    for (std::vector<Sensor *>::const_iterator it = sensors.begin(); it != sensors.end(); it++)
    {
        if (**it == *sensor)
        {
            throw std::runtime_error("Error: duplicate sensors");
        }
    }
    sensors.push_back(sensor);
    currentSensor = (int)(sensors.size() - 1);
}

void SensorsDashboard::removeSensor(unsigned int index)
{
    if (index >= (unsigned int)sensors.size())
    {
        throw std::out_of_range("index out of range");
    }
    sensors.erase(sensors.begin() + index);
    if (currentSensor >= (int)sensors.size())
    {
        if (currentSensor == (int)sensors.size())
        {
            currentSensor = (int)(sensors.size() - 1);
        }
        else
        {
            currentSensor = 0;
        }
    }
}

unsigned int SensorsDashboard::getCurrentSensor() const
{
    return currentSensor;
}

Sensor *SensorsDashboard::getSensor(unsigned int index) const
{
    if (index >= (unsigned int)sensors.size())
    {
        throw std::out_of_range("index out of range");
    }
    return sensors[index];
}

unsigned int SensorsDashboard::getSize() const
{
    return (unsigned int)sensors.size();
}

void SensorsDashboard::previous()
{
    if (currentSensor > 0)
    {
        currentSensor--;
    }
    else
    {
        goToEnd();
    }
}

void SensorsDashboard::next()
{
    if (currentSensor < (int)(sensors.size() - 1))
    {
        currentSensor++;
    }
    else
    {
        goToStart();
    }
}

void SensorsDashboard::previousTyped(const unsigned int &index)
{
    if (dynamic_cast<TempSensor *>(sensors[index]))
    {
        if (currentSensor > 0)
        {
            currentSensor--;
            if (!dynamic_cast<TempSensor *>(sensors[currentSensor]))
                previousTyped(index);
        }
        else
        {
            currentSensor = (int)sensors.size();
            previousTyped(index);
        }
    }
    else if (dynamic_cast<GasSensor *>(sensors[index]))
    {
        if (currentSensor > 0)
        {
            currentSensor--;
            if (!dynamic_cast<GasSensor *>(sensors[currentSensor]))
                previousTyped(index);
        }
        else
        {
            currentSensor = (int)sensors.size();
            previousTyped(index);
        }
    }
    else if (dynamic_cast<MovSens *>(sensors[index]))
    {
        if (currentSensor > 0)
        {
            currentSensor--;
            if (!dynamic_cast<MovSens *>(sensors[currentSensor]))
                previousTyped(index);
        }
        else
        {
            currentSensor = (int)sensors.size();
            previousTyped(index);
        }
    }
}

void SensorsDashboard::nextTyped(const unsigned int &index)
{
    if (dynamic_cast<TempSensor *>(sensors[index]))
    {
        if (currentSensor < (int)(sensors.size() - 1))
        {
            currentSensor++;
            if (!dynamic_cast<TempSensor *>(sensors[currentSensor]))
                nextTyped(index);
        }
        else
        {
            currentSensor = -1;
            nextTyped(index);
        }
    }
    else if (dynamic_cast<GasSensor *>(sensors[index]))
    {
        if (currentSensor < (int)(sensors.size() - 1))
        {
            currentSensor++;
            if (!dynamic_cast<GasSensor *>(sensors[currentSensor]))
                nextTyped(index);
        }
        else
        {
            currentSensor = -1;
            nextTyped(index);
        }
    }
    else if (dynamic_cast<MovSens *>(sensors[index]))
    {
        if (currentSensor < (int)(sensors.size() - 1)) // 1-1
        {
            currentSensor++;
            if (!dynamic_cast<MovSens *>(sensors[currentSensor]))
                nextTyped(index);
        }
        else
        {
            currentSensor = -1;
            nextTyped(index);
        }
    }
}

void SensorsDashboard::goToStart()
{
    currentSensor = 0;
}

void SensorsDashboard::goToEnd()
{
    currentSensor = (int)(sensors.size() - 1);
}

void SensorsDashboard::modifySensor(const unsigned int &index, const std::string &name, const std::string &model, const std::string &description)
{
    if (name == "" || model == "")
    {
        throw std::runtime_error("Error: One of name or model field are empty");
    }
    // Sensor *s;
    bool temp = false;

    for (Sensor *sens : sensors)
    {
        if (sens->getName() == name && sensors[index]->getName() != name)
        {
            throw std::runtime_error("Error: This name already exist");
        }
        if (sens == sensors[index])
        {
            temp = true;
            // s = sens;
        }
    }
    if (temp)
    {
        sensors[index]->setName(name);
        sensors[index]->setModel(model);
        sensors[index]->setDescription(description);
    }
}

void SensorsDashboard::setCurrentIndex(const unsigned int &index)
{
    currentSensor = index;
}

std::vector<Sensor *> SensorsDashboard::getSensorsOfGasType() const
{
    std::vector<Sensor *> sensoroftype;
    for (std::vector<Sensor *>::const_iterator it = sensors.begin(); it != sensors.end(); it++)
    {
        if (dynamic_cast<GasSensor *>(*it))
        {
            sensoroftype.push_back(*it);
        }
    }
    return sensoroftype;
}

std::vector<Sensor *> SensorsDashboard::getSensorsOfMovmentType() const
{
    std::vector<Sensor *> sensoroftype;
    for (std::vector<Sensor *>::const_iterator it = sensors.begin(); it != sensors.end(); it++)
    {
        if (dynamic_cast<MovSens *>(*it))
        {
            sensoroftype.push_back(*it);
        }
    }
    return sensoroftype;
}

std::vector<Sensor *> SensorsDashboard::getSensorsOfTemperatureType() const
{
    std::vector<Sensor *> sensoroftype;
    for (std::vector<Sensor *>::const_iterator it = sensors.begin(); it != sensors.end(); it++)
    {
        if (dynamic_cast<TempSensor *>(*it))
        {
            sensoroftype.push_back(*it);
        }
    }
    return sensoroftype;
}

std::vector<Sensor *> SensorsDashboard::getSensors() const
{
    return sensors;
}
