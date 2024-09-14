/* 
 * File:   BorneFontaineAjouter.h
 * Author: etudiant
 *
 * Created on April 20, 2024, 2:31 a.m.
 */

#ifndef _BORNEFONTAINEAJOUTER_H
#define _BORNEFONTAINEAJOUTER_H

#include "ui_BorneFontaineAjouter.h"

class BorneFontaineAjouter : public QDialog
{
    Q_OBJECT
public:
    BorneFontaineAjouter();
    virtual ~BorneFontaineAjouter();
    
    int reqIdentifiant() const;
    QString reqIdentifiantVoiePublique() const;
    QString reqNomTopographique() const;
    double reqLongitude() const;
    double reqLatitude() const;
    QString reqVille() const;
    QString reqArrondissement() const;

private slots:
    void valider();
private:
    Ui::BorneFontaineAjouter widget;
};

#endif /* _BORNEFONTAINEAJOUTER_H */
