/**
 * \file RegistreBorneTesteur.cpp
 * \brief Test unitaire de la classe de base Borne
 * \author Carlos Alfredo Escalante Castillo
 * \date 2024-03-24
 */

#include <gtest/gtest.h>

#include "Borne.h"
#include "RegistreBorne.h"
#include "BorneFontaine.h"
#include "BorneStationnement.h"
#include "ContratException.h"
#include "BorneException.h"

#include <sstream>

using namespace bornesQuebec;
using namespace std;

/**
 * \test Test du constructeur
 * 		Cas valides: Creation d’un objet RegistreBorne et verification de l’assignation de tous les attributs
 *      m_nomRegistreBorne string non vide     
 *      cas invalides:
 *      m_nomRegistreBorne est vide
 */
TEST(RegistreBorne, ConstructeurValide)
{
    RegistreBorne unRegistreBorne("bornes de la ville de Québec 2024");
    ASSERT_EQ("bornes de la ville de Québec 2024", unRegistreBorne.reqNomRegistreBorne ());
}

//Cas invalide
TEST(RegistreBorne, ConstructeurNomRegistreBorneInvalide)
{
    ASSERT_THROW(RegistreBorne unRegistreBorne(""), ContratException) << "Le nom du registre ne peut pas être vide";
}

/**
 * \brief Creation d’une fixture a utiliser pour les methodes public de la classe de test
 */
class RegistreBorneValide: public ::testing::Test
{
public:
    RegistreBorneValide(): registreValide("bornes de la ville de Québec 2024")
    {
    
    }
    
    RegistreBorne registreValide;
};

/**
 * \test Test de la méthode reqNomRegistreBorne()
 * 		Cas valide: vérifier le retour du nom du registre
 * 		Cas invalide: aucun
 */
TEST_F(RegistreBorneValide, reqNomRegistreBorne)
{
    ASSERT_EQ("bornes de la ville de Québec 2024", registreValide.reqNomRegistreBorne());
}

/**
 * \test Test de la méthode ajouteBorne()
 * 		Cas valide: vérifier que le borne passé en paramètre est bien ajouté au registre
 * 		Cas invalide: la borne à ajouter est deja presente dans le registre, BorneDejaPresentException est lancée.
 */
TEST_F(RegistreBorneValide, ajouteBorne)
{
    ASSERT_EQ(0, registreValide.reqNombreBornes());
    BorneFontaine unBorneFontaine(103270, "115066", "Rue Arthur-Dion", 46.848633221772715, -71.36942554972563, "Québec", "La Haute-Saint-Charles");
    BorneStationnement unBorneStationnement(100001, "", "1re Avenue", 46.82899800269792, -71.23627057605484, 4005, "E");
    registreValide.ajouteBorne(unBorneFontaine);
    ASSERT_EQ(1, registreValide.reqNombreBornes());
    registreValide.ajouteBorne(unBorneStationnement);
    ASSERT_EQ(2, registreValide.reqNombreBornes());
    
    // Cas invalide
    ASSERT_THROW(registreValide.ajouteBorne(unBorneFontaine), BorneDejaPresentException) << "Les doublons ne sont pas permis dans le registre";    
}

/**
 * \test Test de la méthode reqNombreBornes()
 * 		Cas valide: vérifier le retour du numéro de bornes dans le registre
 * 		Cas invalide: aucun
 */
TEST_F(RegistreBorneValide, reqNombreBornes)
{
    ASSERT_EQ(0, registreValide.reqNombreBornes());
    BorneFontaine unBorneFontaine(103270, "115066", "Rue Arthur-Dion", 46.848633221772715, -71.36942554972563, "Québec", "La Haute-Saint-Charles");
    BorneStationnement unBorneStationnement(100001, "", "1re Avenue", 46.82899800269792, -71.23627057605484, 4005, "E");
    registreValide.ajouteBorne(unBorneFontaine);
    ASSERT_EQ(1, registreValide.reqNombreBornes());
    registreValide.ajouteBorne(unBorneStationnement);
    ASSERT_EQ(2, registreValide.reqNombreBornes());
}

/**
 * \test Test de la méthode std::string reqBorneFormate();
 * 		Cas valide: vérifier le retour des informations sur l’objets Bornes  dans le registre formaté
 * 		Cas invalide: aucun
 */
TEST_F(RegistreBorneValide, reqRegistreBorneFormate)
{
    BorneFontaine unBorneFontaine(103270, "115066", "Rue Arthur-Dion", 46.848633221772715, -71.36942554972563, "Québec", "La Haute-Saint-Charles");
    BorneStationnement unBorneStationnement(100001, "", "1re Avenue", 46.82899800269792, -71.23627057605484, 4005, "E");
    registreValide.ajouteBorne(unBorneFontaine);
    registreValide.ajouteBorne(unBorneStationnement);
    std::ostringstream os;
    
    os << "\nContenu du registre :\n\nRegistre : " << registreValide.reqNomRegistreBorne() 
       << "\n\n"
       << "----------------------------------------------\n"
       << unBorneFontaine.reqBorneFormate() << '\n'
       << "----------------------------------------------\n"
       << unBorneStationnement.reqBorneFormate() << '\n'
       << "----------------------------------------------\n";

    ASSERT_EQ(os.str(), registreValide.reqRegistreBorneFormate());
}

/**
 * \test Test de la méthode supprimeBorne()
 * 		Cas valide: La borne avec l'identifiant passé en parametre sera supprimée.
 * 		Cas invalide: L'identifiant n'appartient aucunne borne dans le registre, BorneAbsenteException lancée.
 */
TEST_F(RegistreBorneValide, supprimeBorne)
{
    BorneFontaine unBorneFontaine(103270, "115066", "Rue Arthur-Dion", 46.848633221772715, -71.36942554972563, "Québec", "La Haute-Saint-Charles");
    BorneStationnement unBorneStationnement(100001, "", "1re Avenue", 46.82899800269792, -71.23627057605484, 4005, "E");
    registreValide.ajouteBorne(unBorneFontaine);
    ASSERT_EQ(1, registreValide.reqNombreBornes());
    registreValide.ajouteBorne(unBorneStationnement);
    ASSERT_EQ(2, registreValide.reqNombreBornes());
    registreValide.supprimeBorne(103270);
    ASSERT_EQ(1, registreValide.reqNombreBornes());
    registreValide.supprimeBorne(100001);
    ASSERT_EQ(0, registreValide.reqNombreBornes());
    
    // Cas invalide
    ASSERT_THROW(registreValide.supprimeBorne(100001), BorneAbsenteException) << "Impossible d'acceder des elements absents du registre";
    ASSERT_THROW(registreValide.supprimeBorne(103270), BorneAbsenteException) << "Impossible d'acceder des elements absents du registre";
}

