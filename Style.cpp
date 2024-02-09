#include "Style.h"

Style::Style() {}

Style::~Style() {}

QString Style::getButton()
{
    return button;
}

QString Style::getLabelStyle()
{
    return labelStyle;
}

QString Style::getLineEditStyle()
{
    return lineEditStyle;
}

QString Style::getComboBoxStyle()
{
    return comboBox;
}

QString Style::button = "";
QString Style::labelStyle = "";
QString Style::lineEditStyle = "";
QString Style::comboBox = "";

void Style::setButtonStyle()
{
    button = "QPushButton { border-radius: 10px; border: 2px solid #8f8f91; background-color: #3b3c3d;font-size: 15pt Arial; color: white; font-weight: bold;}"
             "QPushButton:hover { background-color: #cccccc; color: #333333;}";
    labelStyle = "QLabel { border-radius: 5px; border: 2px solid  #3b3c3d; background-color: #3b3c3d;  color: white;}";
    lineEditStyle = "QLineEdit { font-size: 15pt Arial;background-color: #cccccc; color: #333333; }";
    comboBox = "QComboBox { font-size: 15pt Arial;background-color: #cccccc; color: #333333; }";
}
