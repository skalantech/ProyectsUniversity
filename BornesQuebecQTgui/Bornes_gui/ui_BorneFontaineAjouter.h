/********************************************************************************
** Form generated from reading UI file 'BorneFontaineAjouter.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BORNEFONTAINEAJOUTER_H
#define UI_BORNEFONTAINEAJOUTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_BorneFontaineAjouter
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *p_identifiantVoiePublique;
    QLineEdit *p_nomTopographique;
    QLineEdit *p_ville;
    QLineEdit *p_arrondissement;
    QPushButton *ok;
    QSpinBox *p_identifiant;
    QDoubleSpinBox *p_longitude;
    QDoubleSpinBox *p_latitude;

    void setupUi(QDialog *BorneFontaineAjouter)
    {
        if (BorneFontaineAjouter->objectName().isEmpty())
            BorneFontaineAjouter->setObjectName(QString::fromUtf8("BorneFontaineAjouter"));
        BorneFontaineAjouter->resize(564, 510);
        label = new QLabel(BorneFontaineAjouter);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 30, 171, 16));
        label_2 = new QLabel(BorneFontaineAjouter);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 90, 71, 16));
        label_3 = new QLabel(BorneFontaineAjouter);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 140, 191, 16));
        label_4 = new QLabel(BorneFontaineAjouter);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 190, 141, 16));
        label_5 = new QLabel(BorneFontaineAjouter);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 240, 151, 16));
        label_6 = new QLabel(BorneFontaineAjouter);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(50, 290, 151, 16));
        label_7 = new QLabel(BorneFontaineAjouter);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(50, 340, 58, 16));
        label_8 = new QLabel(BorneFontaineAjouter);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(50, 390, 131, 16));
        p_identifiantVoiePublique = new QLineEdit(BorneFontaineAjouter);
        p_identifiantVoiePublique->setObjectName(QString::fromUtf8("p_identifiantVoiePublique"));
        p_identifiantVoiePublique->setGeometry(QRect(250, 130, 181, 28));
        p_nomTopographique = new QLineEdit(BorneFontaineAjouter);
        p_nomTopographique->setObjectName(QString::fromUtf8("p_nomTopographique"));
        p_nomTopographique->setGeometry(QRect(250, 180, 181, 28));
        p_ville = new QLineEdit(BorneFontaineAjouter);
        p_ville->setObjectName(QString::fromUtf8("p_ville"));
        p_ville->setGeometry(QRect(250, 330, 181, 28));
        p_arrondissement = new QLineEdit(BorneFontaineAjouter);
        p_arrondissement->setObjectName(QString::fromUtf8("p_arrondissement"));
        p_arrondissement->setGeometry(QRect(250, 380, 181, 28));
        ok = new QPushButton(BorneFontaineAjouter);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(250, 440, 90, 28));
        p_identifiant = new QSpinBox(BorneFontaineAjouter);
        p_identifiant->setObjectName(QString::fromUtf8("p_identifiant"));
        p_identifiant->setGeometry(QRect(250, 80, 181, 26));
        p_identifiant->setMinimum(0);
        p_identifiant->setMaximum(999999);
        p_longitude = new QDoubleSpinBox(BorneFontaineAjouter);
        p_longitude->setObjectName(QString::fromUtf8("p_longitude"));
        p_longitude->setGeometry(QRect(250, 230, 181, 26));
        p_longitude->setDecimals(6);
        p_longitude->setMinimum(-180.000000000000000);
        p_longitude->setMaximum(180.000000000000000);
        p_longitude->setSingleStep(0.010000000000000);
        p_latitude = new QDoubleSpinBox(BorneFontaineAjouter);
        p_latitude->setObjectName(QString::fromUtf8("p_latitude"));
        p_latitude->setGeometry(QRect(250, 280, 181, 26));
        p_latitude->setDecimals(6);
        p_latitude->setMinimum(-90.000000000000000);
        p_latitude->setMaximum(90.000000000000000);
        p_latitude->setSingleStep(0.010000000000000);

        retranslateUi(BorneFontaineAjouter);
        QObject::connect(ok, SIGNAL(clicked()), BorneFontaineAjouter, SLOT(valider()));

        QMetaObject::connectSlotsByName(BorneFontaineAjouter);
    } // setupUi

    void retranslateUi(QDialog *BorneFontaineAjouter)
    {
        BorneFontaineAjouter->setWindowTitle(QCoreApplication::translate("BorneFontaineAjouter", "BorneFontaineAjouter", nullptr));
        label->setText(QCoreApplication::translate("BorneFontaineAjouter", "Ajouter une Borne Fontaine", nullptr));
        label_2->setText(QCoreApplication::translate("BorneFontaineAjouter", "Identifiant", nullptr));
        label_3->setText(QCoreApplication::translate("BorneFontaineAjouter", "Identifiant de la voie publique", nullptr));
        label_4->setText(QCoreApplication::translate("BorneFontaineAjouter", "Nom Topographique", nullptr));
        label_5->setText(QCoreApplication::translate("BorneFontaineAjouter", "Longitude", nullptr));
        label_6->setText(QCoreApplication::translate("BorneFontaineAjouter", "Latitude", nullptr));
        label_7->setText(QCoreApplication::translate("BorneFontaineAjouter", "Ville", nullptr));
        label_8->setText(QCoreApplication::translate("BorneFontaineAjouter", "Arrondissement", nullptr));
        ok->setText(QCoreApplication::translate("BorneFontaineAjouter", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BorneFontaineAjouter: public Ui_BorneFontaineAjouter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORNEFONTAINEAJOUTER_H
