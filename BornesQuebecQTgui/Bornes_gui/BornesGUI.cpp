/*
 * File:   BornesGUI.cpp
 * Author: Carlos Alfredo Escalante Castillo
 *
 * Created on April 15, 2024, 12:42 a.m.
 */

#include "BornesGUI.h"
#include "BorneException.h"
#include "BorneFontaineAjouter.h"
#include "BorneStationnementAjouter.h"
#include "SupprimerBorne.h"
#include "BorneFontaine.h"
#include "BorneStationnement.h"
#include <QMessageBox>
#include <sstream>

BornesGUI::BornesGUI(): m_registre("bornes de l'agglomération de la ville de Québec")
{    
    widget.setupUi (this);
}

BornesGUI::~BornesGUI () { }


void BornesGUI::dialogBorneFontaine()
{
    BorneFontaineAjouter borneFontaine;
    if (borneFontaine.exec())
    {
        bornesQuebec::BorneFontaine newBorneFontaine(
            borneFontaine.reqIdentifiant(),
            borneFontaine.reqIdentifiantVoiePublique().toStdString(),
            borneFontaine.reqNomTopographique().toStdString(),
            borneFontaine.reqLongitude(),
            borneFontaine.reqLatitude(),
            borneFontaine.reqVille().toStdString(),
            borneFontaine.reqArrondissement().toStdString());
        try
        {
           m_registre.ajouteBorne(newBorneFontaine);
        }
        catch (bornesQuebec::BorneDejaPresentException& e)
        {
            QString message = e.what();
            QMessageBox::information(this, "ERREUR", message);
        }
    }
    widget.fenetreAffichage->setText(m_registre.reqRegistreBorneFormate().c_str());
}

void BornesGUI::dialogBorneStationnement()
{
    BorneStationnementAjouter borneStationnement;
    if (borneStationnement.exec())
    {
        bornesQuebec::BorneStationnement newBorneStationnement(
            borneStationnement.reqIdentifiant(),
            borneStationnement.reqIdentifiantVoiePublique().toStdString(),
            borneStationnement.reqNomTopographique().toStdString(),
            borneStationnement.reqLongitude(),
            borneStationnement.reqLatitude(),
            borneStationnement.reqNumBorne(),
            borneStationnement.reqCoteRue().toStdString());
        try
        {
            m_registre.ajouteBorne(newBorneStationnement);        
        }
        catch (bornesQuebec::BorneDejaPresentException& e)
        {
            QString message = e.what();
            QMessageBox::information(this, "ERREUR", message);
        }
    }
    widget.fenetreAffichage->setText(m_registre.reqRegistreBorneFormate().c_str());

}

void BornesGUI::dialogSupprimerBorne()
{
    SupprimerBorne borneSupprimer;
    if (borneSupprimer.exec())
    {
        try
        {
            m_registre.supprimeBorne(borneSupprimer.reqIdentifiant());
        }
        catch (bornesQuebec::BorneAbsenteException& e)
        {
            QString message = e.what();
            QMessageBox::information(this, "ERREUR", message);
        }
    }
    widget.fenetreAffichage->setText(m_registre.reqRegistreBorneFormate().c_str());
}
