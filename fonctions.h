#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include <string>
#include <vector>


typedef enum
{
    GBIO,
    MIP,
    GIE,
    GIN
}t_option;


typedef enum
{
    masculin,
    feminin
} t_sexe;


typedef struct
{
    std::string nom;
    std::string prenom;

    t_sexe sexe;

    std::string matricule;
    std::string dateDeNaissance;
    std::string lieuDeNaissance;

    int age;

    t_option option;



} etudiant;

//Menu
void menuPrincipale();
//Sous menu
void menuPrincipaleEtudiant();

//Fonction permet d'otenir le nombre des occureneces d'un nombre dans un tableau de n élémnets
int get_occurence(int t[],int N,int valeur);

//Fonction permet d'imprimer les nombres impaires
void get_nombresImpaires(int tab[], int N);
// fonction qui permet de sommer les éléments précédents et lui-même
int sommeDesElementPrecedent(int sommePrecedent[], int n);
//Fonction qui determine la frequence de caractere
int frequenceDeLettre(std::string chaine, char c);
//fonctions qui determine la taille du fichier
//ofstream::pos_type taille_fichier(const std::string &nom);

//====================================Fichier==================================
//Fonction qui permet de lire la liste des étudian
void lireLaListeEtudiant();

//Fonction qui permet d'ajouter les étudiants
void ajouterEtudiant(std::vector<etudiant> listeEtudiant  , int nbEtudiant);
//Fonction qui permet d'ajouter les étudiants
void ajouterEtudiantDansLaListe();
//Foncfion qui permet de lister tous les etudiants du genre feminin
void listerDesEtudiantsFeminin();


#endif // FONCTIONS_H_INCLUDED


        //=============================================================================================

        // Definitions :
        //      Type :
        //          toption   = (GBIO, MIP, GIE, GIN)
        //         tEtudiant = article:
        //                          nom : chaine
        //                          prenom : chaine
        //                          sexe : (femme, homme)
        //                          matricule : chiane
        //                          dateDeNaissance : chaine
        //                          lieuDeNaissance : chaine
        //                          option          : toption
        //      Vetudiant = vecteur[1-100] de tEtudiant
        //
        //      I-
        //          1) ecrire une fonction qui lit un vecteur de n étudiants
        //          2) ecrire une fonction qui ecrit un vecteur un n érudiants
        //          3) ecrire une fonction qui delivre les nombres des filles dans un vecteur de n étudaiants
        //          4) ecrire une fonction qui delivre les nombres des garçons et les nombres des filles.
        //          5) ecrire une fonction qui delivre le nombres d'étudiant inscrit dans une discipline donnée.
        //      II-
        //          1) L'écriture des étudiants doit se faire dans un fichier appelé etudiant.txt
        //          2) Enregistrer dans le fichier un étudiant s'appele Aziz faisant l'option MBIO et de sexe masculin
        //          3) Apres avoir entrer au moins 5 étudiants dans le fichiers y compris Mr Aziz
        //              a) lire le fichier ligne par ligine
        //              b) lire le fichier mot par mot
        //              c) lire le fichier caractere par caractere
        //          4) lire le fichier entier
        //          5) donner la taille du fichier
        //          6) Mr Arcele étant perdu dans le fichier, permetez-lui de
        //
