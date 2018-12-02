#include <iostream>
#include <sstream>
#include <fstream>
#include "fonctions.h"


using namespace std;



//Fonction permet d'otenir le nombre des occureneces d'un nombre dans un tableau de n élémnets
int get_occurence(int t[],int N,int valeur)
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

//Fonction permet d'imprimer les nombres impaires
void get_nombresImpaires(int tab[], int N)
{
    cout << "\n\t Les nombres impaires sont";
    for(int i = 0; i < N; i++)
    {
        if( tab[i] %2 == 0)
            cout << "\n\t" << tab[i] << " ";
    }
}

// fonction qui permet de sommer les éléments précédents et lui-même
int sommeDesElementPrecedent(int sommePrecedent[], int n)
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
/*istream::pos_type taille_fichier(const string &nom) {
   ifstream fich{ nom };
   fich.seekg(0, ios::end); // aller à zéro bytes de la fin
   return fich.tellg();  // obtenir la position et la retourner
}*/




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

//Ajouter les étudaints dans la liste
void ajouterEtudiantDansLaListe()
{

      int nbEtudiant(0);

            int i=0;

            //Declaration du tableau dynamique de type
            vector <etudiant> listeEtudiant;


            etudiant infosEtudiant;

            //Lire la liste de étudiant
            //lireLaListeEtudiant();a
            //listes des étudiantes
            //listerDesEtudiantsFeminin()

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


            //ecrire une fonction qui delivre les nombres des filles dans un vecteur de n étudaiant
}

//Foncfion qui permet de lister tous les etudiants du genre feminin
void listerDesEtudiantsFeminin()
{
     //ouverture du fichier en lecture
    ifstream fichier1("etudiant.txt");

    if (fichier1) //on verifie si le fichier est ouvrable en lecture
    {

      string ligne, mot;
        while(getline(fichier1, ligne)) //On lit ligne par ligne tout le fichier
        {
            istringstream flux_ligne(ligne);
            while ( flux_ligne >> mot) //on lit mot par mot tout le fichier
            {
                if( mot == "feminin"){ //si on trouve un mot="feminin"
                    cout << ligne << endl; //on affiche cette ligne
                 }
            }
        }


    }else{

        cout << "impossible d'ouvrir le fichier en lecture!!!!" <<endl;
    }

}

//======================MENU========================================
void menuPrincipale()
{
    cout << "\n*************************************************************************************************************"<<endl;
    cout << "**                                                                                                         **"<<endl;
    cout << "**                                         MENU                                                            **"<<endl;
    cout << "**                                                                                                         **"<<endl;
    cout << "** 1) Fonction permet d'otenir le nombre des occureneces d'un nombre dans un tableau de n élémnets         **"<<endl;
    cout << "**                                                                                                         **"<<endl;
    cout << "** 2) Fonction permet d'imprimer les nombres impaires                                                      **"<<endl;
    cout << "**                                                                                                         **"<<endl;
    cout << "** 3) Fonction qui permet de sommer les éléments précédents et lui-même                                    **"<<endl;
    cout << "**                                                                                                         **"<<endl;
    cout << "** 4) Fonction qui determine la frequence de caractere                                                     **"<<endl;
    cout << "**                                                                                                         **"<<endl;
    cout << "** 5) Gestion des étudiants                                                                                **"<<endl;
    cout << "**                                                                                                         **"<<endl;
    cout << "*************************************************************************************************************"<<endl;

}



//======================SOUS MENU========================================
void menuPrincipaleEtudiant()
{
    cout << "\n*************************************************"<<endl;
    cout << "**                                               **"<<endl;
    cout << "**           MENU                                **"<<endl;
    cout << "**                                               **"<<endl;
    cout << "** a) Ajouter des étudiants                      **"<<endl;
    cout << "**                                               **"<<endl;
    cout << "** b) Listes des tous les étudiants              **"<<endl;
    cout << "**                                               **"<<endl;
    cout << "** c) Lestes des étudiants du genre feminins     **"<<endl;
    cout << "**                                               **"<<endl;
    cout << "** d) Verifier la taille du fichier              **"<<endl;
    cout << "**                                               **"<<endl;
    cout << "** e) Gestion des étudiants                      **"<<endl;
    cout << "**                                               **"<<endl;
    cout << "***************************************************"<<endl;

}
