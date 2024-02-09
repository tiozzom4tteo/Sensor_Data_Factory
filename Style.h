#ifndef STYLE_H
#define STYLE_H


#include <QCoreApplication>
#include <QSettings>
#include <QVariant>

class Style
{
private:

    static QString button;
    static QString labelStyle;
    static QString lineEditStyle;
    static QString comboBox;

public:
    Style();
    ~Style();
    static void setButtonStyle();
    static QString getButton();
    static QString getLabelStyle();
    static QString getLineEditStyle();
    static QString getComboBoxStyle();

};

#endif // STYLE_H
