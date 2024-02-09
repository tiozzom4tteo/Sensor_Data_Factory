#include "ModifyView.h"
#include "SensorsViewerManager.h"

ModifyView::ModifyView(QWidget *parent) : QWidget(parent), nameInput(new QLineEdit()), modelInput((new QLineEdit())), descriptionInput((new QLineEdit()))
{
}

ModifyView::~ModifyView()
{
    delete nameInput;
    delete modelInput;
    delete descriptionInput;
}

QFrame *ModifyView::addModifySensorsView()
{
    QFrame *frame = new QFrame();
    frame->setStyleSheet("background-color: #f5f5f5;");
    QVBoxLayout *layoutV1 = new QVBoxLayout(frame);
    layoutV1->setAlignment(Qt::AlignHCenter);
    layoutV1->setAlignment(Qt::AlignTop);

    QVBoxLayout *layoutV2 = new QVBoxLayout();
    QVBoxLayout *layoutV3 = new QVBoxLayout();
    QVBoxLayout *layoutV4 = new QVBoxLayout();
    QVBoxLayout *layoutV5 = new QVBoxLayout();

    QLabel *label1 = new QLabel();
    label1->setText("Modify name sensor");
    label1->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    label1->setStyleSheet(Style::getLabelStyle());
    label1->setAlignment(Qt::AlignHCenter);
    label1->setFont(QFont("Arial", 15));
    nameInput->setMinimumSize(0, 150);
    nameInput->setStyleSheet(Style::getLineEditStyle());

    QLabel *label2 = new QLabel();
    label2->setText("Modify model sensor");
    label2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    label2->setStyleSheet(Style::getLabelStyle());
    label2->setAlignment(Qt::AlignHCenter);
    label2->setFont(QFont("Arial", 15));
    modelInput->setMinimumSize(0, 150);
    modelInput->setStyleSheet(Style::getLineEditStyle());

    QLabel *label3 = new QLabel();
    label3->setText("Modify description sensor");
    label3->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    label3->setStyleSheet(Style::getLabelStyle());
    label3->setAlignment(Qt::AlignHCenter);
    label3->setFont(QFont("Arial", 15));
    descriptionInput->setMinimumSize(0, 150);
    descriptionInput->setStyleSheet(Style::getLineEditStyle());

    QPushButton *commit = new QPushButton();
    commit->setText("Modify sensor");
    commit->setMinimumSize(150, 30);
    commit->setStyleSheet(Style::getButton());

    connect(commit, &QPushButton::clicked, this, [=](){manager->modifySensor(nameInput->text().toStdString(), modelInput->text().toStdString(), descriptionInput->text().toStdString());});

    layoutV2->addWidget(label1);
    layoutV2->addWidget(nameInput);

    layoutV3->addWidget(label2);
    layoutV3->addWidget(modelInput);

    layoutV4->addWidget(label3);
    layoutV4->addWidget(descriptionInput);

    layoutV5->addWidget(commit);
    layoutV5->setAlignment(Qt::AlignHCenter);

    layoutV1->addLayout(layoutV2);
    layoutV1->addLayout(layoutV3);
    layoutV1->addLayout(layoutV4);
    layoutV1->addLayout(layoutV5);

    return frame;
}

void ModifyView::setManager(SensorsViewerManager *manager)
{
    this->manager = manager;
}

void ModifyView::setSensorRef(const unsigned int& index)
{
    this->index = index;
}

unsigned int ModifyView::getSensorRef() const
{
    return index;
}

void ModifyView::setName(const std::string &name)
{
    this->name = name;
    nameInput->setText(QString::fromStdString(name));
}

void ModifyView::setModel(const std::string &model)
{
    this->model = model;
    modelInput->setText(QString::fromStdString(model));
}

void ModifyView::setDescription(const std::string &description)
{
    this->description = description;
    descriptionInput->setText(QString::fromStdString(description));
}
