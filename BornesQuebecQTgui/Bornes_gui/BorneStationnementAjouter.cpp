/*
 * File:   BorneStationnementAjouter.cpp
 * Author: etudiant
 *
 * Created on April 20, 2024, 2:32 a.m.
 */

#include "BorneStationnementAjouter.h"
#include "Borne.h"
#include "ValidationFormat.h"
#include <QMessageBox>

BorneStationnementAjouter::BorneStationnementAjouter ()
{
    widget.setupUi (this);
}

BorneStationnementAjouter::~BorneStationnementAjouter () { }

int BorneStationnementAjouter::reqIdentifiant() const
{
    return widget.p_identifiant->value();
}

QString BorneStationnementAjouter::reqIdentifiantVoiePublique() const
{
    return widget.p_identifiantVoiePublique->text();
}

QString BorneStationnementAjouter::reqNomTopographique() const
{
    return widget.p_nomTopographique->text();
}

double BorneStationnementAjouter::reqLongitude() const
{
    return widget.p_longitude->value();
}

double BorneStationnementAjouter::reqLatitude() const
{
    return widget.p_latitude->value();
}

int BorneStationnementAjouter::reqNumBorne() const
{
    return widget.p_numBorne->value();
}

QString BorneStationnementAjouter::reqCoteRue() const
{
    return widget.p_coteRue->text();
}

void BorneStationnementAjouter::valider()
{
    if (reqIdentifiant() < 0)
    {
        QString message("L'identifiant ne doit pas être inferieur à cero!");
        QMessageBox::information(this, "ERREUR", message);
        return;
    }
    
    if (!bornesQuebec::Borne::estNombre(reqIdentifiantVoiePublique().toStdString()))
    {
        QString message("L'identifiant de la voie publique doit être un nombre!");
        QMessageBox::information(this, "ERREUR", message);
        return;
    }
    
    if (reqNomTopographique().isEmpty())
    {
        QString message("Le nom topographique ne doit pas être vide!");
        QMessageBox::information(this, "ERREUR", message);
        return;
    }
    
    if (reqNumBorne() > 9999)
    {
        QString message("Le numero de borne doit avoir entre 1 et 4 chiffres!");
        QMessageBox::information(this, "ERREUR", message);
        return;
    }
    
    if (!util::validerPointCardinal(reqCoteRue().toStdString()))
    {
        QString message("Côté de rue invalide choisir entre: N S E O!");
        QMessageBox::information(this, "ERREUR", message);
        return;
    }
    
    accept();
}