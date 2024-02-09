#ifndef MODIFYVIEW_H
#define MODIFYVIEW_H

#include "Sensor.h"
#include <QWidget>
#include <QFrame>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

class SensorsViewerManager;

class ModifyView : public QWidget
{
    Q_OBJECT

private:
    SensorsViewerManager *manager;
    unsigned int index;
    QLineEdit *nameInput;
    QLineEdit *modelInput;
    QLineEdit *descriptionInput;
    std::string name;
    std::string model;
    std::string description;

public:
    explicit ModifyView(QWidget *parent = nullptr);
    ~ModifyView();
    QFrame *addModifySensorsView();
    void setManager(SensorsViewerManager *);
    void setSensorRef(const unsigned int &index);
    unsigned int getSensorRef() const;
    void setName(const std::string &);
    void setModel(const std::string &);
    void setDescription(const std::string &);

signals:
};

#endif // MODIFYVIEW_H
