/**
 * \file validationFormat.h
 * \author Carlos Alfredo Escalante Castillo (escacarlos1982@gmail.com) NI: 537149826
 * \brief Des fonction qui permettent de manipuler des informations de fichiers de 
 *        la base de donnees ouverte de la ville de Quebec.
 *        https://www.donneesquebec.ca/recherche/dataset/vque_8/resource/77f47978-e1ac-4aaa-974b-b3b5dfbf3165
 * \version 0.1
 * \date 2024-02-12
 * 
 * \copyright Copyright (c) 2024
 */

#ifndef VALIDATIONFORMAT_H
#define VALIDATIONFORMAT_H

#include <string>
#include <sstream>

namespace util
{
    bool validerPointCardinal(const std::string& p_cardinalite);
    bool valideLigneCVSBorneStationnement (const std::string& p_ligne);
    bool valideFichierBornesStationnement (std::istream& p_fluxBornesStationnement);
}


#endif /* VALIDATIONFORMAT_H */

