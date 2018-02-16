/********************************************
* Titre: Travail pratique #3 - Fournisseur.cpp
* Date: 
* Auteur:
*******************************************/
#include "Fournisseur.h" 

Fournisseur::Fournisseur(const string&  nom, const string& prenom, 
    int identifiant, const string& codePostal) 
    : Usager(nom, prenom, identifiant, codePostal)
{
    for (int i = 0; i < NIVEAUX_SATISFACTION; i++)
        satisfaction_.niveaux_[i] = 0;
}

vector<Produit*> Fournisseur::obtenirCatalogue() const
{
    return contenuCatalogue_;
}

Satisfaction Fournisseur::obternirSatisfaction() const
{
    return satisfaction_;
}

void Fournisseur::noter(int appreciation)
{
    satisfaction_.niveaux_[appreciation]++;
} 

void Fournisseur::ajouterProduit(Produit* produit)
{
    contenuCatalogue_.push_back(produit);
}

void Fournisseur::enleverProduit(Produit* produit)
{
    bool found = false;
    for (int i = 0; i < contenuCatalogue_.size() || found = true; i++) 
        if (*produit == *contenuCatalogue_[i]) {
            contenuCatalogue_[i] = contenuCatalogue_[contenuCatalogue_.size() - 1];
            contenuCatalogue_.pop_back();
            found = true;
        }
}

Fournisseur& Fournisseur::operator=(const Fournisseur& fournisseur)
{
    satisfaction_ = fournisseur.satisfaction_;
    contenuCatalogue_.clear();
    for (int i = 0; i < fournisseur.contenuCatalogue_.size(); i++)
        contenuCatalogue_.push_back(fournisseur.contenuCatalogue_[i]);
    static_cast<Usager>(*this) = static_cast<Usager>(fournisseur);
}

ostream& operator<<(ostream & os, Fournisseur& fournisseur)
{
    os << "Fournisseur: " << static_cast<Usager>(fournisseur) << "notes ";
    for (int i = 0; i < NIVEAUX_SATISFACTION; i++)
        os << i << ": " << fournisseur.satisfaction_.niveaux_[i] << endl;
        
    return os;
}