/* 
 * File:   SupprimerBorne.h
 * Author: etudiant
 *
 * Created on April 20, 2024, 2:34 a.m.
 */

#ifndef _SUPPRIMERBORNE_H
#define _SUPPRIMERBORNE_H

#include "ui_SupprimerBorne.h"

class SupprimerBorne : public QDialog
{
    Q_OBJECT
public:
    SupprimerBorne();
    virtual ~SupprimerBorne();
    
    int reqIdentifiant() const;

private slots:
    void valider();    
private:
    Ui::SupprimerBorne widget;
};

#endif /* _SUPPRIMERBORNE_H */
