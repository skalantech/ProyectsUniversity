/********************************************************************************
** Form generated from reading UI file 'SupprimerBorne.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMERBORNE_H
#define UI_SUPPRIMERBORNE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SupprimerBorne
{
public:
    QLabel *label;
    QPushButton *ok;
    QLabel *label_2;
    QSpinBox *p_identifiant;

    void setupUi(QDialog *SupprimerBorne)
    {
        if (SupprimerBorne->objectName().isEmpty())
            SupprimerBorne->setObjectName(QString::fromUtf8("SupprimerBorne"));
        SupprimerBorne->resize(518, 300);
        label = new QLabel(SupprimerBorne);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 90, 261, 16));
        ok = new QPushButton(SupprimerBorne);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(220, 160, 90, 28));
        label_2 = new QLabel(SupprimerBorne);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 30, 171, 16));
        p_identifiant = new QSpinBox(SupprimerBorne);
        p_identifiant->setObjectName(QString::fromUtf8("p_identifiant"));
        p_identifiant->setGeometry(QRect(300, 80, 181, 31));
        p_identifiant->setMaximum(999999);

        retranslateUi(SupprimerBorne);
        QObject::connect(ok, SIGNAL(clicked()), SupprimerBorne, SLOT(valider()));

        QMetaObject::connectSlotsByName(SupprimerBorne);
    } // setupUi

    void retranslateUi(QDialog *SupprimerBorne)
    {
        SupprimerBorne->setWindowTitle(QCoreApplication::translate("SupprimerBorne", "SupprimerBorne", nullptr));
        label->setText(QCoreApplication::translate("SupprimerBorne", "Entrez l'identifiant de la borne a supprimer", nullptr));
        ok->setText(QCoreApplication::translate("SupprimerBorne", "OK", nullptr));
        label_2->setText(QCoreApplication::translate("SupprimerBorne", "Supression de une Borne", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupprimerBorne: public Ui_SupprimerBorne {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMERBORNE_H
