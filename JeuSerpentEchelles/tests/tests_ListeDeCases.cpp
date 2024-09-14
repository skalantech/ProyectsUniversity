#include "ListeDeCases.h"
#include "Case.h"

#include "gtest/gtest.h"

#include <iostream>

using namespace tp1;
using namespace std;

TEST(ListeDeCases, constructor_default)
{
    ListeDeCases l;
    EXPECT_EQ(0, l.taille());
    EXPECT_EQ(1, l.estVide());
}

TEST(ListeDeCases, ajouterCase)
{
    ListeDeCases l;
    Case c;
    // cout << l << endl;
    l.ajouterCase(c, 1);
    // cout << "add succesfull" << endl;
    EXPECT_EQ(1, l.taille());
    // cout << l << endl;
    // cout << "end test ajouterCase" << endl;
}

TEST(ListeDeCases, ajouterCase_many_at_begining)
{
    ListeDeCases l;
    Case c;
    Case c1(Case::Couleur::Rouge, Case::Decoration::Serpent);
    Case c2(Case::Couleur::Vert, Case::Decoration::Echelle);
    // cout << l << endl;
    l.ajouterCase(c, 1);
    // cout << "add succesfull" << endl;
    EXPECT_EQ(1, l.taille());
    // cout << l << endl;
    l.ajouterCase(c1, 1);
    EXPECT_EQ(2, l.taille());
    // cout << l << endl;
    // cout << "add succesfull" << endl;
    l.ajouterCase(c2, 1);
    EXPECT_EQ(3, l.taille());
    // cout << l << endl;
    // cout << "add succesfull" << endl;
    // cout << "end test ajouterCase" << endl;
}

TEST(ListeDeCases, ajouterCase_end)
{
    ListeDeCases l;
    Case c;
    Case c1(Case::Couleur::Rouge, Case::Decoration::Serpent);
    Case c2(Case::Couleur::Vert, Case::Decoration::Echelle);
    // cout << l << endl;
    l.ajouterCase(c, 1);
    // cout << "add succesfull" << endl;
    EXPECT_EQ(1, l.taille());
    // cout << l << endl;
    l.ajouterCase(c1, 2);
    EXPECT_EQ(2, l.taille());
    // cout << l << endl;
    // cout << "add succesfull" << endl;
    l.ajouterCase(c2, 3);
    EXPECT_EQ(3, l.taille());
    // cout << l << endl;
    // cout << "add succesfull" << endl;
    // cout << "end test ajouterCase" << endl;
}

TEST(ListeDeCases, ajouterCase_middle)
{
    ListeDeCases l;
    Case cDebut;
    l.ajouterCase(cDebut, 1);
    Case cEnd;
    l.ajouterCase(cEnd, 2);
    Case c1(Case::Couleur::Rouge, Case::Decoration::Serpent);
    Case c2(Case::Couleur::Vert, Case::Decoration::Echelle);
    // cout << l << endl;
    l.ajouterCase(c1, 2);
    // cout << "add succesfull" << endl;
    EXPECT_EQ(3, l.taille());
    // cout << l << endl;
    l.ajouterCase(c2, 3);
    EXPECT_EQ(4, l.taille());
    // cout << l << endl;
    // cout << "add succesfull" << endl;
    l.ajouterCase(c2, 3);
    EXPECT_EQ(5, l.taille());
    // cout << l << endl;
    // cout << "add succesfull" << endl;
    // cout << "end test ajouterCase" << endl;
}

TEST(ListeDeCases, ajouterCaseALaFin)
{
    ListeDeCases l;
    Case c;
    Case c1(Case::Couleur::Rouge, Case::Decoration::Serpent);
    Case c2(Case::Couleur::Vert, Case::Decoration::Echelle);
    // cout << l << endl;
    l.ajouterCaseALaFin(c);
    // cout << "add succesfull" << endl;
    EXPECT_EQ(1, l.taille());
    // cout << l << endl;
    l.ajouterCaseALaFin(c1);
    EXPECT_EQ(2, l.taille());
    // cout << l << endl;
    // cout << "add succesfull" << endl;
    l.ajouterCaseALaFin(c2);
    EXPECT_EQ(3, l.taille());
    // cout << l << endl;
    // cout << "add succesfull" << endl;
    // cout << "end test ajouterCase" << endl;
}

TEST(ListeDeCases, enleverCase)
{
    ListeDeCases l;
    Case cDebut;
    l.ajouterCase(cDebut, 1);
    Case cEnd;
    l.ajouterCase(cEnd, 2);
    Case c1(Case::Couleur::Rouge, Case::Decoration::Serpent);
    Case c2(Case::Couleur::Vert, Case::Decoration::Echelle);
    // cout << l << endl;
    l.ajouterCase(c1, 2);
    // cout << "add succesfull" << endl;
    EXPECT_EQ(3, l.taille());
    // cout << l << endl;
    l.ajouterCase(c2, 3);
    EXPECT_EQ(4, l.taille());
    // cout << l << endl;
    // cout << "add succesfull" << endl;
    l.ajouterCase(c2, 3);
    EXPECT_EQ(5, l.taille());
    // cout << l << endl;
    // cout << "add succesfull" << endl;
    l.enleverCase(1);
    EXPECT_EQ(4, l.taille());
    // cout << l << endl;
    // cout << "remove succesfull" << endl;
    l.enleverCase(2);
    EXPECT_EQ(3, l.taille());
    // cout << l << endl;
    // cout << "remove succesfull" << endl;
    l.enleverCase(l.taille());
    EXPECT_EQ(2, l.taille());
    // cout << l << endl;
    // cout << "remove succesfull" << endl;
}

TEST(ListeDeCases, caseA)
{
    ListeDeCases l;
    Case cDebut;
    l.ajouterCase(cDebut, 1);
    Case cEnd;
    l.ajouterCase(cEnd, 2);
    Case c1(Case::Couleur::Rouge, Case::Decoration::Serpent);
    Case c2(Case::Couleur::Vert, Case::Decoration::Echelle);
    l.ajouterCase(c1, 2);
    // cout << "add succesfull" << endl;
    EXPECT_EQ(3, l.taille());
    l.ajouterCase(c2, 3);
    EXPECT_EQ(4, l.taille());
    // cout << "add succesfull" << endl;
    l.ajouterCase(c2, 3);
    EXPECT_EQ(5, l.taille());
    // cout << "add succesfull" << endl;
    // cout << l << endl;
    // cout << "p0: "<< l.caseA(0) << endl;
    // cout << "p1: "<< l.caseA(1) << endl;
    // cout << "p2: "<< l.caseA(2) << endl;
    // cout << "p3: "<< l.caseA(3) << endl;
    // cout << "p4: "<< l.caseA(l.taille() - 1) << endl;
    std::ostringstream os, os1;
    os << l.caseA(1);
    EXPECT_EQ("(2,A)", os.str());
    EXPECT_EQ(1, l.caseA(2).decoration);
    EXPECT_EQ(1, l.caseA(3).couleur);
    EXPECT_EQ(2, l.caseA(4).decoration);
    os1 << l.caseA(l.taille());
    EXPECT_EQ("(2,A)", os1.str());
}

TEST(ListeDeCases, errors_thrown)
{
    ListeDeCases l;
    EXPECT_THROW(l.enleverCase(1), logic_error);
    Case c;
    l.ajouterCaseALaFin(c);
    EXPECT_THROW(l.enleverCase(2), logic_error);
    EXPECT_THROW(l.ajouterCase(c, 0), range_error);
    EXPECT_THROW(l.ajouterCase(c, 3), range_error);
    // cout << l << endl;
    EXPECT_EQ(1, l.taille());
    auto it = l.debut();
    EXPECT_EQ(1, it.positionCourante());
    EXPECT_EQ(1, it.estADerniereCase());
}