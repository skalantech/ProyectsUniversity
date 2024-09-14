/********************************************************************************
** Form generated from reading UI file 'BorneStationnementAjouter.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BORNESTATIONNEMENTAJOUTER_H
#define UI_BORNESTATIONNEMENTAJOUTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_BorneStationnementAjouter
{
public:
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_4;
    QLineEdit *p_nomTopographique;
    QLineEdit *p_coteRue;
    QLabel *label_6;
    QLabel *label_8;
    QPushButton *ok;
    QLineEdit *p_identifiantVoiePublique;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *p_identifiant;
    QDoubleSpinBox *p_longitude;
    QDoubleSpinBox *p_latitude;
    QSpinBox *p_numBorne;

    void setupUi(QDialog *BorneStationnementAjouter)
    {
        if (BorneStationnementAjouter->objectName().isEmpty())
            BorneStationnementAjouter->setObjectName(QString::fromUtf8("BorneStationnementAjouter"));
        BorneStationnementAjouter->resize(564, 511);
        label_5 = new QLabel(BorneStationnementAjouter);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 240, 151, 16));
        label_7 = new QLabel(BorneStationnementAjouter);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(40, 340, 121, 16));
        label_4 = new QLabel(BorneStationnementAjouter);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 190, 141, 16));
        p_nomTopographique = new QLineEdit(BorneStationnementAjouter);
        p_nomTopographique->setObjectName(QString::fromUtf8("p_nomTopographique"));
        p_nomTopographique->setGeometry(QRect(240, 180, 181, 28));
        p_coteRue = new QLineEdit(BorneStationnementAjouter);
        p_coteRue->setObjectName(QString::fromUtf8("p_coteRue"));
        p_coteRue->setGeometry(QRect(240, 380, 181, 28));
        label_6 = new QLabel(BorneStationnementAjouter);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 290, 151, 16));
        label_8 = new QLabel(BorneStationnementAjouter);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(40, 390, 131, 16));
        ok = new QPushButton(BorneStationnementAjouter);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(240, 440, 90, 28));
        p_identifiantVoiePublique = new QLineEdit(BorneStationnementAjouter);
        p_identifiantVoiePublique->setObjectName(QString::fromUtf8("p_identifiantVoiePublique"));
        p_identifiantVoiePublique->setGeometry(QRect(240, 130, 181, 28));
        label = new QLabel(BorneStationnementAjouter);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 30, 211, 16));
        label_2 = new QLabel(BorneStationnementAjouter);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 90, 71, 16));
        label_3 = new QLabel(BorneStationnementAjouter);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 140, 191, 16));
        p_identifiant = new QSpinBox(BorneStationnementAjouter);
        p_identifiant->setObjectName(QString::fromUtf8("p_identifiant"));
        p_identifiant->setGeometry(QRect(240, 80, 181, 26));
        p_identifiant->setMinimum(0);
        p_identifiant->setMaximum(999999);
        p_longitude = new QDoubleSpinBox(BorneStationnementAjouter);
        p_longitude->setObjectName(QString::fromUtf8("p_longitude"));
        p_longitude->setGeometry(QRect(240, 230, 181, 26));
        p_longitude->setDecimals(6);
        p_longitude->setMinimum(-180.000000000000000);
        p_longitude->setMaximum(180.000000000000000);
        p_longitude->setSingleStep(0.010000000000000);
        p_longitude->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        p_longitude->setValue(0.000000000000000);
        p_latitude = new QDoubleSpinBox(BorneStationnementAjouter);
        p_latitude->setObjectName(QString::fromUtf8("p_latitude"));
        p_latitude->setGeometry(QRect(240, 280, 181, 26));
        p_latitude->setDecimals(6);
        p_latitude->setMinimum(-90.000000000000000);
        p_latitude->setMaximum(90.000000000000000);
        p_latitude->setSingleStep(0.010000000000000);
        p_latitude->setValue(0.000000000000000);
        p_numBorne = new QSpinBox(BorneStationnementAjouter);
        p_numBorne->setObjectName(QString::fromUtf8("p_numBorne"));
        p_numBorne->setGeometry(QRect(240, 330, 181, 26));
        p_numBorne->setMinimum(0);
        p_numBorne->setMaximum(9999);

        retranslateUi(BorneStationnementAjouter);
        QObject::connect(ok, SIGNAL(clicked()), BorneStationnementAjouter, SLOT(valider()));

        QMetaObject::connectSlotsByName(BorneStationnementAjouter);
    } // setupUi

    void retranslateUi(QDialog *BorneStationnementAjouter)
    {
        BorneStationnementAjouter->setWindowTitle(QCoreApplication::translate("BorneStationnementAjouter", "BorneStationnementAjouter", nullptr));
        label_5->setText(QCoreApplication::translate("BorneStationnementAjouter", "Longitude", nullptr));
        label_7->setText(QCoreApplication::translate("BorneStationnementAjouter", "Numero de Borne", nullptr));
        label_4->setText(QCoreApplication::translate("BorneStationnementAjouter", "Nom Topographique", nullptr));
        label_6->setText(QCoreApplication::translate("BorneStationnementAjouter", "Latitude", nullptr));
        label_8->setText(QCoreApplication::translate("BorneStationnementAjouter", "Cote de la Rue", nullptr));
        ok->setText(QCoreApplication::translate("BorneStationnementAjouter", "OK", nullptr));
        label->setText(QCoreApplication::translate("BorneStationnementAjouter", "Ajouter une Borne Stationnement", nullptr));
        label_2->setText(QCoreApplication::translate("BorneStationnementAjouter", "Identifiant", nullptr));
        label_3->setText(QCoreApplication::translate("BorneStationnementAjouter", "Identifiant de la voie publique", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BorneStationnementAjouter: public Ui_BorneStationnementAjouter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORNESTATIONNEMENTAJOUTER_H
