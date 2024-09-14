/**
 * \file DicoSynonymes.cpp
 * \brief Le code des opérateurs du DicoSynonymes.
 * \author IFT-2008, Carlos Alfredo Escalante Castillo
 * \version 0.1
 * \date juillet 2024
 *
 * Travail pratique numéro 3.
 *
 */

#include "DicoSynonymes.h"
#include <algorithm>

namespace TP3 {

/**
 * \brief     Constructeur
 * 
 * \post      Une instance vide de la classe a été initialisée
 * 
 */
DicoSynonymes::DicoSynonymes() : racine(nullptr), nbRadicaux(0) {
}

/**
 * \brief  Constructeur de dictionnaire à partir d'un fichier
 * 
 * \pre    Il y a suffisament de mémoire
 * \pre    Le fichier est ouvert au préalable
 * \param  fichier est un file handle d'un fichier.
 * \post   Si le fichier est ouvert, l'instance de la classe a été initialisée à partir
 *         du fichier de dictionnaire. Sinon, on génère une classe vide.
 * 
 * \exception bad_alloc s'il n'y a pas assez de mémoire
 *  Cette méthode appelle chargerDicoSynonyme !
 */
DicoSynonymes::DicoSynonymes(std::ifstream &fichier) : DicoSynonymes() {
  chargerDicoSynonyme(fichier);
}

// Méthode fournie
/**
 * \brief Charge le dictionnaire de synonymes
 *
 * \pre p_fichier est ouvert
 * \param fichier est un file handle d'un fichier.
 * \post Le dictionnaire est initialisé.
 *
 * \exception invalid_argument si p_fichier n'est pas ouvert
 *
 */
void DicoSynonymes::chargerDicoSynonyme(std::ifstream &fichier) {
  if (!fichier.is_open())
    throw std::logic_error("DicoSynonymes::chargerDicoSynonyme: Le fichier n'est pas ouvert !");

  std::string ligne;
  std::string buffer;
  std::string radical;
  int cat = 1;

  while (!fichier.eof()) // tant qu'on peut lire dans le fichier
  {
    std::getline(fichier, ligne);

    if (ligne == "$") {
      cat = 3;
      std::getline(fichier, ligne);
    }
    if (cat == 1) {
      radical = ligne;
      ajouterRadical(radical);
      cat = 2;
    } else if (cat == 2) {
      std::stringstream ss(ligne);
      while (ss >> buffer)
        ajouterFlexion(radical, buffer);
      cat = 1;
    } else {
      std::stringstream ss(ligne);
      ss >> radical;
      ss >> buffer;
      int position = -1;
      ajouterSynonyme(radical, buffer, position);
      while (ss >> buffer)
        ajouterSynonyme(radical, buffer, position);
    }
  }
}

/**
 * \brief     Destructeur.
 *
 * \post      Une instance de la classe est détruite.
 *
 */
DicoSynonymes::~DicoSynonymes() {
  _detruireArbre(racine);
}

/**
 * \brief     Ajouter un radical au dictionnaire des synonymes
 * \brief     tout en s’assurant de maintenir l'équilibre de l'arbre.
 * 
 * \pre    Il y a suffisament de mémoire.
 * \param  motRadical est le radical string à ajouter.
 * \post   Le mot est ajouté au dictionnaire des synonymes.
 * 
 * \exception bad_alloc si il n'y a pas suffisament de mémoire.
 * \exception logic_error si le radical existe déjà.
 */
void DicoSynonymes::ajouterRadical(const std::string &motRadical) {
  if (_auxAppartient(racine, motRadical))
    throw std::logic_error("ajouterRadical: le radical existe déjà dans le dictionnaire");
  _auxInsererAVL(racine, motRadical);
}

/**
 * \brief  Ajouter une flexion (motFlexion) d'un radical (motRadical) à sa liste de flexions.
 *
 * \pre    Il y a suffisament de mémoire.
 * \param  motRadical est le radical string à ajouter.
 * \param  motFlexion est la flexion string à ajouter.
 * \post   La flexion est ajoutée au dictionnaire des synonymes.
 *
 * \exception bad_alloc si il n'y a pas suffisament de mémoire.
 * \exception logic_error si motFlexion existe déjà ou motRadical n'existe pas.
 */
void DicoSynonymes::ajouterFlexion(const std::string &motRadical, const std::string &motFlexion) {
  auto noeudRadical = _auxAppartient(racine, motRadical);
  if (noeudRadical == nullptr) {
    ajouterRadical(motRadical);
    noeudRadical = _auxAppartient(racine, motRadical);
  }
  for (const auto &flexion: noeudRadical->flexions) {
    if (flexion == motFlexion) throw std::logic_error("ajouterFlexion: flexion deja presente");
  }
  noeudRadical->flexions.push_back(motFlexion);
}

/** 
 * \brief  Ajouter un synonyme (motSynonyme) d'un radical (motRadical)
 * \brief  à un de ses groupes de synonymes.
 * 
 * \pre    Le radical se trouve déjà dans le dictionnaire
 * \       Il y a suffisament de mémoire
 * \param  motRadical est le radical string à ajouter.
 * \param  motSynonyme est le synonyme string à ajouter.
 * \param  numGroupe groupe de synonyme auquel il appartiendra.
 * \post   Le synonyme est ajouté au dictionnaire des synonymes
 * \       Si numGroupe vaut –1, le synonyme est ajouté dans un nouveau groupe de synonymes
 * \       et retourne le numéro de ce nouveau groupe dans numgroupe par référence.
 * 
 * \exception bad_alloc si il n'y a pas suffisament de mémoire
 * \exception logic_error si motSynonyme est déjà dans la liste des synonymes du motRadical
 * \exception logic_error si numGroupe n'est pas correct ou motRadical n'existe pas.
 */
void DicoSynonymes::ajouterSynonyme(const std::string &motRadical, const std::string &motSynonyme, int &numGroupe) {
  auto noeudRadical = _auxAppartient(racine, motRadical);
  if (noeudRadical == nullptr) {
    throw std::logic_error("ajouterSynonyme: motRadical n'est pas present en tant que radical");
  }
  auto noeudSynonym = _auxAppartient(racine, motSynonyme);
  if (noeudSynonym == nullptr) {
    ajouterRadical(motSynonyme);
    noeudSynonym = _auxAppartient(racine, motSynonyme);
  }

  if (numGroupe >= 0) {
    if (numGroupe > (int) groupesSynonymes.size()) {
      throw std::logic_error("ajouterSynonyme: numGroupe n'est pas valide");
    }
    groupesSynonymes.at(numGroupe).emplace_back(noeudSynonym);
  } else if (numGroupe == -1) {
    std::list<NoeudDicoSynonymes *> nouveauGroupe;
    nouveauGroupe.emplace_back(noeudRadical);
    nouveauGroupe.emplace_back(noeudSynonym);
    groupesSynonymes.push_back(nouveauGroupe);
    numGroupe = (int) groupesSynonymes.size() - 1;
    noeudRadical->appSynonymes.push_back(numGroupe);
    noeudSynonym->appSynonymes.push_back(numGroupe);
  } else {
    throw std::logic_error("ajouterSynonyme: numGroupe doit être >= -1");
  }
}

/**
 * \brief     Supprimer un radical du dictionnaire des synonymes
 * \brief     tout en s’assurant de maintenir l'équilibre de l'arbre.
 *
 * \pre    motRadical fait parti de l'arbre.
 * \param  motRadical est le radical string à supprimer.
 * \post   Si le radical appartient au dictionnaire, on l'enlève et on équilibre.
 * \       Il faut libérer la liste des synonymes
 * \       du radical en question ainsi que sa liste des flexions.
 * \       Il faut aussi s’assurer d’éliminer tout pointeur
 * \       pointant sur le nœud contenant le radical.
 *
 * \exception logic_error si l'arbre est vide ou motRadical n'existe pas.
 */
void DicoSynonymes::supprimerRadical(const std::string &motRadical) {
  auto noeudRadical = _auxAppartient(racine, motRadical);
  if (noeudRadical == nullptr) {
    throw std::logic_error("supprimerRadical: l'arbre est vide ou motRadical n'existe pas");
  }
  for (auto &groupe: noeudRadical->appSynonymes) {
    groupesSynonymes.at(groupe).remove(noeudRadical);
  }
  for (auto &flexion: noeudRadical->flexions) {
    supprimerFlexion(motRadical, flexion);
  }
  _auxEnleverAVL(racine, motRadical);
}

/**
 * \brief   Supprimer une flexion (motFlexion) d'un radical
 * \brief   (motRadical) de sa liste de flexions.
 *
 * \pre    motRadical et motFlexion font parti de l'arbre.
 * \param  motRadical est le radical string à supprimer.
 * \param  motFlexion est la flexion string à supprimer.
 * \post   La flexion est enlevée du dictionnaire des synonymes.
 *
 * \exception logic_error si si l'arbre est vide ou
 * \exception motFlexion n'existe pas ou motRadical n'existe pas.
 */
void DicoSynonymes::supprimerFlexion(const std::string &motRadical, const std::string &motFlexion) {
  auto noeudRadical = _auxAppartient(racine, motRadical);
  if (noeudRadical == nullptr) {
    throw std::logic_error("supprimerFlexion: le motRadical n'existe pas");
  }
  auto &flexions = noeudRadical->flexions;
  auto it = std::find(flexions.begin(), flexions.end(), motFlexion);
  if (it == flexions.end()) {
    throw std::logic_error("supprimerFlexion: le motFlexion n'existe pas");
  }
  flexions.erase(it);
}

/**
 * \brief   Retirer motSynonyme faisant partie du numéro de groupe numGroupe du motRadical.
 *
 * \pre    motRadical et motSynonyme existent et motRadical.
 * \pre    a une appartenance au groupe numGroupe.
 * \param  motRadical est le radical string à supprimer.
 * \param  motSynonyme est le synonyme string à supprimer.
 * \param  numGroupe groupe de synonyme auquel il appartient.
 * \post      Le synonyme est enlevé du dictionnaire des synonymes.
 *
 * \exception logic_error si motSynonyme ou motRadical ou numGroupe n'existent pas.
 */
void DicoSynonymes::supprimerSynonyme(const std::string &motRadical, const std::string &motSynonyme, int &numGroupe) {
  auto noeudRadical = _auxAppartient(racine, motRadical);
  if (noeudRadical == nullptr) {
    throw std::logic_error("supprimerSynonyme: motRadical n'est pas present en tant que radical");
  }
  auto noeudSynonym = _auxAppartient(racine, motSynonyme);
  if (noeudSynonym == nullptr) {
    throw std::logic_error("supprimerSynonyme: motSynonyme n'est pas present en tant que radical");
  }

  if (numGroupe < 0 || numGroupe >= (int) groupesSynonymes.size()) {
    throw std::logic_error("supprimerSynonyme: numGroupe n'est pas valide");
  }

  auto &listeSynonymes = groupesSynonymes.at(numGroupe);
  for (auto it = listeSynonymes.begin(); it != listeSynonymes.end(); it++) {
    if ((*it)->radical == motSynonyme) {
      listeSynonymes.erase(it);
      break;
    }
  }
}

/**
 * \brief     Vérifier si le dictionnaire est vide
 *
 * \post      Le dictionnaire est inchangée.
 * \return    true si le dictionnaire et vide, false sinon.
 */
bool DicoSynonymes::estVide() const {
  return nbRadicaux == 0;
}

/**
 * \brief Retourne le nombre de radicaux dans le dictionnaire.
 *
 * \post Le dictionnaire reste inchangé.
 * \return le nombre de radicaux dans le dictionnaire.
 */
int DicoSynonymes::nombreRadicaux() const {
  return nbRadicaux;
}

/**
 * \brief Retourne le radical du mot entré en paramètre.
 *
 * \pre mot est dans la liste des flexions d'un radical.
 * \param mot pour chercher son radical.
 * \post Le dictionnaire reste inchangé.
 * \post Le radical est retournée.
 *
 * \exception logic_error si l'arbre est vide
 * \exception logic_error si la flexion n'est pas dans la liste de flexions du radical
 * \return le radical le plus semblable au mot passé en argument.
 */
std::string DicoSynonymes::rechercherRadical(const std::string &mot) const {
  std::vector<std::string> radicals;
  _parcoursSymetrique(racine, radicals);
  if (radicals.empty()) {
    throw std::logic_error("rechercherRadical: l'arbre est vide");
  }
  std::string meilleurRadical = radicals.at(0);
  float plusSimilaire = similitude(mot, meilleurRadical);
  for (const auto &radical: radicals) {
    float similarite = similitude(mot, radical);
    if (similarite > plusSimilaire) {
      meilleurRadical = radical;
      plusSimilaire = similarite;
    }
  }
  auto flexionPresent = false;
  for (const auto &flexion: getFlexions(meilleurRadical)) {
    if (flexion == mot) {
      flexionPresent = true;
      break;
    }
  }
  if (!flexionPresent) {
    throw std::logic_error("rechercherRadical: la flexion n'est pas dans la liste de flexions du radical");
  }
  return meilleurRadical;
}

/**
 * \brief Retourne un réel entre 0 et 1 qui représente le degré de similitude entre mot1 et mot2 où
 *        0 représente deux mots complétement différents et 1 deux mots identiques.
 *        Vous pouvez utiliser par exemple la distance de Levenshtein, mais ce n'est pas obligatoire !
 * \param mot1 string à comparer
 * \param mot2 string à comparer
 * \post Un réel entre 0 et 1 est retourné
 * \post Le dictionnaire reste inchangé.
 * \return chiffre en 0.0 et 1.0, 0.0: mot1 et mo2 sont totalement different et 1.0: ils sont exactement pareils.
 */
float DicoSynonymes::similitude(const std::string &mot1, const std::string &mot2) const {
  float resultatSimilitude = 0.0;
  int longueurMot1 = (int) mot1.size();
  int longueurMot2 = (int) mot2.size();
  if (longueurMot1 >= longueurMot2) {
    resultatSimilitude = _auxSimilitude(mot1, mot2);
  } else {
    resultatSimilitude = _auxSimilitude(mot2, mot1);
  }
  return resultatSimilitude;
}

/**
 * \brief Donne le nombre de cellules de appSynonymes.
 * \param radical string à chercher le nombre de appSynonymes.
 * \post Le nombre de cellules de appSynonymes pour le radical entré en paramètre est retourné
 * \post Le dictionnaire reste inchangé.
 * \return le nombre de appSynonymes du radical passé en argument.
 */
int DicoSynonymes::getNombreSens(std::string radical) const {
  return (int) _auxAppartient(racine, radical)->appSynonymes.size();
}

/**
 * \brief Donne le premier synonyme du groupe de synonyme de l'emplacement entrée en paramètre.
 * \param radical string à chercher synonyme. 
 * \param position dans le vector appSynonymes.
 * \post un string correspondant au premier synonyme est imprimé
 * \post Le dictionnaire reste inchangé.
 * \return le premier synonyme du radical qui n'est pas le radical.
 */
std::string DicoSynonymes::getSens(std::string radical, int position) const {
  auto noeudRadical = _auxAppartient(racine, radical);
  auto it = groupesSynonymes.at(noeudRadical->appSynonymes[position]).begin();
  it++;
  auto resultatSynonyme = (*it)->radical;
  return resultatSynonyme;
}

/**
 * \brief Donne tous les synonymes du mot entré en paramètre du groupeSynonyme du parametre position
 * \param radical string à chercher synonymes. 
 * \param position dans le vector appSynonymes.
 * \post un vecteur est retourné avec tous les synonymes
 * \post Le dictionnaire reste inchangé.
 * \return vecteur avec tous les synonymes du groupe de synonymes du radical.
 */
std::vector<std::string> DicoSynonymes::getSynonymes(std::string radical, int position) const {
  std::vector<std::string> synonymes;
  auto noeudRadical = _auxAppartient(racine, radical);
  for (auto &synom: groupesSynonymes.at(noeudRadical->appSynonymes[position])) {
    if (synom->radical != radical) {
      synonymes.push_back(synom->radical);
    }
  }
  return synonymes;
}

/**
 * \brief Donne toutes les flexions du mot entré en paramètre
 * \param radical string à chercher flexions.
 * \post un vecteur est retourné avec toutes les flexions
 * \post Le dictionnaire reste inchangé.
 * \return vecteur avec toutes les flexion du radical.
 */
std::vector<std::string> DicoSynonymes::getFlexions(std::string radical) const {
  auto noeud = _auxAppartient(racine, radical);
  std::vector<std::string> flexions;
  for (auto &flexion: noeud->flexions) {
    flexions.push_back(flexion);
  }
  return flexions;
}

/**
 * \brief Indique si l'arbre est équilibré selon le facteur HB(1)
 *
 * \post L'arbre est inchangé
 * \return bool indiquant si l'arbre est AVL
 *
 */
bool DicoSynonymes::estArbreAVL() const {
  return _estArbreAVL(racine);
}

// Mettez l'implantation des autres méthodes (surtout privées) ici.
/**
 * \brief methode auxiliare recursive qui fait un parcour simetrique sur l'arbre
 *
 * \param arbre à parcourir
 * \param vecteur de strings qui va stocker les radicals en ordre
 *
 */
void DicoSynonymes::_parcoursSymetrique(NoeudDicoSynonymes *arbre, std::vector<std::string> &radicals) const {
  if (arbre != nullptr) {
    _parcoursSymetrique(arbre->gauche, radicals); // appel récursif
    radicals.push_back(arbre->radical);              // traitement
    _parcoursSymetrique(arbre->droit, radicals); // appel récursif
  }
}

/**
 * \brief methode auxiliare recursive pour detruire un arbre
 *
 * \param arbre à detruire
 *
 */
void DicoSynonymes::_detruireArbre(NoeudDicoSynonymes *arbre) {
  if (arbre != nullptr) {
    _detruireArbre(arbre->gauche);
    _detruireArbre(arbre->droit);
    delete arbre;
  }
}

/**
 * \brief methode auxiliare recursive pour inserer un radical(noeud) dans l'arbre
 *
 * \param arbre
 * \param radical à inserer
 *
 */
void DicoSynonymes::_auxInsererAVL(NoeudDicoSynonymes *&arbre, const std::string &radical) {
  if (arbre == 0) {
    arbre = new NoeudDicoSynonymes(radical);
    nbRadicaux++;
    return;
  }
  if (radical < arbre->radical)
    _auxInsererAVL(arbre->gauche, radical);
  else if (arbre->radical < radical)
    _auxInsererAVL(arbre->droit, radical);
  else
    throw std::logic_error("Les duplicatats sont interdits");

  _balancer(arbre);
}

/**
 * \brief methode auxiliare recursive pour enlever un radical(noeud) de l'arbre
 *
 * \param arbre
 * \param radical à enlever
 *
 */
void DicoSynonymes::_auxEnleverAVL(NoeudDicoSynonymes *&arbre, const std::string &radical) {
  if (arbre == 0)
    throw std::logic_error("Tentative d'enlever une donnée absente");
  if (radical < arbre->radical)
    _auxEnleverAVL(arbre->gauche, radical);
  else if (arbre->radical < radical)
    _auxEnleverAVL(arbre->droit, radical);
  else if (arbre->gauche != 0 &&
           arbre->droit != 0) {
    _enleverSuccMinDroite(arbre);
  } else {
    NoeudDicoSynonymes *vieuxNoeud = arbre;
    arbre = (arbre->gauche != 0) ? arbre->gauche : arbre->droit;
    delete vieuxNoeud;
    --nbRadicaux;
  }

  _balancer(arbre);
}

/**
 * \brief methode auxiliare recursive pour ecraser la racine avec le successeur minimal à droit
 *
 * \param arbre
 *
 */
void DicoSynonymes::_enleverSuccMinDroite(NoeudDicoSynonymes *arbre) {
  NoeudDicoSynonymes *temp = arbre->droit;
  NoeudDicoSynonymes *parent = arbre;
  while (temp->gauche != 0) {
    parent = temp;
    temp = temp->gauche;
  }
  arbre->radical = temp->radical;
  if (parent->gauche == temp)
    _auxEnleverAVL(parent->gauche, temp->radical);
  else
    _auxEnleverAVL(parent->droit, temp->radical);
}

/**
 * \brief methode auxiliare recursive pour verifier si le radical et present dans l'arbre et le returne
 *
 * \param arbre
 * \param radical à chercher
 * 
 * \return NoeudDicoSynonymes* pointer qui contient le radical
 *
 */
typename DicoSynonymes::NoeudDicoSynonymes *
DicoSynonymes::_auxAppartient(NoeudDicoSynonymes *arbre, const std::string &radical) const {
  if (arbre == nullptr)
    return nullptr;

  if (radical < arbre->radical)
    return _auxAppartient(arbre->gauche, radical);
  else if (arbre->radical < radical)
    return _auxAppartient(arbre->droit, radical);
  else
    return arbre;
}

/**
 * \brief methode auxiliare qui returne l'hauteur d'un sousarbre
 *
 * \param arbre
 * 
 * \return hauteur, information present dans le noeud
 *
 */
int DicoSynonymes::_hauteur(NoeudDicoSynonymes *arbre) const {
  if (arbre == 0)
    return -1;
  return arbre->hauteur;
}

/**
 * \brief methode auxiliare qui fait le balancement d'un arbre AVL
 * \      en performant les rotations correspondantes
 *
 * \param arbre à balancer
 * 
 */
void DicoSynonymes::_balancer(NoeudDicoSynonymes *&arbre) {
  if (_debalancementAGauche(arbre)) {
    if (_sousArbrePencheADroite(arbre->gauche)) {
      _zigZagGauche(arbre);
    } else {
      _zigZigGauche(arbre);
    }
  } else if (_debalancementADroite(arbre)) {
    if (_sousArbrePencheAGauche(arbre->droit)) {
      _zigZagDroit(arbre);
    } else {
      _zigZigDroit(arbre);
    }
  } else
  {
    if (arbre != 0)
      arbre->hauteur = 1 + std::max(_hauteur(arbre->gauche), _hauteur(arbre->droit));
  }
}

/**
 * \brief methode auxiliare qui fait une rotation à droite
 *
 * \param K2 noeud critique
 * 
 */
void DicoSynonymes::_zigZigGauche(NoeudDicoSynonymes *&K2) {
  NoeudDicoSynonymes *K1 = K2->gauche;
  K2->gauche = K1->droit;
  K1->droit = K2;
  K2->hauteur = 1 + std::max(_hauteur(K2->gauche), _hauteur(K2->droit));
  K1->hauteur = 1 + std::max(_hauteur(K1->gauche), K2->hauteur);
  K2 = K1;
}

/**
 * \brief methode auxiliare qui fait une rotation à gauche
 *
 * \param K2 noeud critique
 * 
 */
void DicoSynonymes::_zigZigDroit(NoeudDicoSynonymes *&K2) {
  NoeudDicoSynonymes *K1 = K2->droit;
  K2->droit = K1->gauche;
  K1->gauche = K2;
  K2->hauteur = 1 + std::max(_hauteur(K2->droit), _hauteur(K2->gauche));
  K1->hauteur = 1 + std::max(_hauteur(K1->droit), K2->hauteur);
  K2 = K1;
}

/**
 * \brief methode auxiliare qui fait une double rotation à gauche et puis à droit
 *
 * \param K2 noeud critique
 * 
 */
void DicoSynonymes::_zigZagGauche(NoeudDicoSynonymes *&K3) {
  _zigZigDroit(K3->gauche);
  _zigZigGauche(K3);
}

/**
 * \brief methode auxiliare qui fait une double rotation à droit et puis à gauche
 *
 * \param K2 noeud critique
 * 
 */
void DicoSynonymes::_zigZagDroit(NoeudDicoSynonymes *&K3) {
  _zigZigGauche(K3->droit);
  _zigZigDroit(K3);
}

/**
 * \brief methode auxiliare qui determine s'il y a un debalancement à gauche
 *
 * \param arbre sousarbre à vérifier 
 * 
 * \return true, si débalacement à gauche, false sinon
 * 
 */
bool DicoSynonymes::_debalancementAGauche(NoeudDicoSynonymes *arbre) const {
  if (arbre == 0)
    return false;
  return 1 < _hauteur(arbre->gauche) - _hauteur(arbre->droit);
}

/**
 * \brief methode auxiliare qui determine s'il y a un debalancement à droite
 *
 * \param arbre sousarbre à vérifier 
 * 
 * \return true, si débalacement à droite, false sinon
 * 
 */
bool DicoSynonymes::_debalancementADroite(NoeudDicoSynonymes *arbre) const {
  if (arbre == 0)
    return false;
  return 1 < _hauteur(arbre->droit) - _hauteur(arbre->gauche);
}

/**
 * \brief methode auxiliare qui determine si le sousarbre penche à gauche
 *
 * \param arbre sousarbre à vérifier 
 * 
 * \return true, si penche à gauche, false sinon
 * 
 */
bool DicoSynonymes::_sousArbrePencheAGauche(NoeudDicoSynonymes *arbre) const {
  if (arbre == 0)
    return false;
  return _hauteur(arbre->droit) < _hauteur(arbre->gauche);
}

/**
 * \brief methode auxiliare qui determine si le sousarbre penche à droite
 *
 * \param arbre sousarbre à vérifier 
 * 
 * \return true, si penche à droite, false sinon
 * 
 */
bool DicoSynonymes::_sousArbrePencheADroite(NoeudDicoSynonymes *arbre) const {
  if (arbre == 0)
    return false;
  return _hauteur(arbre->gauche) < _hauteur(arbre->droit);
}

/**
 * \brief methode auxiliare recursive qui determine si le sousarbre est AVL
 *
 * \param arbre sousarbre à vérifier 
 * 
 * \return true, si AVL, false sinon
 * 
 */
bool DicoSynonymes::_estArbreAVL(NoeudDicoSynonymes *arbre) const {
  if (arbre == nullptr) {
    return true;
  }

  if (std::abs(_hauteur(arbre->gauche) - _hauteur(arbre->droit)) <= 1 
      && _estArbreAVL(arbre->gauche) 
      && _estArbreAVL(arbre->droit)) {
    return true;
  }

  return false;
}

/**
 * \brief methode auxiliare qui calcule les similitudes entre deux mots
 * \      une similitude est une lettre sur la même position dans les
 * \      deux mots.
 *
 * \param motPlusLongue
 * \param motPlusCourte
 * 
 * \return float entre 0 et 1 inclusif, 0 totalment different, 1 totalment pareil
 * 
 */
float DicoSynonymes::_auxSimilitude(const std::string &motPlusLongue, const std::string &motPlusCourte) const {
  float resultatSimilitude = 0.0;
  int longueurMotPlusLongue = (int) motPlusLongue.size();
  int longueurMotPlusCourte = (int) motPlusCourte.size();
  int similarites = 0;
  for (int i = 0; i < longueurMotPlusCourte; i++) {
    if (motPlusLongue[i] == motPlusCourte[i]) {
      similarites++;
    }
  }
  resultatSimilitude = (float) similarites / (float) longueurMotPlusLongue;
  return resultatSimilitude;
}

} // Fin du namespace