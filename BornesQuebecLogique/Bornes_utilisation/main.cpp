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

#include <iostream>
#include <string>

using namespace bornesQuebec;
using namespace std;

int reqIdentifiant();
string reqIdentifiantVoiePublique();
bool estNombre(const std::string& nombreString);
string reqNomTopographique();
double reqLongitude();
double reqLatitude();
string reqVille();
string reqArrondissement();
int reqNumBorne();
string reqCoteRue();

int main ()
{
    cout << "__TP2__" << endl;

    cout << "\n\nExemple d’exécution du programme minimaliste du TP2\n\n";
    int identifiant, numBorne;
    string identifiantVoiePublique, nomTopographique, ville, arrondissement, coteRue, entre;
    double longitude, latitude;
        
    RegistreBorne nouveauRegistre("bornes de l'agglomération de la ville de Québec");
    
    while (true)
    {
        cout << "\nTapez 0, 1 ou 2 pour selectionner le type de borne vous desirez d'enregistrer :\n";
        cout << "0.- Finir l'enregistrement\n";
        cout << "1.- Borne Fontaine\n";
        cout << "2.- Borne Stationnement\n";
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
            nouveauRegistre.ajouteBorne(unBorneFontaine);
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
            nouveauRegistre.ajouteBorne(unBorneStationnement);
            continue;
        }
        else
        {
            continue;
        }
    }
    
    cout << nouveauRegistre.reqRegistreBorneFormate();
    
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
        if (!estNombre(identifiantVoiePublique))
        {
            continue;
        }
        break;
    }
    return identifiantVoiePublique;
}

bool estNombre(const std::string& nombreString)
{
    std::string stringNombre = nombreString;
    for (int i=0; i < stringNombre.size(); i++)
    {
        if (stringNombre[i] != '0' &&
            stringNombre[i] != '1' &&
            stringNombre[i] != '2' &&
            stringNombre[i] != '3' &&
            stringNombre[i] != '4' &&
            stringNombre[i] != '5' &&
            stringNombre[i] != '6' &&
            stringNombre[i] != '7' &&
            stringNombre[i] != '8' &&
            stringNombre[i] != '9')
        {
            return false;
        }       
    }
    return true;
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
