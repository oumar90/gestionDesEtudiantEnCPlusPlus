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
//Fonction qui perme de determine l'occurrence d'une caratere
float occurrenceCaractere(char caractere, std::string chaine);
//Fonction qui permet de determiner la frequence d'une caractere
float calculFreqceCaractere(char caract, std::string chaine);
//Fonction de recherche  d'un caractere dans une chaine de caractere
bool rechercheCaractere(char caract , std::string chaine);

//Fonction qui permet de convertir un caractere minuscule en majuscule
void convertChar(char& c);
//Fonction qui permet de convertir un caractere en minuscule
void convertCharMin(char& c);

//Fonction qui permet de convertir une chaine de caractere
void convert(std::string& s);
//====================================Fichier==================================
//Fonction qui permet de lire la liste des étudian
void lireLaListeEtudiant();

//Fonction qui permet d'ajouter les étudiants
void ajouterEtudiant(std::vector<etudiant> listeEtudiant  , int nbEtudiant);
//Fonction qui permet d'ajouter les étudiants
void ajouterEtudiantDansLaListe();
//Foncfion qui permet de lister tous les etudiants du genre feminin
void listerDesEtudiantsFeminin();
//Fonction qui permet determiner la taille d'un fichier
//void tailleDuFichier();
long tailleDuFichier();
//Fonction qui permet determiner la position du curseur dans un fichier
void positionDuCurseur();
//Fonction qui permet de lire mot par mot
void lireMotParMot();
//Fonction qui permet de lire caractere par caractere
void lireCaractereParCaractere();
//Foncfion qui permet de lister tous les etudiants inscrit dans une filiaire donnée
void listerDesEtudiantsDansUneFiliaireDonne(std::string filiaire);


#endif // FONCTIONS_H_INCLUDED

