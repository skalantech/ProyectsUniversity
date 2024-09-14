/**
 * \file BorneStationnement.cpp
 * \brief Implémentation de l'interface de la classe BorneStationnement
 * \author Carlos Alfredo Escalante Castillo
 * \version 1.0
 */
#include "BorneStationnement.h"
#include "ContratException.h"
#include "ValidationFormat.h"

#include <sstream>

namespace bornesQuebec
{
 /**
 * \brief Constructeur avec parametre.
 *        Initialisation des paramètres de l'objet BorneStationnement selon les valeurs reçues en paramètre.
 *        Utilise le constructeur de la clase borne pour construire une BorneStationnement
 * \param[in] p_identifiant, l’identifiant de la borne. C'est un entier strictement positif.
 * \param[in] p_identifiantVoiePublique, l’identifiant de la voie publique sur laquelle la borne est située, C’est un objet string qui peut contenir un numéro ou être vide.
 * \param[in] p_nomTopographique, Un objet string. Le nom topographique (générique, liaison, spécifique, direction) du centre de chaussée. Il doit être non vide.
 * \param[in] p_longitude, nombre réel. 
 * \param[in] p_latitude, nombre réel. 
 * \param[in] p_numBorne, Integet indicant le numèro de la borne.
 * \param[in] p_coteRue, Un objet string. Le côté de la rue.        
 * \pre p_numBorne doit avoir au maximum 4 chiffres.
 * \pre p_coteRue doit être un point cardinal valide.
 * \post m_numBorne prend la valeur de p_numBorne.
 * \post m_coteRue prend la valeur de p_coteRue.
 */ 
BorneStationnement::BorneStationnement(int p_identifiant, const std::string& p_identifiantVoiePublique, 
        const std::string& p_nomTopographique, double p_longitude, double p_latitude,
        int p_numBorne, const std::string& p_coteRue):
        Borne(p_identifiant, p_identifiantVoiePublique, p_nomTopographique, p_longitude, p_latitude), m_numBorne(p_numBorne), m_coteRue(p_coteRue) 
{   
    PRECONDITION(p_numBorne<10000);
    PRECONDITION(util::validerPointCardinal(p_coteRue));
    POSTCONDITION(m_numBorne==p_numBorne);
    POSTCONDITION(m_coteRue==p_coteRue);
    INVARIANTS();
}

/**
 * \brief destructeur par defaut.
 */
BorneStationnement::~BorneStationnement () {}

/**
 * \brief Accesseur du numéro de borne
 * \return numéro de la borne
 */
int BorneStationnement::reqNumBorne() const
{
    return m_numBorne;
}

/**
 * \brief Accesseur de cote Rue
 * \return nom de cote Rue
 */
const std::string& BorneStationnement::reqCoteRue() const
{
    return m_coteRue;
}

/**
 * \brief Crée une copie d'une borneStationnement
 * \return Un pointeur de type borne
 */
std::unique_ptr<Borne> BorneStationnement::clone() const
{
    return std::make_unique<BorneStationnement>(*this); // Appel du constructeur copie
}

/**
 * \brief Affichage de base de une borneStationnement.
 * \return Une chaine de caractères décrivant une borneStationnement.
 */
std::string BorneStationnement::reqBorneFormate() const
{
    std::ostringstream os;
    os << "Borne de stationnement\n"
       << "----------------------------------------------\n"
       << Borne::reqBorneFormate()
       << "Numero de la borne : " << reqNumBorne() << '\n'
       << "Cote de la rue : " << reqCoteRue() << '\n';
    return os.str();
}

/**
 * \brief Vérifier les invariants de la classe
 */
void BorneStationnement::verifieInvariant() const
{
    INVARIANT(m_numBorne<10000 && util::validerPointCardinal(m_coteRue));
}
}
