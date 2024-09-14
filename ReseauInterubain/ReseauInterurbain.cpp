/**
 * \file ReseauInterurbain.cpp
 * \brief Implémentattion de la classe ReseauInterurbain.
 * \author IFT-2008 & Carlos Alfredo Escalante Castillo
 * \version 0.1
 * \date Juin-Juillet 2024
 *
 *  Travail pratique numéro 2
 *
 */
#include <sstream>
#include <fstream>
#include <algorithm>
#include "ReseauInterurbain.h"
// vous pouvez inclure d'autres librairies si c'est nécessaire

namespace TP2
{
/**
 * \brief Constructeur avec parametre.
 *        Construction d'une ReseauInterurbain vide à partir d'un nom de reseau passé en argument.
 *        Le reseau est un graphe initialisé vide.
 * \param nomReseau nom du reseau, chaine de caractères.
 * \param nbVilles nombre de villes du reseau, (valeur par defaut 10).
 */
ReseauInterurbain::ReseauInterurbain(std::string nom_reseau, size_t nbVilles) : nomReseau(nom_reseau), unReseau()
{
}

/**
 * \brief Destructeur.
 */
ReseauInterurbain::~ReseauInterurbain()
{
}

/**
 * \brief Methode resize,
 *        Redimensione le reseau.
 * \param nouvelleTaille, nouvelle taille du reseau.
 */
void ReseauInterurbain::resize(size_t nouvelleTaille)
{
  unReseau.resize(nouvelleTaille);
}

/**
 * \brief Methode chargerReseau,
 *        charge le reseau à partir d'un fichier texte.
 * \param nouvelleTaille, nouvelle taille du reseau.
 */
void ReseauInterurbain::chargerReseau(std::ifstream &fichierEntree)
{
  if (!fichierEntree.is_open())
    throw std::logic_error("ReseauInterurbain::chargerReseau: Le fichier n'est pas ouvert !");

  std::string buff;

  getline(fichierEntree, nomReseau);
  nomReseau.erase(0, 20); // Enlève: Reseau Interurbain:

  int nbVilles;

  fichierEntree >> nbVilles;
  getline(fichierEntree, buff); // villes

  unReseau.resize(nbVilles);

  getline(fichierEntree, buff); // Liste des villes

  size_t i = 0;

  getline(fichierEntree, buff); // Premiere ville

  while (buff != "Liste des trajets:")
  {
    unReseau.nommer(i, buff);
    getline(fichierEntree, buff);
    i++;
  }

  while (!fichierEntree.eof())
  {
    getline(fichierEntree, buff);
    std::string source = buff;
    getline(fichierEntree, buff);
    std::string destination = buff;

    getline(fichierEntree, buff);
    std::istringstream iss(buff);

    float duree;
    iss >> duree;

    float cout;
    iss >> cout;

    unReseau.ajouterArc(unReseau.getNumeroSommet(source), unReseau.getNumeroSommet(destination), duree, cout);
  }
}

/**
 * \brief Methode rechercheCheminDijkstra, 
 *        cherche le chemin le plus court depuis une source à la destination.
 * \param source, ville de départ
 * \param destination, ville de destination
 * \param dureeCout, true si la durée du trajet est prise en tant que ponderation entre arcs,
 *                   false si le coût du trajet est pris en tant que ponderation entre arcs.
 * \return Chemin, struct avec la liste de ville qui conforment le chemin le plus court,
 *                 la durée totale et/ou le coût total, reussi = true si le chemin a été trouvé, false sinon.
 */
Chemin ReseauInterurbain::rechercheCheminDijkstra(const std::string &source, const std::string &destination, bool dureeCout) const
{
  size_t sizeReseau = (size_t)unReseau.getNombreSommets();
  size_t n_source = unReseau.getNumeroSommet(source);   // trouver le numero de sommet dans le reseau pour la source
  size_t n_destination = unReseau.getNumeroSommet(destination); // trouver le numero de sommet dans le reseau pour la destination
  std::vector<float> distances(sizeReseau, (float)ULLONG_MAX);  // distances initialisées à l'infini
  std::vector<size_t> predecesseurs(sizeReseau, sizeReseau);  // vector de predecesseurs initialisé a la taille du reseau êgal à NIL
  std::set<size_t> non_resolus;
  for (size_t i = 0; i < sizeReseau; ++i)   
  {
    non_resolus.insert(i);  // insertion des tout les sommets dans le vector de non resolus
  }
  distances.at(n_source) = 0.0;   // distance de la source est Zéro
  predecesseurs.at(n_source) = n_source;

  while (!non_resolus.empty())
  {
    auto temp = (float)ULLONG_MAX;
    size_t index_min = *non_resolus.begin();  // prendre un sommet
    for (auto ele : non_resolus)
    {
      if (distances.at(ele) < temp)           // trouver le sommet avec la distance minimale
      {
        index_min = ele;
        temp = distances.at(ele);
      }
    }
    auto courant = index_min;
    non_resolus.erase(courant);
    auto adjacents = unReseau.listerSommetsAdjacents(courant);  
    for (auto voisin : adjacents)             // relachement 
    {
      if (dureeCout)
      {
        float new_distance = distances.at(courant) + unReseau.getPonderationsArc(courant, voisin).duree;
        if (new_distance < distances.at(voisin))
        {
          predecesseurs.at(voisin) = courant;
          distances.at(voisin) = new_distance;
        }
      }
      else
      {
        float new_distance = distances.at(courant) + unReseau.getPonderationsArc(courant, voisin).cout;
        if (new_distance < distances.at(voisin))
        {
          predecesseurs.at(voisin) = courant;
          distances.at(voisin) = new_distance;
        }
      }
    }
  }
  // Reconstruction du chemin
  Chemin cheminTrouve;
  cheminTrouve.reussi = false;
  cheminTrouve.dureeTotale = 0.0;
  cheminTrouve.coutTotal = 0.0;
  size_t i = 0;
  std::stack<std::string> cheminReconstruit;
  while (i < sizeReseau)
  {
    if (predecesseurs.at(i) == sizeReseau)
    {
      ++i;
      continue;
    }
    if (i == n_destination)
    {
      cheminReconstruit.push(unReseau.getNomSommet(i));
      if (dureeCout)
      {
        cheminTrouve.dureeTotale = distances.at(i);
      }
      else
      {
        cheminTrouve.coutTotal = distances.at(i);
      }
      i = predecesseurs.at(i);
      while (i != n_source)
      {
        cheminReconstruit.push(unReseau.getNomSommet(i));
        i = predecesseurs.at(i);
      }
      cheminReconstruit.push(unReseau.getNomSommet(i));
      cheminTrouve.reussi = true;
      break;
    }
    ++i;
  }
  while (!cheminReconstruit.empty())
  {
    cheminTrouve.listeVilles.push_back(cheminReconstruit.top());
    cheminReconstruit.pop();
  }
  return cheminTrouve;
}

/**
 * \brief Methode algorithmeKosaraju, 
 *        cherche les composantes fortement connexes de reseau.
 * \return Un vecteur de vecteur de villes, qui conforment les composantes fortement connexes du graphe.
 */
std::vector<std::vector<std::string>> ReseauInterurbain::algorithmeKosaraju()
{
  Graphe inv = inverse(unReseau);

  // Exploration en profondeur complète du graphe inverse
  std::set<size_t> puits;
  for (int i = 0; i < inv.getNombreSommets(); ++i)
  {
    auto puit = explorer_dfs(inv, (size_t)i);
    puits.insert(puit.top());
  }

  std::vector<std::vector<std::string>> composantes;
  std::vector<bool> visites(unReseau.getNombreSommets(), false);

  // Exploration en profondeur du reseau selon l'ordre de puits obtenue
  while (!puits.empty())
  {
    auto courant = *puits.begin();
    puits.erase(courant);
    if (!visites.at(courant))
    {
      std::vector<size_t> composante;
      std::stack<size_t> sommets_de_composante = explorer_dfs(unReseau, courant);
      // Filtrer les composantes déjà prensentes dans un autre.
      // Étant donné que certaines edges ne sont pas presentes dans le graphe.
      while (!sommets_de_composante.empty())
      {
        if (!visites.at(sommets_de_composante.top()))
        {
          visites.at(sommets_de_composante.top()) = true;
          composante.push_back(sommets_de_composante.top());
        }
        sommets_de_composante.pop();
      }
      sort(composante.begin(), composante.end()); // Tri de composantes selon le numèro de ville original
      std::vector<std::string> nom_composante;
      // Transformation de la pile de sommets de composantes numeriques à chaine de caractères.
      for (auto comp : composante)
      {
        nom_composante.push_back(unReseau.getNomSommet(comp));
      }
      composantes.push_back(nom_composante);
    }
  }

  return composantes;
}

// À compléter au besoin par d'autres méthodes

/**
 * \brief Methode inverse, 
 *        construction d'un graphe inverse à celui passé en argument.
 * \param Le graphe à inverser.
 * \return Le graphe inverse.
 */
Graphe ReseauInterurbain::inverse(Graphe &graphe)
{
  Graphe inverse;
  size_t sizeReseau = unReseau.getNombreSommets();
  inverse.resize(sizeReseau);

  for (size_t i = 0; i < sizeReseau; ++i)
  {
    inverse.nommer(i, unReseau.getNomSommet(i));
  }

  for (size_t i = 0; i < sizeReseau; ++i)
  {
    auto adjacents = unReseau.listerSommetsAdjacents(i);
    for (auto sommet : adjacents)
    {
      auto duree = unReseau.getPonderationsArc(i, sommet).duree;
      auto cout = unReseau.getPonderationsArc(i, sommet).cout;
      inverse.ajouterArc(sommet, i, duree, cout);
    }
  }

  return inverse;
}

/**
 * \brief Methode explorer_dfs, 
 *        exploration en profondeur à partir d'une source numérique.
 * \param graphe, le graphe à explorer.
 * \param n_source, le numéro du sommet source.
 * \return La pile avec l'ordre de sommets abandonées après l'exploration.
 */
std::stack<size_t> ReseauInterurbain::explorer_dfs(Graphe &graphe, size_t n_source) const
{
  std::vector<bool> visites(unReseau.getNombreSommets(), false);
  std::stack<size_t> attente;
  std::stack<size_t> resultat;

  visites.at(n_source) = true;
  attente.push(n_source);

  while (!attente.empty())
  {
    auto courant = attente.top();
    attente.pop();
    auto liste = graphe.listerSommetsAdjacents(courant);
    for (auto voisin : liste)
    {
      if (!visites.at(voisin))
      {
        attente.push(voisin);
        visites.at(voisin) = true;
      }
    }
    resultat.push(courant);
  }

  return resultat;
}
} // Fin du namespace
