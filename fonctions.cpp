#include <iostream>
#include <sstream>
#include <fstream>
#include <limits>  // pour utiliser numeric_limits<int>::max()
#include "fonctions.h"


using namespace std;


//Fonction qui permet de convertir un caractere minuscule en majuscule
void convertChar(char& c)
{

    c = toupper(c);
}


//Fonction qui permet de convertir un caractere en minuscule
void convertCharMin(char& c)
{
    c = tolower(c);
}

//Fonction qui permet de convertir une chaine de caractere
void convert(std::string& s)
{

    for (int i = 0; i < s.length(); i++)
    {
        s[i] = toupper(s[i]);
    }
}
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
    cout << "\n\tLes nombres impaires sont : [ ";
    for(int i = 0; i < N; i++)
    {
        if( tab[i] %2 != 0)
            cout << tab[i] << " ";
    }
    cout << " ]";
}

// fonction qui permet de sommer les éléments précédents et lui-même
int sommeDesElementPrecedent(int sommePrecedent[], int n)
{

        for(int i = 1; i <=n; i++){
             sommePrecedent[i] =  sommePrecedent[i-1] + sommePrecedent[i];
             cout << " " <<  sommePrecedent[i];
        }
}

//Fonction qui perme de determine l'occurrence d'une caratere
float occurrenceCaractere(char caractere, string chaine){

	int occurrence = 0, i;

	for(i = 0; i < chaine.size(); i++){

		if(toupper(caractere) == toupper( chaine[i]))

				occurrence ++;


	}

	return occurrence;

}

//Fonction qui permet de determiner la frequence d'une caractere
float calculFreqceCaractere(char caract, string chaine){

	float resultat = occurrenceCaractere(caract, chaine) / chaine.size();

	return resultat;

}

//Fonction de recherche  d'un caractere dans une chaine de caractere

bool rechercheCaractere(char caract , string chaine){

	for(int i = 0; i < chaine.size(); i++)

		if(toupper(caract) == toupper(chaine[i]))


				return true;

	return false;
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
                    case GBIO: monFlux <<listeEtudiant[i].nom << "    "<< listeEtudiant[i].prenom << "       " << "masculin" << "       " << listeEtudiant[i].age << "       " <<listeEtudiant[i].matricule << "       " << listeEtudiant[i].dateDeNaissance << "       " <<listeEtudiant[i].lieuDeNaissance << "       " << "GBIO" << endl; break;
                    case MIP: monFlux <<listeEtudiant[i].nom << "   "<< listeEtudiant[i].prenom << "       " << "masculin" << "       " << listeEtudiant[i].age << "       " <<listeEtudiant[i].matricule << "       " << listeEtudiant[i].dateDeNaissance << "       " <<listeEtudiant[i].lieuDeNaissance << "       " << "MIP" << endl ;break;
                    case GIE: monFlux <<listeEtudiant[i].nom << "   "<< listeEtudiant[i].prenom << "       " << "masculin" << "       " << listeEtudiant[i].age << "       " <<listeEtudiant[i].matricule << "       " << listeEtudiant[i].dateDeNaissance << "       " <<listeEtudiant[i].lieuDeNaissance << "       " << "GIE" << endl ;break;
                    case GIN: monFlux <<listeEtudiant[i].nom << "   "<< listeEtudiant[i].prenom << "       " << "masculin" << "       " << listeEtudiant[i].age << "       " <<listeEtudiant[i].matricule << "       " << listeEtudiant[i].dateDeNaissance << "       " <<listeEtudiant[i].lieuDeNaissance << "       " << "GIN" << endl ;break;

                }
                monFlux << "\n";

            }else if(listeEtudiant[i].sexe ==  1){
                switch(listeEtudiant[i].option)
                {
                    case GBIO: monFlux <<listeEtudiant[i].nom << "   "<< listeEtudiant[i].prenom << "       " << "feminin" << "       " << listeEtudiant[i].age << "       " <<listeEtudiant[i].matricule << "       " << listeEtudiant[i].dateDeNaissance << "       " <<listeEtudiant[i].lieuDeNaissance << "       " << "GBIO" << endl ;break;
                    case MIP: monFlux <<listeEtudiant[i].nom << "   "<< listeEtudiant[i].prenom << "       " << "feminin" << "       " << listeEtudiant[i].age << "       " <<listeEtudiant[i].matricule << "       " << listeEtudiant[i].dateDeNaissance << "       " <<listeEtudiant[i].lieuDeNaissance << "       " << "MIP" << endl ;break;
                    case GIE: monFlux <<listeEtudiant[i].nom << "   "<< listeEtudiant[i].prenom << "       " << "feminin" << "       " << listeEtudiant[i].age << "       " <<listeEtudiant[i].matricule << "       " << listeEtudiant[i].dateDeNaissance << "       " <<listeEtudiant[i].lieuDeNaissance << "       " << "GIE" << endl ;break;
                    case GIN: monFlux <<listeEtudiant[i].nom << "   "<< listeEtudiant[i].prenom << "       " << "feminin" << "       " << listeEtudiant[i].age << "       " <<listeEtudiant[i].matricule << "       " << listeEtudiant[i].dateDeNaissance << "       " <<listeEtudiant[i].lieuDeNaissance << "       " << "GIN" << endl ;break;
                }
                monFlux << "\n";
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

                convertChar(choiSex);


                switch(choiSex){

                    case 'M': infosEtudiant.sexe = masculin;break;
                    case 'F': infosEtudiant.sexe = feminin;break;
                   // default: cout << "Vous n'êtes pas un être humain !!! " <<endl;
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
                convert(optionv);

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

            cout << "\n\tL'étudiant a été ajouter avec succès!!!"<<endl;


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
      int nombreFille(0);
        while(getline(fichier1, ligne)) //On lit ligne par ligne tout le fichier
        {
            istringstream flux_ligne(ligne);
            while ( flux_ligne >> mot) //on lit mot par mot tout le fichier
            {
                if( mot == "feminin"){ //si on trouve un mot="feminin"
                   nombreFille+=1; //on affiche cette ligne
                 }
            }
        }

        cout << "\n\t Les nombres de fille est : " << nombreFille << endl;


    }else{

        cout << "impossible d'ouvrir le fichier en lecture!!!!" <<endl;
    }

      fichier1.close();
}

//Fonction qui permet determiner la position du curseur dans un fichier
void positionDuCurseur(){

    ifstream fichier("etudiant.txt");

    long position = fichier.tellg(); //on recupère la position de du curseur

    if(!fichier.fail()){
        cout << "\n\t\tOn se trouve au " << position << " ième octet." << endl;
    }
fichier.close();
}
// Getsize taille
long tailleDuFichier()
{
    ifstream fichier("etudiant.txt");
    // sauvegarder la position courante
    long pos = fichier.tellg();
    // se placer en fin de fichier
    fichier.seekg(0 , std::ios_base::end );
    // récupérer la nouvelle position = la taille du fichier
    long size = fichier.tellg() ;
    // restaurer la position initiale du fichier
    fichier.seekg( pos,  std::ios_base::beg ) ;
    return size ;
}
//Fonction qui permet determiner la taille d'un fichier
/*void tailleDuFichier()
{
    long long int length = 0;
    std::ifstream is;
    is.open ("etudiant.txt", std::ios::binary );
    is.seekg (0, std::ios::end);
    length = is.tellg();
     cout << "\n\t La taille du fichier etudiant.txt pèse " << length << " octets." << endl;
}*/

//Fonction qui permet de lire mot par mot
void lireMotParMot()
{
    ifstream monFlux("etudiant.txt");
    string mot;

    while ( monFlux >> mot) //on lit mot par mot tout le fichier
    {
        cout << mot << endl;
    }
    monFlux.close();
}


//Fonction qui permet de lire mot par mot
void lireCaractereParCaractere()
{
    ifstream monFlux("etudiant.txt");
    char car;

    while ( monFlux.get(car)) //on lit mot par mot tout le fichier
    {
        cout << car << endl;
    }
    monFlux.close();
}

//Foncfion qui permet de lister tous les etudiants inscrit dans une filiaire donnée
void listerDesEtudiantsDansUneFiliaireDonne(string filiaire)
{
     //ouverture du fichier en lecture
    ifstream fichier1("etudiant.txt");

    if (fichier1) //on verifie si le fichier est ouvrable en lecture
    {

      string ligne, mot;
      int nombreEtudiantD(0);
        while(getline(fichier1, ligne)) //On lit ligne par ligne tout le fichier
        {
            istringstream flux_ligne(ligne);
            while ( flux_ligne >> mot) //on lit mot par mot tout le fichier
            {
                if( mot == filiaire){ //si on trouve un mot="feminin"
                   nombreEtudiantD+=1; //on affiche cette ligne
                 }
            }
        }

        if(nombreEtudiantD != 0)
            cout << "\n\t Les nombre des étudiants dans la filiaire " << filiaire << " est :" << nombreEtudiantD << endl;
        else
            cout << "\n\t Aucun étudiant dans la " << filiaire <<  endl;



    }else{

        cout << "impossible d'ouvrir le fichier en lecture!!!!" <<endl;
    }

      fichier1.close();
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
    cout << "\n***************************************************"<<endl;
    cout << "**                                                 **"<<endl;
    cout << "**                MENU                             **"<<endl;
    cout << "*****************************************************"<<endl;
    cout << "** a) Ajouter des étudiants                        **"<<endl;
    cout << "**                                                 **"<<endl;
    cout << "** b) Listes des tous les étudiants                **"<<endl;
    cout << "**                                                 **"<<endl;
    cout << "** c) Lestes des étudiants du genre feminins       **"<<endl;
    cout << "**                                                 **"<<endl;
    cout << "** d) Lister le fichier mot par mot                **"<<endl;
    cout << "**                                                 **"<<endl;
    cout << "** e) Lister le fichier caractère par caratère     **"<<endl;
    cout << "**                                                 **"<<endl;
    cout << "** f) Liste des étudiants dans une displine donnée **"<<endl;
    cout << "**                                                 **"<<endl;
    cout << "** g) Position du curseur dans fichier             **"<<endl;
    cout << "**                                                 **"<<endl;
    cout << "** h) La taille du fichier                         **"<<endl;
    cout << "**                                                 **"<<endl;
    cout << "*****************************************************"<<endl;

}
