/////////////////////////////////////////////////////////////////////////////
//Fichier File.hpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file File.hpp
 * \brief Ce fichier contient une implémentation générique de la classe File
 * \author Carlos Alfredo Escalante Castillo
 * \version 0.1
 * \date mai-juin 2024
 */


namespace tp1 {
 /**
 * \brief Constructeur sans parametre.
 *        Création d'une File de type T vide à partir d'une file circulaire vide.
 */
template<typename T>
File<T>::File() : liste() {
    // Ce constructeur peut rester vide (en utilisant la liste d'initialisation).
}

/**
 * \brief Methode enfiler.
 *        ajouter un élement à la fin de la file.
 * \param[in] element, de type T passé par réference constante
 */
template<typename T>
void File<T>::enfiler(const T& element) {
    // Complété
    liste.ajouterFin(element);
}

/**
 * \brief Methode defiler.
 *        rétirer un élement du début de la File.
 * \return le élement rétiré
 */
template<typename T>
T File<T>::defiler() {
    // Corrigé
    if (taille() < 1) {
        throw std::logic_error("La file est vide");
    }
    T ret = liste.element(1);
    liste.enleverPos(1);
    return ret;
}

/**
 * \brief Methode Taille.
 * \return la taille de la file
 */
template<typename T>
unsigned int File<T>::taille() const {
    // Corrigé
    return liste.taille();
}

/**
 * \brief Surcharge de l'operateur de sortie.
 * \param[in] os, Reférence à un stream de sortie ostream.
 * \param[in] file, un objet de File passé comme reférence constante.
 * \return os, le stream de sortie.
 */
//Ne touchez pas à cette fonction.
template<typename T>
std::ostream& operator<<(std::ostream& os, const File<T>& file) {
    os << file.liste;
    return os;
}

}
