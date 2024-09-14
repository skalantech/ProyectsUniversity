/**
 * \file BorneFontaineTesteur.cpp
 * \brief Test unitaire de la classe de base Borne
 * \author Carlos Alfredo Escalante Castillo
 * \date 2024-03-24
 */

#include <gtest/gtest.h>

#include "BorneFontaine.h"
#include "ContratException.h"

#include <iostream>
#include <sstream>

using namespace bornesQuebec;
using namespace std;

/**
 * \test Test du constructeur
 * 		Cas valides: Creation d’un objet BorneFontaine et verification de l’assignation de tous les attributs
 * 		p_arrondissement vide quand la ville n'est pas Québec
 *      cas invalides:
 *      p_arrondissement vide quand la ville est Québec
 */
TEST(BorneFontaine, ConstructeurValide)
{
    BorneFontaine unBorneFontaine(103270, "115066", "Rue Arthur-Dion", 46.848633221772715, -71.36942554972563, "Québec", "La Haute-Saint-Charles");
    ASSERT_EQ(103270, unBorneFontaine.reqIdentifiant());
    ASSERT_EQ("115066", unBorneFontaine.reqIdentifiantVoiePublique());
    ASSERT_EQ("Rue Arthur-Dion", unBorneFontaine.reqNomTopographique());
    ASSERT_EQ(46.848633221772715, unBorneFontaine.reqLongitude());
    ASSERT_EQ(-71.36942554972563, unBorneFontaine.reqLatitude());
    ASSERT_EQ("Québec", unBorneFontaine.reqVille());
    ASSERT_EQ("La Haute-Saint-Charles", unBorneFontaine.reqArrondissement());
}

//Cas invalide
TEST(BorneFontaine, ConstructeurArrondissementInvalide)
{
    ASSERT_THROW(BorneFontaine unBorneFontaine(103270, "115066", "Rue Arthur-Dion", 46.848633221772715, -71.36942554972563, "Québec", ""), ContratException) << "L'arrondissement ne peut pas être vide si la ville et Québec";
}

//Cas valide
TEST(BorneFontaine, ConstructeurArrondissementValide)
{
    ASSERT_NO_THROW(BorneFontaine unBorneFontaine(103270, "115066", "Rue Arthur-Dion", 46.848633221772715, -71.36942554972563, "Ontario", "")) << "L'arrondissement peut être vide si la ville n'est pas Québec";
}

/**
 * \brief Creation d’une fixture a utiliser pour les methodes public de la classe de test
 */
class BorneFontaineValide : public ::testing::Test
{
public:
    BorneFontaineValide(): borneVal(103270, "115066", "Rue Arthur-Dion", 46.848633221772715, -71.36942554972563, "Québec", "La Haute-Saint-Charles")
    {
        
    }
    BorneFontaine borneVal;
};

/**
 * \test Test de la méthode reqVille()
 * 		Cas valide: vérifier le retour de la ville
 * 		Cas invalide: aucun
 */
TEST_F(BorneFontaineValide, reqVille)
{
    ASSERT_EQ("Québec", borneVal.reqVille());
}

/**
 * \test Test de la méthode reqArrondissement()
 * 		Cas valide: vérifier le retour de l`arrondissement
 * 		Cas invalide: aucun
 */
TEST_F(BorneFontaineValide, reqArrondissement)
{
    ASSERT_EQ("La Haute-Saint-Charles", borneVal.reqArrondissement());
}

/**
 * \test Test de la méthode std::string reqBorneFormate();
 * 		Cas valide: vérifier le retour des informations sur l’objet Borne Fontaine formaté
 * 		Cas invalide: aucun
 */
TEST_F(BorneFontaineValide, reqBorneFormate)
{
    std::ostringstream os;
    os << "Borne fontaine\n"
       << "----------------------------------------------\n"
       << "Identifiant de la borne : " << borneVal.reqIdentifiant() << '\n' 
       << "Voie publique : " << borneVal.reqIdentifiantVoiePublique() << '\n' 
       << "Nom topographique : " << borneVal.reqNomTopographique() << '\n' 
       << "Latitude : " << borneVal.reqLongitude() << '\n' 
       << "Longitude : " << borneVal.reqLatitude() << '\n' 
       << "Ville : " << borneVal.reqVille() << '\n'
       << "Arrondissement : " << borneVal.reqArrondissement() << '\n';
    ASSERT_EQ(os.str(), borneVal.reqBorneFormate());
  
    std::string reqFormateLiteral = "Borne fontaine\n----------------------------------------------\nIdentifiant de la borne : 103270\nVoie publique : 115066\nNom topographique : Rue Arthur-Dion\nLatitude : 46.8486\nLongitude : -71.3694\nVille : Québec\nArrondissement : La Haute-Saint-Charles\n";
    std::string reqFormateFunction = borneVal.reqBorneFormate();
    ASSERT_STREQ(reqFormateLiteral.c_str(), reqFormateFunction.c_str());
}

/**
 * \test Test de la méthode clone();
 * 		Cas valide: Cree une copie d'un borne fontaine et returne un pointeur intelligent de ce borne
 * 		Cas invalide: aucun
 */
TEST_F(BorneFontaineValide, clone)
{
    unique_ptr<Borne> unBornePtr = borneVal.clone();
    ASSERT_EQ(unBornePtr->reqIdentifiant(),  borneVal.reqIdentifiant ());
}