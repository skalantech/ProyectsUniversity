/////////////////////////////////////////////////////////////////////////////
//Fichier Case.cpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file Case.cpp
 * \brief Ce fichier contient une implémentation de la classe Case
 * \author Carlos Alfredo Escalante Castillo
 * \version 0.1
 * \date mai-juin 2024
 */

#include "Case.h"

namespace tp1 {
/**
 * \brief Constructeur avec parametre.
 *        Initialisation des paramètres de l'objet Clase selon les valeurs reçues en paramètre.
 * \param[in] p_couleur, couleur d'une case (Rouge, Vert, Bleu, Jaune)
 * \param[in] p_decoration, decoration d'une case (Aucune, Serpent, Echelle)
 */
Case::Case(Case::Couleur p_couleur, Case::Decoration p_decoration) : couleur(p_couleur), decoration(p_decoration) {
    // Ce constructeur peut rester vide (en utilisant la liste d'initialisation).
}

/**
 * \brief destructeur par defaut.
 */
Case::~Case() {
    // Réfléchissez s'il faut faire quelque chose !
}

/**
 * \brief Methode decorationEnLettre.
 *        Fonction pour aider à afficher plus naturellement une case à l'écran.
 * param[in] decoration, la décoration d'une Case.
 */
std::string decorationEnLettre(Case::Decoration decoration) {
    switch (decoration) {
        case Case::Serpent:
            return "S";
        case Case::Echelle:
            return "E";
        default:
            return "A";
    }
}

/**
 * \brief Surcharge de l'operateur de sortie.
 * \param[in] os, Reférence à un stream de sortie ostream.
 * \param[in] uneCase, un objet de Case passé comme reférence constante.
 * \return os, le stream de sortie.
 */
//Ne touchez pas à cette fonction.
std::ostream& operator<<(std::ostream &os, const Case& uneCase) {
    os << "(" << uneCase.couleur << "," << decorationEnLettre(uneCase.decoration) << ")";

    return os;
}

}
