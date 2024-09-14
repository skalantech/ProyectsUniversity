/**
 * \file BorneStationnement.h
 * \brief Déclaration de la classe BorneStationnement
 * \author Carlos Alfredo Escalante Castillo
 */

#ifndef BORNESTATIONNEMENT_H
#define BORNESTATIONNEMENT_H

#include "Borne.h"

namespace bornesQuebec
{
class BorneStationnement: public Borne
{
public:
    BorneStationnement(int p_identifiant, const std::string& p_identifiantVoiePublique, 
          const std::string& p_nomTopographique, double p_longitude, double p_latitude,
          int p_numBorne, const std::string& p_coteRue);
    ~BorneStationnement();
    virtual std::unique_ptr<Borne> clone() const;
    virtual std::string reqBorneFormate() const;
    int reqNumBorne() const;
    const std::string& reqCoteRue() const;
private:
    int m_numBorne;
    std::string m_coteRue;
    void verifieInvariant() const;
};
}

#endif /* BORNESTATIONNEMENT_H */

