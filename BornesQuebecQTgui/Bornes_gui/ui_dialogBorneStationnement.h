/********************************************************************************
** Form generated from reading UI file 'dialogBorneStationnement.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGBORNESTATIONNEMENT_H
#define UI_DIALOGBORNESTATIONNEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_dialogBorneStationnement
{
public:

    void setupUi(QDialog *dialogBorneStationnement)
    {
        if (dialogBorneStationnement->objectName().isEmpty())
            dialogBorneStationnement->setObjectName(QString::fromUtf8("dialogBorneStationnement"));
        dialogBorneStationnement->resize(597, 541);

        retranslateUi(dialogBorneStationnement);

        QMetaObject::connectSlotsByName(dialogBorneStationnement);
    } // setupUi

    void retranslateUi(QDialog *dialogBorneStationnement)
    {
        dialogBorneStationnement->setWindowTitle(QCoreApplication::translate("dialogBorneStationnement", "dialogBorneStationnement", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialogBorneStationnement: public Ui_dialogBorneStationnement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGBORNESTATIONNEMENT_H
