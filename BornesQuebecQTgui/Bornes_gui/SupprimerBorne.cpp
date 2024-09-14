/*
 * File:   SupprimerBorne.cpp
 * Author: etudiant
 *
 * Created on April 20, 2024, 2:34 a.m.
 */

#include "SupprimerBorne.h"
#include <QMessageBox>

SupprimerBorne::SupprimerBorne ()
{
    widget.setupUi (this);
}

SupprimerBorne::~SupprimerBorne () { }

int SupprimerBorne::reqIdentifiant() const
{
    return widget.p_identifiant->value();
}

void SupprimerBorne::valider()
{
    if (reqIdentifiant() < 0)
    {
        QString message("L'identifiant ne doit pas être inferieur à cero!");
        QMessageBox::information(this, "ERREUR", message);
        return;
    }
    accept();
}