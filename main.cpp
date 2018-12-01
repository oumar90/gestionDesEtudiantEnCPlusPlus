#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

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
    string nom;
    string prenom;

    t_sexe sexe;

    string matricule;
    string dateDeNaissance;
    string lieuDeNaissance;

    int age;

    t_option option;

    

} etudiant;



//Fonction permet d'otenir le nombre des occureneces d'un nombre dans un tableau de n élémnets
int get_occurence(int *t,int N,int valeur)
{
	int nb_occurence=0;
    //ON PARCOURS LE TABLEAU
	for(int s=0;s<N;s++)
	{
        //SI ON TROUVE UN ELEMENT DANS LE TABLEAU EGALE À VAL ON INCREMNET LE COMPTEUR
		if (t[s]==valeur)
		{
            nb_occurence=nb_occurence+1;
		}
	}
	//ON RETOURNE LE NOMBRE DES OCCURENCES
	return(nb_occurence);
}

// Fonction qui permet d'imprimer tous les nombres impaires dans un tableau
int get_nombresImpaires(int *t , int n){

       cout << "\n************Les éléments impaires du tableau sont*************** "<<endl;
       cout << "\n\t[";
        for(int i = 0; i < n; i++){
            if(t[i] % 2 != 0)
                cout << " " << t[i];
        }
        cout << " ]\n";
}

// fonction qui permet de sommer les éléments précédents et lui-même
int sommeDesElementPrecedent(int *sommePrecedent, int n)
{

        for(int i = 1; i < n; i++){
             sommePrecedent[i] =  sommePrecedent[i] + sommePrecedent[i+1];
             cout << " " <<  sommePrecedent[i];
        }
}

//Fonction qui determine la frequence de caractere
int frequenceDeLettre(string chaine, char c)
{
    double compteur(0);
    for (int i = 0; i < chaine.length(); i++)
    {
        if (chaine[i] == c)
        {
            compteur++;
        }
    }

    return compteur;
}

//=====================================Taille d'un fichier======================
istream::pos_type taille_fichier(const string &nom) {
   ifstream fich{ nom };
   fich.seekg(0, ios::end); // aller à zéro bytes de la fin
   return fich.tellg();  // obtenir la position et la retourner
}

//====================================Fichier==================================
//Fonction qui permet de lire la liste des étudian

void lireLaListeEtudiant()
{
    string ligne;

    cout << "Listes des étudiants déja inscrits" <<endl;
    ifstream fichier("etudiant.txt");
    if (fichier)
    {
        while(getline(fichier, ligne)){
            cout << ligne << endl;
        }
    }else{
        cout << "impossible d'ouvrir le fichier. "<< endl;
    }

}

//Fonction qui permet d'ajouter les étudiants

void ajouterEtudiant(vector<etudiant> listeEtudiant  , int nbEtudiant)
{
   
    ofstream monFlux;
    monFlux.open("etudiant.txt", ofstream::app);

    if (monFlux)
    {


        for (int i = 0; i < nbEtudiant; ++i)
        {

            if( listeEtudiant[i].sexe ==  0){
                switch(listeEtudiant[i].option)
                {
                    case GBIO : monFlux <<listeEtudiant[i].nom << " "<< listeEtudiant[i].prenom << " " << "masculin" << " " << listeEtudiant[i].age << " " <<listeEtudiant[i].matricule << " " << listeEtudiant[i].dateDeNaissance << " " <<listeEtudiant[i].lieuDeNaissance << " " << "GBIO" << endl; break;
                    case MIP: monFlux <<listeEtudiant[i].nom << " "<< listeEtudiant[i].prenom << " " << "masculin" << " " << listeEtudiant[i].age << " " <<listeEtudiant[i].matricule << " " << listeEtudiant[i].dateDeNaissance << " " <<listeEtudiant[i].lieuDeNaissance << " " << "MIP" << endl ;break;
                    case GIE: monFlux <<listeEtudiant[i].nom << " "<< listeEtudiant[i].prenom << " " << "masculin" << " " << listeEtudiant[i].age << " " <<listeEtudiant[i].matricule << " " << listeEtudiant[i].dateDeNaissance << " " <<listeEtudiant[i].lieuDeNaissance << " " << "GIE" << endl ;break;
                    case GIN: monFlux <<listeEtudiant[i].nom << " "<< listeEtudiant[i].prenom << " " << "masculin" << " " << listeEtudiant[i].age << " " <<listeEtudiant[i].matricule << " " << listeEtudiant[i].dateDeNaissance << " " <<listeEtudiant[i].lieuDeNaissance << " " << "GIN" << endl ;break;
                }

            }else if(listeEtudiant[i].sexe ==  1){
                switch(listeEtudiant[i].option)
                {
                    case GBIO: monFlux <<listeEtudiant[i].nom << " "<< listeEtudiant[i].prenom << " " << "feminin" << " " << listeEtudiant[i].age << " " <<listeEtudiant[i].matricule << " " << listeEtudiant[i].dateDeNaissance << " " <<listeEtudiant[i].lieuDeNaissance << " " << "GBIO" << endl ;break;
                    case MIP: monFlux <<listeEtudiant[i].nom << " "<< listeEtudiant[i].prenom << " " << "feminin" << " " << listeEtudiant[i].age << " " <<listeEtudiant[i].matricule << " " << listeEtudiant[i].dateDeNaissance << " " <<listeEtudiant[i].lieuDeNaissance << " " << "MIP" << endl ;break;
                    case GIE: monFlux <<listeEtudiant[i].nom << " "<< listeEtudiant[i].prenom << " " << "feminin" << " " << listeEtudiant[i].age << " " <<listeEtudiant[i].matricule << " " << listeEtudiant[i].dateDeNaissance << " " <<listeEtudiant[i].lieuDeNaissance << " " << "GIE" << endl ;break;
                    case GIN: monFlux <<listeEtudiant[i].nom << " "<< listeEtudiant[i].prenom << " " << "feminin" << " " << listeEtudiant[i].age << " " <<listeEtudiant[i].matricule << " " << listeEtudiant[i].dateDeNaissance << " " <<listeEtudiant[i].lieuDeNaissance << " " << "GIN" << endl ;break;
                }
            }else{
                cout << "\n\t Vous n'êtes pas un être humain"<<endl;
            }

        }
        
    }else{

        cout << "impossible d'ouvrir le fichier" <<endl;
    }

    monFlux.close();

}

int main()
{
 /*   //DESCLARATION DE VARIAABLES ET TAB(COMME POITEUR) ET INITITALISATIONS
    int *tab, N(0), val(0), nombresDesOccurences(0),elts(0);

    cout << "************Veillez entrer la taille (N) du tableau ***************** "<<endl;
    cout << "myconsole@taille~$ ";
    cin>> N;
    //On remplie le tableau tab
    cout << "\n************Veillez entrer les éléments de tableau*******************"<<endl;
    for(int i=0; i<N; i++){
        cout << "myconsole@elts~$ ";
        cin>>elts;
        tab[i]=elts;
    }

    //on entre la valeuer a compter son nombre des occurences
    cout << "\n***************Veillez entrer la valeur de val******************* "<<endl;
    cout << "myconsole@val~$ ";
    cin>> val;


    //On stocke le nombre d'occurences retourne par la focntion get_occurrences
    nombresDesOccurences = get_occurence(tab, N, val);
    cout << "\n\tLe nombre nombre des occurences de  " << val << " est : " << nombresDesOccurences<<endl;*/

    //==============================================================================================================

     /*  int *tab, N(0), val(0), nombresDesOccurences(0),elts(0);

        cout << "************Veillez entrer la taille (N) du tableau ***************** "<<endl;
        cout << "myconsole@taille~$ ";
        cin>> N;
        //On remplie le tableau tab
        cout << "\n************Veillez entrer les éléments de tableau*******************"<<endl;
        for(int i=0; i<N; i++){
            cout << "myconsole@elts~$ ";
            cin>>elts;
            tab[i]=elts;
        }

        get_nombresImpaires(tab, N);*/
        //============================================================================================================

        
        /*int elts(0), n(0);
        int *sommePrecedent;

        cout << "************Veillez entrer la taille (N) du tableau ***************** "<<endl;
        cout << "myconsole@taille~$ ";
        cin>>n;
        cout <<"\n";
        cout << "\n************Veillez entrer les éléments du tableau ***************** "<<endl;
        for(int i = 0; i < n ; i++){
            cout << "myconsole@elts~$ ";
            cin>> elts;
            sommePrecedent[i] = elts;
        }

        cout << "\n\tLes éléments de tableau origial: [";
        for (int i = 0; i < n; ++i)
        {
            cout << " " << sommePrecedent[i];
        }
        cout << " ]"<<endl;

        cout << "\n\tLa somme des éléments précédents : [ ";
        sommeDesElementPrecedent(sommePrecedent, n);
        cout <<"]" <<endl;*/

    //=======================================Pas fini=======================================================================

   /* string chaine;
    char c;
    double compteur(0);

    cout << "Veillez saisir une phrase anglaise"<< endl;
    cout << "myconsole@phrase~$ ";
    getline(cin, chaine);

    cout << "Veillez entrer un caractere à determinée sa frequence "<<endl;
    cout << "myconsole@char~$ ";
    cin>>c;

    compteur = frequenceDeLettre(chaine, c);

    double f(0);

    f = (compteur / chaine.length()) * 100;

    cout << chaine<<endl;
    cout << f  << " % "<<endl;
    cout << chaine.length() <<endl;*/


  
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


    int n(0), nbEtudiant(0);

    int i=0;

    //Declaration du tableau dynamique de type 
    vector <etudiant> listeEtudiant;
   

    etudiant infosEtudiant;

    //Lire la liste de étudiant
    //lireLaListeEtudiant();

    cout << "\n\tVeillez entrer le nombre de l'etudiant : ";
    cin>>nbEtudiant;
    cin.ignore();

    char choiSex;

    //Remplir la liste 
   while(i < nbEtudiant)
    {
        cout << "Etudiant n"<<i<< " : ";
        cout << "\n\t Nom: ";
        getline(cin,infosEtudiant.nom);
        cout << "\n\t Prenom: ";
        getline(cin,infosEtudiant.prenom);
        cout << "\n\t Sexe: ";
        cin>>choiSex;

        switch(choiSex){

            case 'M': infosEtudiant.sexe = masculin;break;
            case 'F': infosEtudiant.sexe = feminin;break;
            default: cout << "Vous n'êtes pas un être humain !!! " <<endl;
        }

        cout << "\n\t Age: ";
        cin>>infosEtudiant.age;
        cin.ignore();       
        cout << "\n\t Matricule: ";
        getline(cin,infosEtudiant.matricule);
        cout << "\n\t Date de naissance: ";
        getline(cin,infosEtudiant.dateDeNaissance);
        cout << "\n\t Lieu de naissance: ";
        getline(cin,infosEtudiant.lieuDeNaissance);

        string optionv;
        cout << "\n\t Veillez choisir une option(GBIO, MIP, GIE, GIN): ";
        cin>>optionv;

        if(optionv == "GBIO"){
            infosEtudiant.option = GBIO;
        }
        else if(optionv == "MIP"){
            infosEtudiant.option = MIP;
        }
        else if(optionv == "GIE"){
            infosEtudiant.option = GIE;
        }
        else if(optionv == "GIN"){
             infosEtudiant.option = GIN;
        }
         else{
            cout <<"\n Veilez choissir une mauvaise option SVP!!!";
        }

        listeEtudiant.push_back(infosEtudiant);

        i = i + 1;
    }

    //Ajout des étudiants
    ajouterEtudiant(listeEtudiant, nbEtudiant);


    //ecrire une fonction qui delivre les nombres des filles dans un vecteur de n étudaiants

   
    ifstream fichier1("etudiant.txt");

    if (fichier1)
    {
      
      string ligne, mot;
        while(getline(fichier1, ligne))
        {
            while ( fichier1 >> mot)
            {
                if( mot == "feminin"){
                    cout << ligne << endl;
                 }
            }
        }
      
  
    }else{

        cout << "impossible d'ouvrir le fichier" <<endl;
    }
    //  string ligne, mot;
    // ifstream file("etudiant.txt"); 
    // string word; 

    // while( file >> word){
    //     if(word == "feminin") 
    //             cout << getline(file, ligne) << endl; 
    // }


    return 0;
}
