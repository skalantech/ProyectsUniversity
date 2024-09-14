/**
 * \file Borne.h
 * \brief Déclaration de la classe Borne, La classe Borne représente tous les 
 * types de Bornes présents dans la ville de Québec
 * \author Carlos Alfredo Escalante Castillo
 */

#ifndef BORNE_H
#define BORNE_H

#include <memory>
#include <string>

namespace bornesQuebec
{
class Borne
{
public:
    Borne(int p_identifiant, const std::string& p_identifiantVoiePublique, 
          const std::string& p_nomTopographique, double p_longitude, double p_latitude);
    virtual ~Borne();
    virtual std::unique_ptr<Borne> clone() const = 0;
    virtual std::string reqBorneFormate() const;
    int reqIdentifiant() const;
    const std::string& reqIdentifiantVoiePublique() const;
    const std::string& reqNomTopographique() const;
    double reqLongitude() const;
    double reqLatitude() const;
    void asgNomTopographique(const std::string& newNomTopographique);
    bool operator==(const Borne& borne) const;    
private:
    int m_identifiant;
    std::string m_identifiantVoiePublique;
    std::string m_nomTopographique;
    double m_longitude;
    double m_latitude;
    void verifieInvariant() const;
    bool estNombre(const std::string& nombreString) const;    
};
}

#endif /* BORNE_H */

