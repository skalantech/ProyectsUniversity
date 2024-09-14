/**
 * \file BorneStationnementTesteur.cpp
 * \brief Test unitaire de la classe de base Borne
 * \author Carlos Alfredo Escalante Castillo
 * \date 2024-03-24
 */

#include <gtest/gtest.h>

#include "BorneStationnement.h"
#include "ContratException.h"

#include <iostream>
#include <sstream>

using namespace bornesQuebec;
using namespace std;

/**
 * \test Test du constructeur
 * 		Cas valides: Creation d’un objet BorneStationnement et verification de l’assignation de tous les attributs
 * 		m_numBorne de 4 chiffres ou moins
 *      m_coteRue point cardinal valide
 *      cas invalides:
 *      m_numBorne superieur a 9999
 *      m_coteRue different au N, S, E, O, ou vide
 */
TEST(BorneStationnement, ConstructeurValide)
{
    BorneStationnement unBorneStationnement(100001, "", "1re Avenue", 46.82899800269792, -71.23627057605484, 4005, "E");
    ASSERT_EQ(100001, unBorneStationnement.reqIdentifiant());
    ASSERT_EQ("", unBorneStationnement.reqIdentifiantVoiePublique());
    ASSERT_EQ("1re Avenue", unBorneStationnement.reqNomTopographique());
    ASSERT_EQ(46.82899800269792, unBorneStationnement.reqLongitude());
    ASSERT_EQ(-71.23627057605484, unBorneStationnement.reqLatitude());
    ASSERT_EQ(4005, unBorneStationnement.reqNumBorne());
    ASSERT_EQ("E", unBorneStationnement.reqCoteRue());
}

//Cas invalide
TEST(BorneStationnement, ConstructeurNumeroBornetInvalide)
{
    ASSERT_THROW(BorneStationnement unBorneStationnement(100001, "", "1re Avenue", 46.82899800269792, -71.23627057605484, 10000, "E"), ContratException) << "Le numéro de borne doit être 4 chiffres maximum";
}

//Cas invalide
TEST(BorneStationnement, ConstructeurCoteRueInvalide)
{
    ASSERT_THROW(BorneStationnement unBorneStationnement(100001, "", "1re Avenue", 46.82899800269792, -71.23627057605484, 9999, "H"), ContratException) << "Le point cardinal doit être valide";
}

/**
 * \brief Creation d’une fixture a utiliser pour les methodes public de la classe de test
 */
class BorneStationnementValide : public ::testing::Test
{
public:
    BorneStationnementValide(): borneVal(100001, "", "1re Avenue", 46.82899800269792, -71.23627057605484, 4005, "E")
    {
        
    }
    BorneStationnement borneVal;
};

/**
 * \test Test de la méthode reqNumBorne()
 * 		Cas valide: vérifier le retour du numéro de borne
 * 		Cas invalide: aucun
 */
TEST_F(BorneStationnementValide, reqNumBorne)
{
    ASSERT_EQ(4005, borneVal.reqNumBorne());
}

/**
 * \test Test de la méthode reqCoteRue()
 * 		Cas valide: vérifier le retour du côté de rue
 * 		Cas invalide: aucun
 */
TEST_F(BorneStationnementValide, reqCoteRue)
{
    ASSERT_EQ("E", borneVal.reqCoteRue());
}

/**
 * \test Test de la méthode std::string reqBorneFormate();
 * 		Cas valide: vérifier le retour des informations sur l’objet Borne Stationnement formaté
 * 		Cas invalide: aucun
 */
TEST_F(BorneStationnementValide, reqBorneFormate)
{
    std::ostringstream os;
    os << "Borne de stationnement\n"
       << "----------------------------------------------\n"
       << "Identifiant de la borne : " << borneVal.reqIdentifiant() << '\n'
       << "Nom topographique : " << borneVal.reqNomTopographique() << '\n' 
       << "Latitude : " << borneVal.reqLongitude() << '\n' 
       << "Longitude : " << borneVal.reqLatitude() << '\n' 
       << "Numero de la borne : " << borneVal.reqNumBorne() << '\n'
       << "Cote de la rue : " << borneVal.reqCoteRue() << '\n';
    ASSERT_EQ(os.str(), borneVal.reqBorneFormate());
  

    std::string reqFormateLiteral = "Borne de stationnement\n----------------------------------------------\nIdentifiant de la borne : 100001\nNom topographique : 1re Avenue\nLatitude : 46.829\nLongitude : -71.2363\nNumero de la borne : 4005\nCote de la rue : E\n";
    std::string reqFormateFunction = borneVal.reqBorneFormate();
    ASSERT_STREQ(reqFormateLiteral.c_str(), reqFormateFunction.c_str());
}

/**
 * \test Test de la méthode clone();
 * 		Cas valide: Cree une copie d'un borne de stationnement et returne un pointeur intelligent de ce borne
 * 		Cas invalide: aucun
 */
TEST_F(BorneStationnementValide, clone)
{
    unique_ptr<Borne> unBornePtr = borneVal.clone();
    ASSERT_EQ(unBornePtr->reqIdentifiant(),  borneVal.reqIdentifiant ());
}