/********************************************
* Titre: Travail pratique #3 - ProduitAuxEncheres.cpp
* Date: 
* Auteur:
*******************************************/

#include "ProduitAuxEncheres.h"

ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur& fournisseur, 
    const string& nom, int reference, double prix, 
    TypeProduit type, double prixBase, 
    int identifiantClient)
    : Produit(fournisseur, nom, reference, prix, type)
{
    prixBase_ = prixBase;
    identifiantClient_ = identifiantClient;
}

int ProduitAuxEncheres::obtenirIdentifiantClient() const
{
    return identifiantClient_;
}

double ProduitAuxEncheres::obtenirPrixBase() const
{
    return prixBase_;
}

void ProduitAuxEncheres::modifierIdentifiantClient(int identifiantClient)
{
    identifiantClient_ = identifiantClient;
}

void ProduitAuxEncheres::modifierPrixBase(double prixBase)
{
    prixBase_ = prixBase;
}

ostream& operator<<(ostream& os, const ProduitAuxEncheres& produit)
{
	os << "Produit aux encheres " << static_cast<Produit>(produit)
       << "Prix de base " << produit.obtenirPrixBase() << endl
       << "Identifiant Client " << produit.obtenirIdentifiantClient() << endl;
    return os;
}

istream& operator>>(istream& is, ProduitAuxEncheres& produit)
{
    is  >> static_cast<Produit&>(produit);
    return is;
}