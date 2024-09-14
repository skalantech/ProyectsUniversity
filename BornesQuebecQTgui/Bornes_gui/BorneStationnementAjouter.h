/* 
 * File:   BorneStationnementAjouter.h
 * Author: etudiant
 *
 * Created on April 20, 2024, 2:32 a.m.
 */

#ifndef _BORNESTATIONNEMENTAJOUTER_H
#define _BORNESTATIONNEMENTAJOUTER_H

#include "ui_BorneStationnementAjouter.h"

class BorneStationnementAjouter : public QDialog
{
    Q_OBJECT
public:
    BorneStationnementAjouter();
    virtual ~BorneStationnementAjouter();
    
    int reqIdentifiant() const;
    QString reqIdentifiantVoiePublique() const;
    QString reqNomTopographique() const;
    double reqLongitude() const;
    double reqLatitude() const;
    int reqNumBorne() const;
    QString reqCoteRue() const;

private slots:
    void valider();
private:
    Ui::BorneStationnementAjouter widget;
};

#endif /* _BORNESTATIONNEMENTAJOUTER_H */
