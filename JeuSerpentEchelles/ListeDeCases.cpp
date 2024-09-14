/////////////////////////////////////////////////////////////////////////////
//Fichier ListeDeCases.cpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file ListeDeCases.cpp
 * \brief Ce fichier contient une implémentation de la classe ListeDeCases
 *        J'ai laisse mes impression en tant que commentaire pour faciliter
 *        l'explication de ma demarche au correcteur.
 *        Des tests on été fait au cours de developement aussi mais non pas inclus.
 * \author Carlos Alfredo Escalante Castillo
 * \version 0.1
 * \date mai-juin 2024
 */

#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>

#include "ListeDeCases.h"

using std::string;
using std::ostringstream;
using std::out_of_range;
using std::range_error;

using std::cout;
using std::endl;

namespace tp1 {
/**
 * \brief Constructeur avec parametre.
 *        Construction d'une ListeDeCases vide.
 */
ListeDeCases::ListeDeCases() : m_debut(nullptr), m_fin(nullptr), m_taille(0) {
    // Ce constructeur peut rester vide (en utilisant la liste d'initialisation).
}

/**
 * \brief destructeur.
 */
ListeDeCases::~ListeDeCases() {
    // Complété
    while (!this->estVide()) {
        enleverCase(1);
    }
}

/**
 * \brief Methode Taille.
 * \return la taille de la ListeDeCases
 */
int ListeDeCases::taille() const {
    // Corrigé
    return m_taille;
}

/**
 * \brief Methode Taille.
 * \return true si la ListeDeCases est vide, false sinon.
 */
bool ListeDeCases::estVide() const {
    // Corrigé
    return taille() == 0;
}

/**
 * \brief Methode ajouterCase.
 *        Ajoute un Case à la ListeDeCases.
 * \param[in] uneCase, la Case à ajouter en tant que ref const.
 * \param[in] position, la position dans la liste oû la case doit être ajouté
 * \error std::range_error si la position est hors borne.
 */
void ListeDeCases::ajouterCase(const Case& uneCase, int position) {
    // Complété
    if (position < 1 || position > taille() + 1) {
        throw range_error("ajouterCase: position invalide");
    }

    auto nouveau = new Noeud(uneCase); // Noeud Crée
    
    if (position == 1) {     // ajouter au debut
        nouveau->m_suivant = m_debut;
        if (m_debut != nullptr) {
            m_debut->m_precedent = nouveau;
        }
        m_debut = nouveau;
        if (m_fin == nullptr) {
            m_fin = nouveau;
        }
    } else if (position == taille() + 1) {  // ajouter à la fin
        nouveau->m_precedent = m_fin;
        if (m_fin != nullptr) {
            m_fin->m_suivant = nouveau;
        }
        m_fin = nouveau;
        if (m_debut == nullptr) {
            m_debut = nouveau;
        }
    } else { // insertion au milieu
        auto courant = noeudAt(position);
        nouveau->m_suivant = courant;
        nouveau->m_precedent = courant->m_precedent;
        if (courant->m_precedent != nullptr) {
            courant->m_precedent->m_suivant = nouveau;
        }
        courant->m_precedent = nouveau;
    }
    ++m_taille;
} // Connection des Noeud rétablise

/**
 * \brief Methode ajouterCaseALaFin.
 *        Ajoute la Case à la fin de la ListeDeCases.
 * \param[in] uneCase, la Case à ajouter en tant que ref const.
 */
void ListeDeCases::ajouterCaseALaFin(const Case& uneCase) {
    // Complété
    ajouterCase(uneCase, taille() + 1);
}

/**
 * \brief Methode enleverCase.
 *        Rétirer la Case à la position passée en argument.
 * \param[in] position, la position de la case à rétirer.
 * \error std::logic_error si la position est hors borne.
 */
void ListeDeCases::enleverCase(int position) {
    // Complété
    if (taille() == 0) {
        throw std::logic_error("enleverCase: ListeDeCases est vide");
    }
    if (position < 1 || position > taille()) {
        throw std::logic_error("enleverCase: la position est hors borne");
    }
    auto courant = noeudAt(position);

    if (courant == m_debut) {     // Retirer au debut
        m_debut = courant->m_suivant;
        if (m_debut != nullptr) {
            m_debut->m_precedent = nullptr;
        }
    } else {
        courant->m_precedent->m_suivant = courant->m_suivant;
    }

    if (courant == m_fin) {
        m_fin = courant->m_precedent;
        if (m_fin != nullptr) {
            m_fin->m_suivant = nullptr;
        }
    } else {
        courant->m_suivant->m_precedent = courant->m_precedent;
    }
    delete courant;
    --m_taille;
}

/**
 * \brief Methode caseA.
 * \param[in] position, la position de la case à returner.
 * \return la case à la position passée en argument.
 */
const Case& ListeDeCases::caseA(int position) const {
    // Corrigé
    return noeudAt(position)->m_case;
}

/**
 * \brief Methode auxiliaire noeudAt.
 * \param[in] position, la position du noeud à returner.
 * \return le noeud à la position passée en argument.
 */
ListeDeCases::Noeud* ListeDeCases::noeudAt(int position) const {
    // Corrigé
    if (position < 1 || position > taille()) {
        throw std::range_error("noeudAt: la position est hors borne");
    }

    auto noeud = m_debut;
    
    for (int p = 1; p < position; ++p) {
        noeud = noeud->m_suivant;
    }
    return noeud;
}

// Le reste du code qui utilise surtout l'itérateur est fourni.
// Ajoutez simplement les balises Doxygen.
/**
 * \brief Methode debut.
 * \return un Iterateur au début de la liste.
 */
ListeDeCases::Iterateur ListeDeCases::debut() const {
    return Iterateur(*this);
}

/**
 * \brief Constructeur Iterateur.
 *        Construit un iterateur au debut de la liste passé en argument
 * \param[in] liste, passé en tant que const ref
 */
ListeDeCases::Iterateur::Iterateur(const ListeDeCases& liste) :
        m_liste(liste), m_courant(liste.m_debut) {
}

/**
 * \brief destructeur.
 *        Met le membre m_courant à 0.
 */
ListeDeCases::Iterateur::~Iterateur() {
    m_courant = 0;
}

/**
 * \brief Méthode caseCourante.
 * \return la case courante
 */
const Case& ListeDeCases::Iterateur::caseCourante() const {
    return m_courant->m_case;
}

/**
 * \brief Méthode existeCaseSuivante.
 * \return true si existe une case après la case courante, false sinon.
 */
bool ListeDeCases::Iterateur::existeCaseSuivante() const {
    return (m_courant != 0 && m_courant->m_suivant != 0);
}

/**
 * \brief Surcharge operateur prefix ajouter ++.
 * \return l'iterateur avancé d'une position dans la liste.
 */
ListeDeCases::Iterateur& ListeDeCases::Iterateur::operator++() {
    if (existeCaseSuivante()) {
        m_courant = m_courant->m_suivant;
    } else {
        m_courant = 0;
        throw out_of_range("L'iterateur ne peut pas aller à une case suivante.");
    }
    return *this;
}

/**
 * \brief Methode noeudSuivant.
 * \param[in] couleur de la case du noeud suivant
 * \param[in] distance à la quelle le noeud de couleur se trouve, combien de cases après la case courante
 * \return un pointeur au noeud suivant.
 */
ListeDeCases::Noeud* ListeDeCases::Iterateur::noeudSuivant(Case::Couleur couleur, int& distance) const {
    distance = 0;
    if (m_courant == 0) {
        return 0;
    }

    ListeDeCases::Noeud *suivant = m_courant->m_suivant;
    while (noeudMauvaiseCouleur(suivant, couleur)) {
        suivant = suivant->m_suivant;
        distance++;
    }
    return suivant;
}

/**
 * \brief Methode noeudMauvaiseCouleur.
 * \param[in] noeud, à vérifier
 * \param[in] couleur, vérifier si noeud est de cette couleur.
 * \return true si noeud est de couleur, false sinon.
 */
bool ListeDeCases::Iterateur::noeudMauvaiseCouleur(ListeDeCases::Noeud* noeud, Case::Couleur couleur) const {
    return (noeud != 0 && noeud->m_case.couleur != couleur);
}

/**
 * \brief Methode caseSuivante.
 *        Se déplacer au noeud de la couleur passé en argument
 * \param[in] couleur, du noeud auquel se déplacer.
 * \error si la case n'existe pas
 */
void ListeDeCases::Iterateur::caseSuivante(Case::Couleur couleur) {
    int distance = 0;
    m_courant = noeudSuivant(couleur, distance);
    if (m_courant == 0) {
        ostringstream message;
        message << "L'iterateur ne peut pas aller à une case suivante de couleur " << couleur << ".";
        throw out_of_range(message.str());
    }
}

/**
 * \brief Methode existeCaseSuivante.
 * \param[in] couleur, du noeud auquel vérifier existance.
 * \return true si un noeud de la couleur passé en argument existe, false sinon.
 */
bool ListeDeCases::Iterateur::existeCaseSuivante(Case::Couleur couleur) const {
    int distance = 0;
    return noeudSuivant(couleur, distance) != 0;
}

/**
 * \brief Methode noeudPrecedent.
 * \param[in] couleur, du noeud precedent.
 * \param[in] distance, à la quelle le noeud de couleur se trouve, combien de cases avant la case courante
 * \return un pointeur au noeud precedent.
 */
ListeDeCases::Noeud* ListeDeCases::Iterateur::noeudPrecedent(Case::Couleur couleur, int& distance) const {
    distance = 0;
    if (m_courant == 0) {
        return 0;
    }

    ListeDeCases::Noeud *precedent = m_courant->m_precedent;
    while (noeudMauvaiseCouleur(precedent, couleur)) {
        precedent = precedent->m_precedent;
        distance++;
    }
    return precedent;
}

/**
 * \brief Methode casePrecedente.
 *        Se déplacer au noeud de la couleur passé en argument
 * \param[in] couleur, du noeud auquel se déplacer.
 * \error si la case n'existe pas
 */
void ListeDeCases::Iterateur::casePrecedente(Case::Couleur couleur) {
    int distance;
    m_courant = noeudPrecedent(couleur, distance);
    if (m_courant == 0) {
        ostringstream message;
        message << "L'iterateur ne peut pas aller à une case precedente de couleur " << couleur
                << ".";
        throw out_of_range(message.str());
    }
}

/**
 * \brief Methode existeCasePrecedente.
 * \param[in] couleur, du noeud auquel vérifier existance.
 * \return true si un noeud de la couleur passé en argument existe, false sinon.
 */
bool ListeDeCases::Iterateur::existeCasePrecedente(Case::Couleur couleur) const {
    int distance = 0;
    return noeudPrecedent(couleur, distance) != 0;
}

/**
 * \brief Méthode positionCourante.
 * \return integer indicant la position courante
 */
int ListeDeCases::Iterateur::positionCourante() const {
    Noeud *courant = m_liste.m_debut;
    if (courant == 0)
        throw range_error("positionCourante: La liste est vide");

    int i = 1;
    while (courant != m_courant) {
        courant = courant->m_suivant;
        i++;
    }
    return i;
}

/**
 * \brief Methode estADerniereCase.
 * \return true si la case courante est la dernière, false sinon.
 */
bool ListeDeCases::Iterateur::estADerniereCase() const {
    return m_courant == m_liste.m_fin && m_courant != 0;
}

/**
 * \brief Surcharge de l'operateur de sortie.
 * \param[in] os, Reférence à un stream de sortie ostream.
 * \param[in] liste, un objet de ListeDeCases passé comme reférence constante.
 * \return os, le stream de sortie.
 */
//Ne touchez surtout pas à cette fonction.
std::ostream& operator<<(std::ostream& os, const ListeDeCases& liste) {
    if (liste.estVide()) {
        os << "Liste de cases vide";
    } else {
        ListeDeCases::Iterateur iter = liste.debut();
        while (!iter.estADerniereCase()) {
            os << iter.caseCourante() << "; ";
            ++iter;
        }
        os << iter.caseCourante();
    }

    return os;
}

}
