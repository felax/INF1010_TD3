/********************************************
* Titre: Travail pratique #3 - Client.cpp
* Date: 
* Auteur: 
*******************************************/

#include "Client.h"
#include "Fournisseur.h"


Client::Client(const string&  nom, const string& prenom, int identifiant, 
			   const string& codePostal, long date)
			   :Usager(nom, prenom, identifiant, codePostal), 
			   dateNaissance_{date}
{
	monPanier_ = nullptr;
}


Client::~Client()
{
	if (monPanier_ != nullptr)
		delete monPanier_;
}

Client::Client(const Client & client) :
	Usager(client.obtenirNom(), client.obtenirPrenom(), 
		   client.obtenirIdentifiant(), client.obtenirCodePostal()),	
	dateNaissance_{ client.dateNaissance_ }
{
	if (client.monPanier_ == nullptr)
		monPanier_ = nullptr;
	else {
		monPanier_ = new Panier(client.obtenirIdentifiant());
		for (int i = 0; i < client.monPanier_->obtenirNombreContenu(); i++) {
			monPanier_->ajouter(client.monPanier_->obtenirContenuPanier()[i]);
		}
		//int idClient = this->obtenirIdentifiant(); Ligne inutile?
		monPanier_->modifierTotalAPayer(client.monPanier_->obtenirTotalApayer());
	}
}


// Methodes d'acces
long Client::obtenirDateNaissance() const
{
	return dateNaissance_;
}

Panier * Client::obtenirPanier() const
{
	return monPanier_;
}


// Methodes de modification
void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}

// Autres méthodes
void Client::acheter(ProduitOrdinaire * prod)
{
	if (monPanier_ == nullptr)
		monPanier_ = new Panier(this->obtenirIdentifiant());
	monPanier_->ajouter(prod);
	// obtenir une note aléatoire
	int note = rand() % 5;
	prod->obtenirFournisseur().noter(note);
	// faire la mise à jour de la satisfaction au fournisseur
		
}

void Client::livrerPanier()
{
	monPanier_->livrer();
	delete monPanier_;
	monPanier_ = nullptr;
}


void Client::miserProduit(ProduitAuxEncheres* produitAuxEncheres, double montantMise) {
	// à faire
	if (montantMise > produitAuxEncheres->obtenirPrix()) {
		produitAuxEncheres->modifierPrix(montantMise);
		produitAuxEncheres->modifierIdentifiantClient(this->obtenirIdentifiant());
		if (monPanier_ == nullptr)
			monPanier_ = new Panier(this->obtenirIdentifiant());
		this->monPanier_->ajouter(produitAuxEncheres);
	}
}

Client & Client::operator=(const Client & client)
{
	if (this != &client) {
		Usager temp(*this);
		temp = static_cast<Usager> (client);
		dateNaissance_ = client.obtenirDateNaissance();
		if (client.monPanier_ != nullptr) {
			delete monPanier_;
			monPanier_ = new Panier(obtenirIdentifiant());
			for (int i = 0; i < client.monPanier_->obtenirNombreContenu(); i++) {
				monPanier_->ajouter(client.monPanier_->obtenirContenuPanier()[i]);
			}
		}
		else
			monPanier_ = nullptr;
	}
	return *this;
}


ostream & operator<<(ostream & os, const Client & client)
{
	// à faire
	os << "Client : " << static_cast<Usager>(client) 
	<< "Le panier de " << client.obtenirPrenom();
	if (client.monPanier_ == nullptr)
		os << " est vide!\n";
	else
		os << ":\n" << static_cast<Panier>(*client.monPanier_) << endl
		<< "---->total a payer: " << client.monPanier_->calculerTotalApayer() << endl;
	return os;
}
