/********************************************************************************
** Form generated from reading UI file 'BornesGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BORNESGUI_H
#define UI_BORNESGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BornesGUI
{
public:
    QAction *actionSupprimer_une_Borne;
    QAction *actionBorne_Fontaine;
    QAction *actionBorne_Stationnement;
    QAction *actionQuitter;
    QWidget *centralwidget;
    QTextEdit *fenetreAffichage;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuAjouter_une_Borne;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BornesGUI)
    {
        if (BornesGUI->objectName().isEmpty())
            BornesGUI->setObjectName(QString::fromUtf8("BornesGUI"));
        BornesGUI->resize(625, 600);
        actionSupprimer_une_Borne = new QAction(BornesGUI);
        actionSupprimer_une_Borne->setObjectName(QString::fromUtf8("actionSupprimer_une_Borne"));
        actionBorne_Fontaine = new QAction(BornesGUI);
        actionBorne_Fontaine->setObjectName(QString::fromUtf8("actionBorne_Fontaine"));
        actionBorne_Stationnement = new QAction(BornesGUI);
        actionBorne_Stationnement->setObjectName(QString::fromUtf8("actionBorne_Stationnement"));
        actionQuitter = new QAction(BornesGUI);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        centralwidget = new QWidget(BornesGUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        fenetreAffichage = new QTextEdit(centralwidget);
        fenetreAffichage->setObjectName(QString::fromUtf8("fenetreAffichage"));
        fenetreAffichage->setGeometry(QRect(10, 20, 601, 551));
        BornesGUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BornesGUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 625, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuAjouter_une_Borne = new QMenu(menuMenu);
        menuAjouter_une_Borne->setObjectName(QString::fromUtf8("menuAjouter_une_Borne"));
        BornesGUI->setMenuBar(menubar);
        statusbar = new QStatusBar(BornesGUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        BornesGUI->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(menuAjouter_une_Borne->menuAction());
        menuMenu->addAction(actionSupprimer_une_Borne);
        menuMenu->addAction(actionQuitter);
        menuAjouter_une_Borne->addAction(actionBorne_Fontaine);
        menuAjouter_une_Borne->addAction(actionBorne_Stationnement);

        retranslateUi(BornesGUI);
        QObject::connect(actionQuitter, SIGNAL(triggered()), BornesGUI, SLOT(close()));
        QObject::connect(actionBorne_Fontaine, SIGNAL(triggered()), BornesGUI, SLOT(dialogBorneFontaine()));
        QObject::connect(actionBorne_Stationnement, SIGNAL(triggered()), BornesGUI, SLOT(dialogBorneStationnement()));
        QObject::connect(actionSupprimer_une_Borne, SIGNAL(triggered()), BornesGUI, SLOT(dialogSupprimerBorne()));

        QMetaObject::connectSlotsByName(BornesGUI);
    } // setupUi

    void retranslateUi(QMainWindow *BornesGUI)
    {
        BornesGUI->setWindowTitle(QCoreApplication::translate("BornesGUI", "BornesGUI", nullptr));
        actionSupprimer_une_Borne->setText(QCoreApplication::translate("BornesGUI", "Supprimer une Borne", nullptr));
        actionBorne_Fontaine->setText(QCoreApplication::translate("BornesGUI", "Borne Fontaine", nullptr));
        actionBorne_Stationnement->setText(QCoreApplication::translate("BornesGUI", "Borne Stationnement", nullptr));
        actionQuitter->setText(QCoreApplication::translate("BornesGUI", "Quitter", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("BornesGUI", "Menu", nullptr));
        menuAjouter_une_Borne->setTitle(QCoreApplication::translate("BornesGUI", "Ajouter une Borne", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BornesGUI: public Ui_BornesGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORNESGUI_H
