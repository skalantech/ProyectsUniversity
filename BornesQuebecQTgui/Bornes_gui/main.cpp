/*
 * File:   main.cpp
 * Author: Carlos Alfredo Escalante Castillo
 *
 * Created on April 15, 2024, 12:34 a.m.
 */

#include <QApplication>
#include "BornesGUI.h"

int main (int argc, char *argv[])
{
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app (argc, argv);

    // create and show your widgets here
    BornesGUI fenetre;
    fenetre.show();
    
    return app.exec ();
}
