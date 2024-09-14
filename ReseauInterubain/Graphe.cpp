/**
 * \file Graphe.cpp
 * \brief Implémentation d'un graphe orienté.
 * \author IFT-2008 & Carlos Alfredo Escalante Castillo
 * \version 0.1
 * \date Juin-Juillet 2024
 *
 *  Travail pratique numéro 2
 *
 */

#include "Graphe.h"
// vous pouvez inclure d'autres librairies si c'est nécessaire

namespace TP2
{
// Ajoutez l'implémentation de vos méthodes ici.

/**
 * \brief Constructeur avec parametre.
 *        Construction d'un graphe vide.
 * \param nbSommets nombre de sommets (valeur par defaut 10).
 */
Graphe::Graphe(size_t nbSommets_) : noms(), listesAdj(), nbSommets(0), nbArcs(0) {}

/**
 * \brief Destructeur.
 */
Graphe::~Graphe() {}

/**
 * \brief Methode resize,
 *        Redimensione le graphe
 * \param nouvelleTaille, nouvelle taille du reseau.
 */
void Graphe::resize(size_t nouvelleTaille)
{
  noms.resize(nouvelleTaille);
  listesAdj.resize(nouvelleTaille);
  nbSommets = nouvelleTaille;
}

/**
 * \brief Methode nommer,
 *        Nommer un numéro sommet 
 * \param nouvelleTaille, nouvelle taille du reseau.
 * \exception Exception logic_error si sommet supérieur à nbSommets
 */
void Graphe::nommer(size_t sommet, const std::string &nom)
{
  if (sommet > nbSommets - 1) 
  {
    throw std::logic_error("nommer: numéro de sommet invalide");
  }
  noms.at(sommet) = nom;
}

/**
 * \brief Methode ajouterArc,
 *        Ajouter un arc au graphe.
 * \param source.
 * \param destination.
 * \param duree, temps entre la source et la destination.
 * \param cout, coût du trajet dès la source à la destination. 
 * \exception Exception logic_error si sommet ou destination sont supérieurs à nbSommets.
 * \exception Exception logic_error si l'arc existe déjà dans le graphe
 */
void Graphe::ajouterArc(size_t source, size_t destination, float duree, float cout)
{
  if (source > nbSommets - 1 || destination > nbSommets - 1)
  {
    throw std::logic_error("ajouterArc: invalid source ou destination");
  }
  if (arcExiste(source, destination))
  {
    throw std::logic_error("ajouterArc: arc existant");
  }
  auto &liste = listesAdj.at(source);
  Ponderations p{duree, cout};
  liste.emplace_back(destination, p);
  ++nbArcs;
}

/**
 * \brief Methode enleverArc,
 *        enlever un arc du graphe.
 * \param source.
 * \param destination.
 * \exception Exception logic_error si sommet ou destination sont supérieurs à nbSommets.
 * \exception Exception logic_error si l'arc n'est pas présent dans le graphe.
 */
void Graphe::enleverArc(size_t source, size_t destination)
{
  if (source > nbSommets - 1 || destination > nbSommets - 1)
  {
    throw std::logic_error("enleverArc: invalid source ou destination");
  }
  if (!arcExiste(source, destination))
  {
    throw std::logic_error("enleverArc: l'arc n'est pas present");
  }
  for (auto it = listesAdj.at(source).begin(), end = listesAdj.at(destination).end(); it != end; ++it)
  {
    if (it->destination == destination)
    {
      listesAdj.at(source).erase(it);
      --nbArcs;
      return;
    }
  }
  throw std::logic_error("enleverArc: apres la recherche l'arc n'as pas ete trouve");
}

/**
 * \brief Methode arcExiste,
 *        vérifier si un arc éxiste dans le graphe.
 * \param source.
 * \param destination.
 * \exception Exception logic_error si sommet ou destination sont supérieurs à nbSommets.
 * \return true si l'arc existe, false sinon.
 */
bool Graphe::arcExiste(size_t source, size_t destination) const
{
  if (source > nbSommets - 1 || destination > nbSommets - 1)
  {
    throw std::logic_error("arcExiste: invalid source ou destination");
  }
  for (auto arc : listesAdj.at(source))
  {
    if (arc.destination == destination)
    {
      return true;
    }
  }
  return false;
}

/**
 * \brief Methode listerSommetsAdjacents,
 *        faire un vector avec les sommets adjacents au sommet passé en argument.
 * \param sommet.
 * \exception Exception logic_error si sommet est supérieurs à nbSommets.
 * \return un vector avec les sommets adjacents.
 */
std::vector<size_t> Graphe::listerSommetsAdjacents(size_t sommet) const
{
  if (sommet > nbSommets - 1)
  {
    throw std::logic_error("listerSommetsAdjacents: sommet invalide");
  }
  std::vector<size_t> listeSommets;
  for (auto arc : listesAdj.at(sommet))
  {
    listeSommets.push_back(arc.destination);
  }
  return listeSommets;
}

/**
 * \brief Methode getNomSommet,
 *        returne le nom du sommet passé en argument.
 * \param sommet.
 * \exception Exception logic_error si sommet est supérieurs à nbSommets.
 * \return le nom du sommet.
 */
std::string Graphe::getNomSommet(size_t sommet) const
{
  if (sommet > nbSommets - 1)
    throw std::logic_error("getNomSommet: sommet invalide");
  return noms.at(sommet);
}

/**
 * \brief Methode getNumeroSommet,
 *        returne le numéro du sommet passé en argument.
 * \param nom du sommet.
 * \exception Exception logic_error si nom n'existe pas dans le graphe
 * \return le numéro du sommet.
 */
size_t Graphe::getNumeroSommet(const std::string &nom) const
{
  size_t i = 0;
  while (i < nbSommets)
  {
    if (noms.at(i) == nom)
    {
      return i;
    }
    ++i;
  }
  throw std::logic_error("getNumeroSommet: le nom n'existe pas");
}

/**
 * \brief Methode getNombreSommets,
 *        returne le nombre des sommets du graphe.
 * \return le nombre de sommets.
 */
int Graphe::getNombreSommets() const
{
  return (int)nbSommets;
}

/**
 * \brief Methode getNombreArcs,
 *        returne le nombre d'arcs du graphe.
 * \return le nombre d'arcs.
 */
int Graphe::getNombreArcs() const
{
  return (int)nbArcs;
}

/**
 * \brief Methode getPonderationsArc,
 *        returne la ponderation de l'arc entre la source et la destination.
 * \param source.
 * \param destination.
 * \exception Exception logic_error si sommet ou destination sont supérieurs à nbSommets.
 * \return struct Ponderation qui inclu une durée et un coût.
 */
Ponderations Graphe::getPonderationsArc(size_t source, size_t destination) const
{
  if (source > nbSommets - 1 || destination > nbSommets - 1)
  {
    throw std::logic_error("getPonderationsArc: invalid source ou destination");
  }
  for (auto arc : listesAdj.at(source))
  {
    if (arc.destination == destination)
    {
      return arc.poids;
    }
  }
  throw std::logic_error("getPonderationsArc: l'arc n'existe pas dans le graphe");
}
} // Fin du namespace
