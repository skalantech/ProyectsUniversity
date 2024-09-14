/**
 * \file BorneTesteur.cpp
 * \brief Test unitaire de la classe de base Borne
 * \author Carlos Alfredo Escalante Castillo
 * \date 2024-03-24
 */

#include <gtest/gtest.h>

#include "Borne.h"
#include "ContratException.h"

using namespace bornesQuebec;
using namespace std;

/**
 * \class BorneDeTest
 * \brief Classe de test permettant de tester la classe abstraite Employe
 */
class BorneDeTest : public Borne
{
public:
    BorneDeTest (int p_identifiant, const std::string& p_identifiantVoiePublique, 
        const std::string& p_nomTopographique, double p_longitude, double p_latitude):
        Borne(p_identifiant, p_identifiantVoiePublique, p_nomTopographique, p_longitude, p_latitude)
    {

    }
    
    std::unique_ptr<Borne> clone() const
    {
        return std::make_unique<BorneDeTest>(*this);
    }
};

/**
 * \test Test du constructeur
 * 		Cas valides: Creation d’un objet Borne et verification de l’assignation de tous les attributs
 * 		cas invalides:
 * 			Identifiant negatif
 * 			Nom topographique vide
 */
TEST(BorneDeTest, ConstructeurValide)
{
    BorneDeTest unBorne(300070, "100328", "Boulevard René-Levesque Est", 46.814323, -71.226669);
    ASSERT_EQ(300070, unBorne.reqIdentifiant());
    ASSERT_EQ("100328", unBorne.reqIdentifiantVoiePublique());
    ASSERT_EQ("Boulevard René-Levesque Est", unBorne.reqNomTopographique());
    ASSERT_EQ(46.814323, unBorne.reqLongitude());
    ASSERT_EQ(-71.226669, unBorne.reqLatitude());
}

//Cas invalide
TEST(BorneDeTest, ConstructeurIdentifiantInvalide)
{
    ASSERT_THROW(BorneDeTest unBorne(-1, "100328", "Boulevard René-Levesque Est", 46.814323, -71.226669), ContratException) << "L'identifiant ne peut pas être negatif";
}

//Cas invalide
TEST(BorneDeTest, ConstructeurIdentifiantVoiePubliqueInvalide)
{
    ASSERT_THROW(BorneDeTest unBorne(300070, "10A", "Boulevard René-Levesque Est", 46.814323, -71.226669), ContratException) << "L'identifiant de la voie publique doit être un nombre";
}

//Cas invalide
TEST(BorneDeTest, NomTopographiqueInvalide)
{
    ASSERT_THROW(BorneDeTest unBorne(300070, "100328", "", 46.814323, -71.226669), ContratException) << "L'identifiant ne peut pas être negatif";
}

/**
 * \brief Creation d’une fixture a utiliser pour les methodes public de la classe de test
 */
class BorneValide : public ::testing::Test
{
public:
    BorneValide(): borneVal(300070, "100328", "Boulevard René-Levesque Est", 46.814323, -71.226669)
    {
        
    }
    BorneDeTest borneVal;
};

/**
 * \test Test de la méthode asgNomTopographique
 * 		Cas valide: vérifier que la méthode assigne le nouveau nom topographique au membre m_nomTopographique
 *      Cas invalide: p_newNomTopographique est vide
 */
TEST_F(BorneValide, asgNomTopographique)
{
    borneVal.asgNomTopographique("Boulevard Lemire");
    ASSERT_EQ("Boulevard Lemire", borneVal.reqNomTopographique());
}

/**
 * \test Test de la méthode asgNomTopographiqueInvalide
 * 		Cas invalide: vérifier que la méthode thorws une erreur si le nom est vide
 */
TEST_F(BorneValide, asgNomTopographiqueInvalide)
{
    ASSERT_THROW(borneVal.asgNomTopographique(""), ContratException) << "Le nom topographique ne peut pas être vide";
}

/**
 * \test Test de la méthode reqIdentifiant()
 * 		Cas valide: vérifier le retour de l`identifiant de la borne
 * 		Cas invalide: aucun
 */
TEST_F(BorneValide, reqIdentifiant)
{
    ASSERT_EQ(300070, borneVal.reqIdentifiant());
}

/**
 * \test Test de la méthode reqIdentifiantVoiePublique()
 * 		Cas valide: vérifier le retour de l`identifiant de la voie publique
 * 		Cas invalide: aucun
 */
TEST_F(BorneValide, reqIdentifiantVoiePublique)
{
    ASSERT_EQ("100328", borneVal.reqIdentifiantVoiePublique());
}

/**
 * \test Test de la méthode reqNomTopographique()
 * 		Cas valide: vérifier le retour du nom topographique
 * 		Cas invalide: aucun
 */
TEST_F(BorneValide, reqNomTopographique)
{
    ASSERT_EQ("Boulevard René-Levesque Est", borneVal.reqNomTopographique());
}

/**
 * \test Test de la méthode reqLongitude()
 * 		Cas valide: vérifier le retour de la longitude
 * 		Cas invalide: aucun
 */
TEST_F(BorneValide, reqLongitude)
{
    ASSERT_EQ(46.814323, borneVal.reqLongitude());
}

/**
 * \test Test de la méthode reqLatitude()
 * 		Cas valide: vérifier le retour de la latitude
 * 		Cas invalide: aucun
 */
TEST_F(BorneValide, reqLatitude)
{
    ASSERT_EQ(-71.226669, borneVal.reqLatitude());
}

/**
 * \test Test de l'operateur egalité ==
 * 		Cas valide: vérifier le retour du booléen qui vérifie l'égalité entre deux bornes
 * 		Cas invalide: aucun
 */
TEST_F(BorneValide, EqualityTest)
{
    BorneDeTest unBorne(300070, "100328", "Boulevard René-Levesque Est", 46.814323, -71.226669);
    ASSERT_TRUE(unBorne==borneVal);
    ASSERT_TRUE(unBorne.operator==(borneVal));
    BorneDeTest autreBorne(300070, "115066", "Rue Arthur-Dion", 46.848633221772715, -71.36942554972563);
    ASSERT_FALSE(unBorne==autreBorne);
}

/**
 * \test Test de la méthode std::string reqBorneFormate();
 * 		Cas valide: vérifier le retour des informations sur l’objet Borne formaté
 * 		Cas invalide: aucun
 */
TEST_F(BorneValide, reqBorneFormate)
{
    std::ostringstream os;
    os << "Identifiant de la borne : " << borneVal.reqIdentifiant() << '\n' <<
    "Voie publique : " << borneVal.reqIdentifiantVoiePublique() << '\n' << 
    "Nom topographique : " << borneVal.reqNomTopographique() << '\n' <<
    "Latitude : " << borneVal.reqLongitude() << '\n' <<
    "Longitude : " << borneVal.reqLatitude() << '\n';
    ASSERT_EQ(os.str(), borneVal.reqBorneFormate());
    
    std::string reqFormateLiteral = "Identifiant de la borne : 300070\nVoie publique : 100328\nNom topographique : Boulevard René-Levesque Est\nLatitude : 46.8143\nLongitude : -71.2267\n";
    std::string reqFormateFunction = borneVal.reqBorneFormate();
    ASSERT_STREQ(reqFormateLiteral.c_str(), reqFormateFunction.c_str());
}