/********************************************************************************
** Form generated from reading UI file 'dialogBorneFontaine.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGBORNEFONTAINE_H
#define UI_DIALOGBORNEFONTAINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_dialogBorneFontaine
{
public:

    void setupUi(QDialog *dialogBorneFontaine)
    {
        if (dialogBorneFontaine->objectName().isEmpty())
            dialogBorneFontaine->setObjectName(QString::fromUtf8("dialogBorneFontaine"));
        dialogBorneFontaine->resize(597, 580);

        retranslateUi(dialogBorneFontaine);

        QMetaObject::connectSlotsByName(dialogBorneFontaine);
    } // setupUi

    void retranslateUi(QDialog *dialogBorneFontaine)
    {
        dialogBorneFontaine->setWindowTitle(QCoreApplication::translate("dialogBorneFontaine", "dialogBorneFontaine", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialogBorneFontaine: public Ui_dialogBorneFontaine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGBORNEFONTAINE_H
