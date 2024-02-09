#ifndef CREATEVIEW_H
#define CREATEVIEW_H

#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QRadioButton>
#include "Style.h"

class SensorsViewerManager;

class CreateView : public QWidget
{
    Q_OBJECT
private:
    SensorsViewerManager *manager;

public:
    explicit CreateView(QWidget *parent = nullptr);
    ~CreateView();
    QFrame *addCreateSensorsView();
    void setManager(SensorsViewerManager *);

signals:
};

#endif // CREATEVIEW_H
