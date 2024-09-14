/**
 * \file BorneFontaine.cpp
 * \brief Implémentation de l'interface de la classe BorneFontaine
 * \author Carlos Alfredo Escalante Castillo
 * \version 1.0
 */
#include "BorneFontaine.h"
#include "ContratException.h"

#include <sstream>

namespace bornesQuebec
{
/**
 * \brief Constructeur avec parametre.
 *        Initialisation des paramètres de l'objet BorneFontaine selon les valeurs reçues en paramètre.
 *        Utilise le constructeur de la clase borne pour construire une borneFontaine
 * \param[in] p_identifiant, l’identifiant de la borne. C'est un entier strictement positif.
 * \param[in] p_identifiantVoiePublique, l’identifiant de la voie publique sur laquelle la borne est située, C’est un objet string qui peut contenir un numéro ou être vide.
 * \param[in] p_nomTopographique, Un objet string. Le nom topographique (générique, liaison, spécifique, direction) du centre de chaussée. Il doit être non vide.
 * \param[in] p_longitude, nombre réel. 
 * \param[in] p_latitude, nombre réel. 
 * \param[in] p_ville, Un objet string. La ville de la borne.
 * \param[in] p_arrondissement, Un objet string. L'arrondissement de la borne.        
 * \pre p_arrondissement non vide si la ville est Québec.
 * \post m_ville prend la valeur de p_ville.
 * \post m_arrondissement prend la valeur de p_arrondissement.
 */    
BorneFontaine::BorneFontaine(int p_identifiant, const std::string& p_identifiantVoiePublique, 
        const std::string& p_nomTopographique, double p_longitude, double p_latitude, 
        const std::string& p_ville, const std::string& p_arrondissement):
        Borne(p_identifiant, p_identifiantVoiePublique, p_nomTopographique, p_longitude, p_latitude), m_ville(p_ville), m_arrondissement(p_arrondissement) 
{
    if (p_ville == "Québec")
    {
        PRECONDITION(p_arrondissement!="");
    }
    POSTCONDITION(m_ville==p_ville);
    POSTCONDITION(m_arrondissement==p_arrondissement);
    INVARIANTS();
}

/**
 * \brief destructeur par defaut.
 */
BorneFontaine::~BorneFontaine () {}

/**
 * \brief Accesseur de la ville
 * \return nom de la ville
 */
const std::string& BorneFontaine::reqVille() const
{
    return m_ville;
}

/**
 * \brief Accesseur de l'arrondissement
 * \return l'arrondissement
 */
const std::string& BorneFontaine::reqArrondissement() const
{
    return m_arrondissement;
}

/**
 * \brief Crée une copie d'une boneFontaine
 * \return Un pointeur de type borne
 */
std::unique_ptr<Borne> BorneFontaine::clone() const
{
    return std::make_unique<BorneFontaine>(*this); // Appel du constructeur copie
}

/**
 * \brief Affichage de base de une borneFontaine.
 * \return Une chaine de caractères décrivant une borneFontaine.
 */
std:: string BorneFontaine::reqBorneFormate() const
{
    std::ostringstream os;
    os << "Borne fontaine\n"
       << "----------------------------------------------\n"
       << Borne::reqBorneFormate()
       << "Ville : " << reqVille() << '\n'
       << "Arrondissement : " << reqArrondissement() << '\n';
    return os.str();
}

/**
 * \brief Vérifier les invariants de la classe
 */
void BorneFontaine::verifieInvariant() const
{
    if (m_ville == "Québec")
    {
        INVARIANT(m_arrondissement!="");
    }
}
}