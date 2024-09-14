/**
 * \file RegistreBorne.cpp
 * \brief Implémentation de l'interface de la classe RegistreBorne
 * \author Carlos Alfredo Escalante Castillo
 * \version 1.0
 */
#include "RegistreBorne.h"
#include "ContratException.h"

#include <sstream>

using namespace std;

namespace bornesQuebec
{
 /**
 * \brief Constructeur avec parametre.
 *        Initialisation des paramètres de l'objet RegistreBorne selon les valeurs reçues en paramètre.
 * \param[in] p_nomRegistreBorne, l’identifiant du registre de bornes.
 * \pre p_nomRegistreBorne doit être non vide
 * \post m_nomRegistreBorne prend la valeur de p_nomRegistreBorne.
 */ 
RegistreBorne::RegistreBorne(const std::string& p_nomRegistreBorne):
        m_nomRegistreBorne(p_nomRegistreBorne) 
{
    PRECONDITION(!p_nomRegistreBorne.empty());
    POSTCONDITION(m_nomRegistreBorne==p_nomRegistreBorne)
    INVARIANTS();
}

 /**
 * \brief Constructeur de copie.
 *        Initialisation des paramètres de l'objet BorneStationnement selon les valeurs reçues en paramètre.
 * \param[in] p_orig, un autre registre de bornes passé en tant que reference constante
 */ 
RegistreBorne::RegistreBorne(const RegistreBorne& p_registreBorne):
    m_nomRegistreBorne(p_registreBorne.m_nomRegistreBorne) 
{
    for (auto& borne : p_registreBorne.m_bornes)
    {
        ajouteBorne(*borne);
    }
}

/**
 * \brief Opérateor d'assignation, prendre un autre registre de bornes passé en tant que reference constante
 * \return une reference à la classe appelante (this)
 */
const RegistreBorne& RegistreBorne::operator=(const RegistreBorne& p_registreBorne)
{
    if (!(this == &p_registreBorne))
    {
        m_nomRegistreBorne = p_registreBorne.m_nomRegistreBorne;
        m_bornes.clear();
        
        for (auto& borne : p_registreBorne.m_bornes)
        {
            ajouteBorne(*borne);
        }
        POSTCONDITION(m_nomRegistreBorne == p_registreBorne.m_nomRegistreBorne);
    }
    INVARIANTS();
    return *this;
}

/**
 * \brief destructeur par defaut.
 */
RegistreBorne::~RegistreBorne()
{

}

/**
 * \brief Accesseur du nom de regitre de bornes
 * \return nom du registre de bornes
 */
const std::string& RegistreBorne::reqNomRegistreBorne() const
{
    return m_nomRegistreBorne;
}

/**
 * \brief Accesseur de numéro de bornes dans le registre
 * \return numero de bornes dans le registre
 */
int RegistreBorne::reqNombreBornes() const
{
    return m_bornes.size();
}

/**
 * \brief Accesseur de numéro de bornes dans le registre
 * \return numero de bornes dans le registre
 */
void RegistreBorne::ajouteBorne(const Borne& p_borne)
{
    int avantAjoutSize = m_bornes.size();
    m_bornes.push_back(p_borne.clone());
    POSTCONDITION(avantAjoutSize+1==m_bornes.size())
    POSTCONDITION(m_bornes.size()>0)
//    cout << "borne ajouté" << '\n';
    INVARIANTS();
}

/**
 * \brief Affichage de base de une borneStationnement.
 * \return Une chaine de caractères décrivant une borneStationnement.
 */
std::string RegistreBorne::reqRegistreBorneFormate() const
{
    std::ostringstream os;
    os << "\nContenu du registre :\n\nRegistre : " << reqNomRegistreBorne() 
       << "\n\n";
    for (const auto& borne : m_bornes)
    {
        os << "----------------------------------------------\n"
           << borne->reqBorneFormate() << '\n';
    }
    os << "----------------------------------------------\n";
    return os.str();
}

/**
 * \brief Vérifier les invariants de la classe
 */
void RegistreBorne::verifieInvariant() const
{
    INVARIANT(!m_nomRegistreBorne.empty());
}
}
