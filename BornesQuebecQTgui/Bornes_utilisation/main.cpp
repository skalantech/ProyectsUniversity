/**
 * \file main.cpp
 * \brief Programme principal pour la création des objets des classes derivees de Borne et le rigistre de Bornes.
 * \author Carlos Alfredo Escalante Castillo
 * \version 1.0
 */
#include <iostream>

#include "Borne.h"
#include "BorneFontaine.h"
#include "BorneStationnement.h"
#include "RegistreBorne.h"
#include "ContratException.h"
#include "ValidationFormat.h"
#include "BorneException.h"

#include <iostream>
#include <string>

using namespace bornesQuebec;
using namespace std;

int reqIdentifiant();
string reqIdentifiantVoiePublique();
string reqNomTopographique();
double reqLongitude();
double reqLatitude();
string reqVille();
string reqArrondissement();
int reqNumBorne();
string reqCoteRue();

int main ()
{
    cout << "__TP3__" << endl;

    cout << "\n\nExemple d’exécution du programme minimaliste du TP3\n\n";
    int identifiant, numBorne;
    string identifiantVoiePublique, nomTopographique, ville, arrondissement, coteRue, entre;
    double longitude, latitude;
        
    RegistreBorne nouveauRegistre("bornes de l'agglomération de la ville de Québec");
    
    while (true)
    {
        cout << "\nTapez 0, 1, 2 ou 3 pour selectionner le type de borne vous desirez d'enregistrer ou effacer:\n";
        cout << "0.- Finir l'enregistrement\n";
        cout << "1.- Borne Fontaine\n";
        cout << "2.- Borne Stationnement\n";
        cout << "3.- Suprimmer une borne du registre\n";
        cout << "4.- Visualiser le registre\n";
        getline (cin, entre);
        if (entre == "0")
        {
            break;
        }
        else if (entre == "1")
        {
            
            cout << "Enregistrement d’une borne fontaine :\n";
            identifiant = reqIdentifiant();
            identifiantVoiePublique = reqIdentifiantVoiePublique();
            nomTopographique = reqNomTopographique();
            longitude = reqLongitude();
            latitude = reqLatitude();
            ville = reqVille();
            arrondissement = reqArrondissement();
            BorneFontaine unBorneFontaine(identifiant, identifiantVoiePublique, nomTopographique, longitude, latitude, ville, arrondissement);
            try
            {
                nouveauRegistre.ajouteBorne(unBorneFontaine);
            }
            catch (BorneDejaPresentException& e)
            {
                cout << e.what();
            }
            continue;
        }
        else if (entre == "2")
        {
            cout << "Enregistrement d’une borne de stationnement :\n";
            identifiant = reqIdentifiant();
            identifiantVoiePublique = reqIdentifiantVoiePublique();
            nomTopographique = reqNomTopographique();
            longitude = reqLongitude();
            latitude = reqLatitude();
            numBorne = reqNumBorne();
            coteRue = reqCoteRue();
            BorneStationnement unBorneStationnement(identifiant, identifiantVoiePublique, nomTopographique, longitude, latitude, numBorne, coteRue);
            try
            {
                nouveauRegistre.ajouteBorne(unBorneStationnement);
            }
            catch (BorneDejaPresentException& e)
            {
                cout << e.what();
            }
            continue;
        }
        else if (entre == "3")
        {
            string entry;
            cout << "Entre l'identifiant de la borne a supprimer :\n";
            getline (cin, entry);
            try
            {
                identifiant = stoi(entry);
            }
            catch (...)
            {
                cout << "Identifiant invalide!\n";
                continue;
            }
            try
            {
                nouveauRegistre.supprimeBorne(identifiant);
                cout << "Borne supprimé avec succes\n";
            }
            catch (BorneAbsenteException& e)
            {
                cout << e.what();
            }           
        }
        else if (entre == "4")
        {
            cout << nouveauRegistre.reqRegistreBorneFormate();
        }
        else
        {
            continue;
        }
    }
    
    cout << "Au revoir!";
    
    return 0;
}

int reqIdentifiant()
{
    string entry;
    int identifiant;
    while (true)
    {
        cout << "Entrez l'identifiant de la borne valide : ";
        getline (cin, entry);
        try
        {
            identifiant = stoi(entry);
        }
        catch (...)
        {
            continue;
        }                    
        if (identifiant <= 0)
        {
            continue;
        }
        break;
    }
    return identifiant;
}

string reqIdentifiantVoiePublique()
{
    string identifiantVoiePublique;
    while (true)
    {
        cout << "Entrez l'identifiant de la Voie Publique de la borne valide : ";
        getline (cin, identifiantVoiePublique);   
        if (!Borne::estNombre(identifiantVoiePublique))
        {
            continue;
        }
        break;
    }
    return identifiantVoiePublique;
}

string reqNomTopographique()
{
    string nomTopographique;
    while (true)
    {
        cout << "Entrez le nom topographique valide : ";
        getline (cin, nomTopographique); 
        if (nomTopographique.empty())
        {
            continue;
        }       
        break;
    }
    return nomTopographique;
}

double reqLongitude()
{
    string entry;
    double longitude;
    while (true)
    {
        cout << "Entrez la longitude : ";
        getline (cin, entry);
        try
        {
            longitude = stod(entry);
        }
        catch (...)
        {
            continue;
        }                            
        break;
    }
    return longitude;
}

double reqLatitude()
{
    string entry;
    double latitude;
    while (true)
    {
        cout << "Entrez la latitude : ";
        getline (cin, entry);
        try
        {
            latitude = stod(entry);
        }
        catch (...)
        {
            continue;
        }                            
        break;
    }
    return latitude;
}


string reqVille()
{
    string ville;
    while (true)
    {
        cout << "Entrez le nom de la ville : ";
        getline (cin, ville);       
        break;
    }
    return ville;
}

string reqArrondissement()
{
    string arrondissement;
    while (true)
    {
        cout << "Entrez le nom de l'arrondissement : ";
        getline (cin, arrondissement);
        if (arrondissement.empty())
        {
            continue;
        }       
        break;
    }
    return arrondissement;
}

int reqNumBorne()
{
    string entry;
    int numBorne;
    while (true)
    {
        cout << "Entrez le numéro de la borne de stationnement : ";
        getline (cin, entry);
        try
        {
            numBorne = stoi(entry);
        }
        catch (...)
        {
            continue;
        }
        if (numBorne > 9999)
        {
            continue;
        }        
        break;
    }
    return numBorne;
}

string reqCoteRue()
{
    string coteRue;
    while (true)
    {
        cout << "Entrez le cote de la rue (N, S, E, O) : ";
        getline (cin, coteRue);
        if (!util::validerPointCardinal(coteRue))
        {
            continue;
        }       
        break;
    }
    return coteRue;
}
