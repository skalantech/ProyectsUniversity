/* 
 * File:   BornesGUI.h
 * Author: Carlos Alfredo Escalante Castillo
 *
 * Created on April 15, 2024, 12:42 a.m.
 */

#ifndef _BORNESGUI_H
#define _BORNESGUI_H

#include "ui_BornesGUI.h"
#include "RegistreBorne.h"

class BornesGUI : public QMainWindow
{
    Q_OBJECT
public:
    BornesGUI();
    virtual ~BornesGUI();
    
private slots:
    void dialogBorneFontaine();
    void dialogBorneStationnement();
    void dialogSupprimerBorne();
private:
    Ui::BornesGUI widget;
    bornesQuebec::RegistreBorne m_registre;
};

#endif /* _BORNESGUI_H */
