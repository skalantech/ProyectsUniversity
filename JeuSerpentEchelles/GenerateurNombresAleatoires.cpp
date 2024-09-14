/////////////////////////////////////////////////////////////////////////////
//Fichier GenerateurNombresAleatoires.cpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file GenerateurNombresAleatoires.cpp
 * \brief Ce fichier contient une implémentation de la classe GenerateurNombresAleatoires
 * \author Carlos Alfredo Escalante Castillo
 * \version 0.1
 * \date mai-juin 2024
 */

#include "GenerateurNombresAleatoires.h"

namespace tp1 {

GenerateurNombresAleatoires::GenerateurNombresAleatoires(unsigned int init, unsigned int max) :
        m_etat(init), m_maxPlusUn(max + 1) {
}

int GenerateurNombresAleatoires::pige() {
    m_etat *= ENTROPIE;
    return m_etat % m_maxPlusUn;
}

}
