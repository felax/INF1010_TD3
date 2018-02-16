/********************************************
* Titre: Travail pratique #3 - ProduitAuxEncheres.cpp
* Date: 
* Auteur:
*******************************************/

#include "ProduitAuxEncheres.h"

ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur& fournisseur, 
    const string& nom = "outil", int reference = 0, double prix = 0.0, 
    TypeProduit type = TypeProduitOrdinaire, double prixBase = 0.0, 
    int identifiantClient = 0)
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

ostream& operator<<(ostream& os, const ProduitAuxEncheres& produit)
{
	os  << static_cast<Produit>(produit)
        << "Prix de base " << produit.obtenirPrixBase << endl
        << "Identifiant Client " << produit.obtenirIdentifiantClient << endl;
    return os;
}

istream& operator>>(istream& is, ProduitAuxEncheres& produit)
{
    is  >> static_cast<Produit&>(produit);
    return is;
}