/********************************************
* Titre: Travail pratique #3 - Panier.cpp
* Date: 
* Auteur: 
*******************************************/

#include "Panier.h"
using namespace std;

Panier::Panier(int idClient): idClient_{idClient}
{
	totalAPayer_ = 0;
}

Panier::~Panier()
{
	contenuPanier_.clear();
}

// methodes d'accès
vector<Produit*>  Panier::obtenirContenuPanier()const
{
	return contenuPanier_;
}

int Panier::obtenirNombreContenu() const
{
	return (int)contenuPanier_.size();
}


int Panier::obtenirIdClient() const {
	return idClient_;
}

double Panier::obtenirTotalApayer() const {
	return totalAPayer_;
}


double Panier::calculerTotalApayer()
{
	totalAPayer_ = 0;
	for (unsigned int i = 0; i < contenuPanier_.size(); i++) {
		if (contenuPanier_[i]->retournerType() == TypeProduitAuxEncheres) {
			if (idClient_ == static_cast<ProduitAuxEncheres*>
							 (contenuPanier_[i])->obtenirIdentifiantClient())
				totalAPayer_ += contenuPanier_[i]->obtenirPrix();
		}
		else {
			if (static_cast<ProduitOrdinaire*>(contenuPanier_[i])->
												obtenirEstTaxable())
				totalAPayer_ += 
				(contenuPanier_[i]->obtenirPrix() * (1 + TAUX_TAXE));
			else
				totalAPayer_ += contenuPanier_[i]->obtenirPrix();
		}
	}
	return totalAPayer_;
}



void Panier::modifierTotalAPayer(double totalAPayer)
{
	totalAPayer_ = totalAPayer;
}


void Panier::modifierIdClient(int idClient) {
	idClient_ = idClient;
}




void Panier::ajouter(Produit * prod) 
{
	contenuPanier_.push_back(prod);
}

void Panier::livrer()
{
	totalAPayer_ = 0;
	contenuPanier_.clear();
}

Produit* Panier::trouverProduitPlusCher()
{
	if (contenuPanier_.empty())
		return nullptr;

	Produit* prodPlusChere = contenuPanier_[0];
	for (unsigned int i = 1; i < contenuPanier_.size(); i++)
		if (*contenuPanier_[i] > *prodPlusChere)
			prodPlusChere = contenuPanier_[i];

	return prodPlusChere;
}

ostream & operator<<(ostream & os,  const Panier & panier)
{
	for (unsigned int i = 0; i < panier.contenuPanier_.size(); i++) {

		if (panier.contenuPanier_[i]->retournerType() == TypeProduitAuxEncheres)
			os << *static_cast<ProduitAuxEncheres*>(panier.contenuPanier_[i]);

		else
			os << *static_cast<ProduitOrdinaire*>(panier.contenuPanier_[i]); 
		os << endl << endl;
	}
	return os;
}
