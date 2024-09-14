/**
 * \file BorneFontaine.h
 * \brief Déclaration de la classe BorneFontaine
 * \author Carlos Alfredo Escalante Castillo
 */

#ifndef BORNEFONTAINE_H
#define BORNEFONTAINE_H

#include "Borne.h"

namespace bornesQuebec
{
class BorneFontaine: public Borne
{
public:
    BorneFontaine(int p_identifiant, const std::string& p_identifiantVoiePublique, 
          const std::string& p_nomTopographique, double p_longitude, double p_latitude, 
          const std::string& p_ville, const std::string& p_arrondissement);
//    BorneFontaine(const BorneFontaine& orig);
    ~BorneFontaine();
    virtual std::unique_ptr<Borne> clone() const;
    virtual std:: string reqBorneFormate() const;
    const std::string& reqVille() const;
    const std::string& reqArrondissement() const;
private:
    std::string m_ville;
    std::string m_arrondissement;
    void verifieInvariant() const;
};
}

#endif /* BORNEFONTAINE_H */

