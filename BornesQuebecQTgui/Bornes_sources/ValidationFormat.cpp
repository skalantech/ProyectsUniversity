/**
 * \file ValidationFormat.cpp
 * \brief Implémentation de l'interface de la classe ValidationFormat
 * \author Carlos Alfredo Escalante Castillo
 * \version 1.0
 */
#include "ValidationFormat.h"

#include <vector>

namespace util
{
    /**
     * \brief Cette fonction valide le format d'un point cardinal.
     * Les valeurs d'un point cardinal sont: N, S, E, O, "" (chaine vide)
     * 
     * \param p_cardinalite reference constante de type string
     * \return true 
     * \return false 
     */    
    bool validerPointCardinal(const std::string& p_cardinalite)
    {
        if ((p_cardinalite.compare("N") == 0) 
            || (p_cardinalite.compare("S") == 0) 
            || (p_cardinalite.compare("E") == 0) 
            || (p_cardinalite.compare("O") == 0)
            || (p_cardinalite.empty ()))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    
    /**
     * \brief Cette fonction permet de valider les informations contenues dans une ligne
     * au format CSV
     * - ID,NO_BORNE,COTE_RUE,ID_VOIE_PUBLIQUE,NOM_TOPOGRAPHIQUE,LONGITUDE,LATITUDE
     * - COTE_RUE est un point cardinal ou est vide
     * - ID_VOIE_PUBLIQUE est un numéro d'identification mais peut être vide
     * - Les autres champs ne doivent pas être vides
     * - La valeur entière de la longitude doit être -71, celle de la latitude 46
     * 
     * \param p_ligne reference constante de type string
     * \return true 
     * \return false 
     */
    bool valideLigneCVSBorneStationnement (const std::string& p_ligne)
    {
        std::istringstream ss(p_ligne);
        std::string champ;
        
        std::vector<std::string> champs;
        
        while (std::getline(ss, champ, ','))
        {
            champs.push_back (champ);
        }
        
        if (champs.size () != 7)
        {
            return false;
        }
        
        if (!validerPointCardinal (champs[2]) && !champs[2].empty ())
        {
            return false;
        }
                
        if (champs[0].empty () || champs[1].empty () || champs[4].empty () 
            || champs[5].empty () || champs[6].empty ())
        {
            return false;
        }
        
        double longitude, latitude;
        try
        {
            longitude = std::stod (champs[5]);
            latitude = std::stod (champs[6]); 
        }
        catch (...)
        {
            return false;
        }

        if (static_cast<int> (longitude) != -71 || static_cast<int> (latitude) != 46)
        {
            return false;
        }
        
        return true;
    }

    
    /**
     * \brief Cette fonction permet de valider la conformité de fichiers de données au format 
     * CSV contenant des enregistrements correspondant à la localisation et à la description de 
     * bornes de stationnement.
     * Ces fichiers commencent par la liste des champs de ces enregistrements, suivis d'enregistrements 
     * (1 par ligne) et se terminant par une ligne vide.
     * La liste des champs est la suivante:
     * - ID,NO_BORNE,COTE_RUE,ID_VOIE_PUBLIQUE,NOM_TOPOGRAPHIQUE,LONGITUDE,LATITUDE
     * - Les contraintes sur les différents champs sont celles validées par valideLigneCVSBorneStationnement
     * 
     * \param p_fluxBornesStationnement flux d'entree provenant d'un fichier
     * \return true 
     * \return false 
     */
    bool valideFichierBornesStationnement (std::istream& p_fluxBornesStationnement)
    {
        std::string ligne;
        bool estPremiereLigne = true;
        bool aDonnee = false;
                
        while (std::getline(p_fluxBornesStationnement, ligne))
        {
            if (ligne.empty ())
            {
                if (estPremiereLigne)
                {
                    return false;
                }
                if (aDonnee)
                {
                    return true;
                }
                return false;
            }
            
            if (estPremiereLigne)
            {
                if (ligne == "ID,NO_BORNE,COTE_RUE,ID_VOIE_PUBLIQUE,NOM_TOPOGRAPHIQUE,LONGITUDE,LATITUDE")
                {
                    estPremiereLigne = false;
                    aDonnee = true;
                    continue;
                }
                return false;
            }
 
            if (!valideLigneCVSBorneStationnement(ligne))
            {
                return false;
            }            
        }
        return !estPremiereLigne && aDonnee;
    }
}

