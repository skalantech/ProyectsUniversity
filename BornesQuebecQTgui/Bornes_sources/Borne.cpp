/**
 * \file Borne.cpp
 * \brief Implémentation de l'interface de la classe Borne
 * \author Carlos Alfredo Escalante Castillo
 * \version 1.0
 */
#include "Borne.h"
#include "ContratException.h"

#include <sstream>

namespace bornesQuebec
{
/**
 * \brief Constructeur avec parametre.
 *        Initialisation des paramètres de l'objet Borne selon les valeurs reçues en paramètre.
 * \param[in] p_identifiant, l’identifiant de la borne. C'est un entier strictement positif.
 * \param[in] p_identifiantVoiePublique, l’identifiant de la voie publique sur laquelle la borne est située, C’est un objet string qui peut contenir un numéro ou être vide.
 * \param[in] p_nomTopographique, Un objet string. Le nom topographique (générique, liaison, spécifique, direction) du centre de chaussée. Il doit être non vide.
 * \param[in] p_longitude, nombre réel. 
 * \param[in] p_latitude, nombre réel. 
 * \pre p_identifiant positif.
 * \pre p_nomTopographique non vide.
 * \post m_identifiant prend la valeur de p_identifiant.
 * \post m_identifiantVoiePublique prend la valeur de p_identifiantVoiePublique.
 * \post m_nomTopographique prend la valeur de p_nomTopographique.
 * \post m_longitude prend la valeur de p_longitude.
 * \post m_latitude prend la valeur de p_latitude.
 */
Borne::Borne (int p_identifiant, const std::string& p_identifiantVoiePublique, 
        const std::string& p_nomTopographique, double p_longitude, double p_latitude):
        m_identifiant(p_identifiant), m_identifiantVoiePublique(p_identifiantVoiePublique), 
        m_nomTopographique(p_nomTopographique), m_longitude(p_longitude), 
        m_latitude(p_latitude) 
{
    PRECONDITION(p_identifiant>=0);
    PRECONDITION(estNombre(p_identifiantVoiePublique))
    PRECONDITION(p_nomTopographique!="");
    POSTCONDITION(m_identifiant==p_identifiant);
    POSTCONDITION(m_identifiantVoiePublique==p_identifiantVoiePublique);
    POSTCONDITION(m_nomTopographique==p_nomTopographique);
    POSTCONDITION(m_longitude==p_longitude);
    POSTCONDITION(m_latitude==p_latitude);
    INVARIANTS();
}

/**
 * \brief destructeur par defaut.
 */
Borne::~Borne () { }

int Borne::reqIdentifiant() const
{
    return m_identifiant;
}

/**
 * \brief Accesseur de l’identifiant de la borne
 * \return identifiant de voie publique
 */
const std::string& Borne::reqIdentifiantVoiePublique() const
{
    return m_identifiantVoiePublique;
}

/**
 * \brief Accesseur du nom topographique
 * \return le nom topographique
 */
const std::string& Borne::reqNomTopographique() const
{
    return m_nomTopographique;
}

/**
 * \brief Accesseur de la logitude
 * \return la longitude
 */
double Borne::reqLongitude() const
{
    return m_longitude;
}

/**
 * \brief Accesseur de la latitude
 * \return la latitude
 */
double Borne::reqLatitude() const
{
    return m_latitude;
}

/**
 * \brief Assigne le nom topographique
 * \param[in] le nouveau nom topographique
 * \pre p_newNomTopographique non vide
 * \post m_nomTopographique prend la valeur de p_newNomTopographique
 */
void Borne::asgNomTopographique(const std::string& p_newNomTopographique)
{
    PRECONDITION(p_newNomTopographique!="");
    m_nomTopographique = p_newNomTopographique;
    POSTCONDITION(m_nomTopographique==p_newNomTopographique);
    INVARIANTS();
}

/**
 * \brief Opérateor égal pour vérifier si une borne et égal une autre passé en paramètre
 * \return boolean indicant true ou false.
 */
bool Borne::operator==(const Borne& borne) const
{
    return m_identifiant == borne.m_identifiant &&
           m_identifiantVoiePublique == borne.m_identifiantVoiePublique &&
           m_nomTopographique == borne.m_nomTopographique &&
           m_longitude == borne.m_longitude &&
           m_latitude == borne.m_latitude;
}

/**
 * \brief Affichage de base de une borne.
 * \return Une chaine de caractères décrivant une borne.
 */
std::string Borne::reqBorneFormate() const
{
    std::ostringstream os;
    if (!reqIdentifiantVoiePublique().empty())
    {
        os << "Identifiant de la borne : " << reqIdentifiant() << '\n' 
           << "Voie publique : " << reqIdentifiantVoiePublique() << '\n' 
           << "Nom topographique : " << reqNomTopographique() << '\n' 
           << "Latitude : " << reqLongitude() << '\n'
           << "Longitude : " << reqLatitude() << '\n';
                     
    }
    else
    {
        os << "Identifiant de la borne : " << reqIdentifiant() << '\n' 
           << "Nom topographique : " << reqNomTopographique() << '\n'
           << "Latitude : " << reqLongitude() << '\n'
           << "Longitude : " << reqLatitude() << '\n';
           
    }
    return os.str();
}

/**
 * \brief Vérifier si le string passé en argument est un nombre
 */
bool Borne::estNombre(const std::string& nombreString)
{
    std::string stringNombre = nombreString;
    for (int i=0; i < stringNombre.size(); i++)
    {
        if (stringNombre[i] != '0' &&
            stringNombre[i] != '1' &&
            stringNombre[i] != '2' &&
            stringNombre[i] != '3' &&
            stringNombre[i] != '4' &&
            stringNombre[i] != '5' &&
            stringNombre[i] != '6' &&
            stringNombre[i] != '7' &&
            stringNombre[i] != '8' &&
            stringNombre[i] != '9')
        {
            return false;
        }       
    }
    return true;
}

/**
 * \brief Vérifier les invariants de la classe
 */
void Borne::verifieInvariant() const
{
    INVARIANT(m_identifiant>=0 && m_nomTopographique!="" && estNombre(m_identifiantVoiePublique));
}

}