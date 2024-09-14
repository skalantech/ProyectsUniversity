/**
 * \file RegistreBorne.h
 * \brief Déclaration de la classe RegistreBorne
 * \author Carlos Alfredo Escalante Castillo
 */

#ifndef REGISTREBORNE_H
#define REGISTREBORNE_H

#include "Borne.h"

#include <vector>

namespace bornesQuebec
{
class RegistreBorne
{
public:
    RegistreBorne(const std::string& p_nomRegistreBorne);
    RegistreBorne(const RegistreBorne& p_registreBorne);
    const RegistreBorne& operator=(const RegistreBorne& p_registreBorne);
    ~RegistreBorne();
    const std::string& reqNomRegistreBorne() const;
    int reqNombreBornes() const;
    std::string reqRegistreBorneFormate() const;

    void ajouteBorne(const Borne& p_borne);
    void supprimeBorne(int p_identifiant);
    
private:
    std::string m_nomRegistreBorne;
    std::vector<std::unique_ptr<Borne>> m_bornes;
    void verifieInvariant() const;
    bool borneDejaExistante(const Borne& p_Borne) const;
};
}

#endif /* REGISTREBORNE_H */

