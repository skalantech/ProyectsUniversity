#include "DicoSynonymes.h"
#include <gtest/gtest.h>
#include <iostream>

using namespace std;
using namespace TP3;

TEST(DicoSynonymes, general) {
  DicoSynonymes dic;
  cout << dic.estVide() << endl;
  dic.ajouterRadical("Hacer");
  dic.ajouterFlexion("Hacer","Haciendo");
  dic.ajouterFlexion("Hacer","Haces");
  cout << dic << endl;
  cout << dic.getFlexions("Hacer")[0] << dic.getFlexions("Hacer")[1] << endl;
  int n = -1;
  int &numGroupe = n;
  dic.ajouterSynonyme("Hacer", "Ejecutar", numGroupe);
  cout << numGroupe << endl;
  cout << dic.getSens("Hacer", numGroupe) << endl;
  dic.ajouterSynonyme("Hacer", "Realizar", numGroupe);
  cout << dic.getSynonymes("Hacer", numGroupe)[0] << dic.getSynonymes("Hacer", numGroupe)[1] << endl;
  dic.ajouterRadical("jugar");
  cout << dic << endl;
  cout << dic.nombreRadicaux() << endl;
  cout << dic.getNombreSens("Hacer") << endl; 
  cout << dic.getNombreSens("jugar") << endl; 
  cout << dic.similitude("Hacer", "Hacer") << endl;
  cout << dic.similitude("Hacer", "Haces") << endl;
  cout << dic.similitude("Haces", "Hacer") << endl;
  cout << dic.similitude("Hacer", "Haciendo") << endl;
  cout << dic.similitude("Haciendo", "Hacer") << endl;
  cout << dic.rechercherRadical("Haciendo") << endl;
  EXPECT_THROW(dic.rechercherRadical("Haciste"), logic_error);
  ASSERT_TRUE(dic.estArbreAVL());
  EXPECT_EQ(dic.estArbreAVL(), true);
  string radical = "Hacer";
  string flexion = "Haciendo";
  string synonym = "Realizar";
  dic.supprimerFlexion(radical, flexion);
  for (const auto &flex : dic.getFlexions("Hacer")) {
    cout << flex << " ";
  }
  cout << endl;
  dic.supprimerSynonyme(radical, synonym, numGroupe);
  for (const auto &syn : dic.getSynonymes("Hacer", numGroupe)) {
    cout << syn << " ";
  }
  cout << endl;
  cout << dic << endl;
  dic.supprimerRadical(radical);
  cout << dic << endl;
  DicoSynonymes dic2;
  
  cout << dic2 << endl;
  ifstream EntreeFichier;
  EntreeFichier.open("PetitDico.txt", ios::in);
  if (EntreeFichier.is_open())
  {
    dic2.chargerDicoSynonyme(EntreeFichier);
  }
  cout << "Le dictionnaire a ete charge !" << endl;
  cout << "Affichage du dictionnaire: " << endl
        << dic2 << endl;
  EntreeFichier.close();

  cout << "Le même dictionnaire" << endl;
  ifstream fichier("PetitDico.txt");
  if (fichier.is_open())
  {
    cout << "fichier ouvert" << endl;
  }
  DicoSynonymes dic3(fichier);
  cout << dic3 << endl;
  cout << dic3.estVide() << endl;
  fichier.close();

  EXPECT_THROW(dic2.rechercherRadical("Nous"), logic_error);
  cout << dic2.rechercherRadical("poursuivrons") << endl;
  for (const auto &flex : dic2.getFlexions("poursuivre")) {
    cout << flex << " ";
  }
}