/*
 * File:   BorneFontaineAjouter.cpp
 * Author: etudiant
 *
 * Created on April 20, 2024, 2:31 a.m.
 */

#include "BorneFontaineAjouter.h"
#include "Borne.h"
#include <QMessageBox>

BorneFontaineAjouter::BorneFontaineAjouter ()
{
    widget.setupUi (this);
}

BorneFontaineAjouter::~BorneFontaineAjouter () { }

int BorneFontaineAjouter::reqIdentifiant() const
{
    return widget.p_identifiant->value();
}

QString BorneFontaineAjouter::reqIdentifiantVoiePublique() const
{
    return widget.p_identifiantVoiePublique->text();
}

QString BorneFontaineAjouter::reqNomTopographique() const
{
    return widget.p_nomTopographique->text();
}

double BorneFontaineAjouter::reqLongitude() const
{
    return widget.p_longitude->value();
}

double BorneFontaineAjouter::reqLatitude() const
{
    return widget.p_latitude->value();
}

QString BorneFontaineAjouter::reqVille() const
{
    return widget.p_ville->text();
}

QString BorneFontaineAjouter::reqArrondissement() const
{
    return widget.p_arrondissement->text();
}

void BorneFontaineAjouter::valider()
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
    if (reqVille().toLower() == "québec" || reqVille().toLower() == "quebec" || reqVille().toLower() == "qc")
    {
        if (reqArrondissement().isEmpty())
        {
            QString message("L'arrondissement ne doit pas être vide!");
            QMessageBox::information(this, "ERREUR", message);
            return;
        }
    }
    accept();
}