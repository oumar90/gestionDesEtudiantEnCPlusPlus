#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <limits>  // pour utiliser numeric_limits<int>::max()
#include "fonctions.h"

using namespace std;

int main()
{

    string select("sel");
    do
    {

        //MENU
        menuPrincipale();

        cout << "*****************************************************************************************"<<endl;
        cout << "**                 VEILLEZ FAIRE VOTRE CHOIX [1-5]                                     **"<<endl;
        cout << "*****************************************************************************************"<<endl;
        cout <<"\n\tmyconsole@choix~$ ";


        int choix(0);
        cin>> choix;


        switch(choix)
        {
            case 1 : {

                int N(0), val(0), nombresDesOccurences(0),elts(0);
                int tab[N];
                cout << "\n*****************************************************************************************"<<endl;
                cout << "**                 BIENVENUE AU PROGRAMME QUI CALCUL LE NOMBRE D'OCCURRENCE            **"<<endl;
                cout << "*****************************************************************************************"<<endl;

                cout << "\n************Veillez entrer la taille (N) du tableau ***************** "<<endl;
                cout << "\n\tmyconsole@taille~$ ";
                cin>> N;
                //On remplie le tableau tab
                cout << "\n************Veillez entrer les éléments de tableau*******************"<<endl;
                for(int i=0; i<N; i++){
                    cout << "\n\tmyconsole@elts~$ ";
                    cin>>elts;
                    tab[i]=elts;
                }

                //on entre la valeuer a compter son nombre des occurences
                cout << "\n***************Veillez entrer la valeur de val******************* "<<endl;
                cout << "\n\tmyconsole@val~$ ";
                cin>> val;


                //On stocke le nombre d'occurences retourne par la focntion get_occurrences
                nombresDesOccurences = get_occurence(tab, N, val);
                cout << "\n\tLe nombre nombre des occurences de  " << val << " est : " << nombresDesOccurences<<endl;

                break;
            }
            case 2 : {

                int N(0),elts(0);
                 int tab[N];
                cout << "\n*****************************************************************************************"<<endl;
                cout << "**                 BIENVENUE AU PROGRAMME QUI DETERMINE LES NOMBRES IMPAIRS            **"<<endl;
                cout << "*****************************************************************************************"<<endl;
                cout << "\n************Veillez entrer la taille (N) du tableau ***************** "<<endl;
                cout << "\n\tmyconsole@taille~$ ";
                cin>> N;
                //On remplie le tableau tab
                cout << "\n************Veillez entrer les éléments de tableau*******************"<<endl;
                for(int i=0; i<N; i++){
                    cout << "myconsole@elts~$ ";
                    cin>>elts;
                    tab[i]=elts;
                }

                get_nombresImpaires(tab, N);
            break;
            }
            case 3 : {
                //Declarations et initialisations des variables
                int elts(0), n(0);
                int sommePrecedent[n];
                cout << "\n*****************************************************************************************"<<endl;
                cout << "**                 BIENVENUE AU PROGRAMME QUI SOMME LES EELEMENTS PRECEDENT            **"<<endl;
                cout << "*****************************************************************************************"<<endl;
                cout << "\n************Veillez entrer la taille (N) du tableau ***************** "<<endl;
                cout << "\n\tmyconsole@taille~$ ";
                cin>>n;
                cout <<"\n";
                cout << "\n************Veillez entrer les éléments du tableau ***************** "<<endl;
                for(int i = 0; i < n ; i++){
                    cout << "\n\tmyconsole@elts~$ ";
                    cin>> elts;
                    sommePrecedent[i] = elts;
                }

                cout << "\n\tLes éléments de tableau origial: [";
                for (int i = 0; i < n; ++i)
                {
                    cout << " " << sommePrecedent[i];
                }
                cout << "]"<<endl;

                cout << "\n\tLa somme des éléments précédents : [";
                sommeDesElementPrecedent(sommePrecedent, n);
                cout <<"]" <<endl;
            break;
            }
            case 4: {

                string chainLecture("sans"), chaineAphabetique("sans");

                int codeAscii(0);
                cout << "\n*****************************************************************************************"<<endl;
                cout << "**                 BIENVENUE AU PROGRAMME QUI DETERMINE LES FREQUENCES DE LETTRES      **"<<endl;
                cout << "*****************************************************************************************"<<endl;
                cout<<"\n===========Entrer une chaine de caracteres se terminant par un point=============="<<endl<<endl;
                cout << "\n\t:> ";
                getline(cin, chainLecture, '.');

                for(int i = 0; i < chainLecture.size(); i++){

                    codeAscii = (int)chainLecture[i];

                    if(((codeAscii >= 65) && (codeAscii <= 90)) ||((codeAscii >= 97) && (codeAscii <= 122)))

                        chaineAphabetique.push_back(chainLecture[i]);


                }
                string collectionDeChaineDeCaractere;

                collectionDeChaineDeCaractere.push_back(chaineAphabetique[0]);

                for(int i = 1; i < chaineAphabetique.size(); i++)

                    if(!rechercheCaractere(chaineAphabetique[i], collectionDeChaineDeCaractere))

                        collectionDeChaineDeCaractere.push_back(chaineAphabetique[i]);

                for(int i = 0; i < collectionDeChaineDeCaractere.size(); i++ ){

                    cout.setf(ios::dec, ios::basefield);

                    cout.setf(ios::fixed, ios::floatfield);

                    cout.precision(2);

                    cout<<collectionDeChaineDeCaractere[i]<<"  :  "<<calculFreqceCaractere(collectionDeChaineDeCaractere[i], chaineAphabetique) << "%"<<endl;

                }



            break;
            }

            case 5 : {
                    //Sous menu
                    menuPrincipaleEtudiant();
                    cout << "\n*****************************************************************************************"<<endl;
                    cout << "**                 VEILLEZ FAIRE VOTRE CHOIX [a-c]                                     **"<<endl;
                    cout << "*****************************************************************************************"<<endl;
                    cout <<"\n\tmyconsole@choix~$ ";
                    char chois;
                    cin>>chois;
                    convertCharMin(chois);
                    switch(chois)
                    {
                        case 'a':{
                            string verfifier;
                             ajouterEtudiantDansLaListe();
                             cout << "\n\t Voulez-vous verifier l'enregistrement (Oui/Non) ? ";
                             cin>> verfifier;
                             if(verfifier == "Oui" || verfifier == "O" || verfifier == "o" ||verfifier =="OUI" )
                                lireLaListeEtudiant(); //oN APPEL LA FONTION POUR LISTER LES ETUDIANTS

                        break;}
                        case 'b':{
                            lireLaListeEtudiant();//oN APPEL LA FONTION POUR LISTER LES ETUDIANTS
                        break;}
                        case 'c':{
                             listerDesEtudiantsFeminin();//oN APPEL LA FONTION POUR LISTER LES ETUDIANTS  DU GENRE GEMININ
                        break;}
                        case 'd':lireMotParMot(); break;
                        case 'e':lireCaractereParCaractere(); break;
                        case 'f':{
                            cout << "\t\tLISTES DES FILIAIRES"<<endl;
                            cout << "\n\t\t1) GBIO"<<endl;
                            cout << "\n\t\t2) MIP"<<endl;
                            cout << "\n\t\t3) GIN"<<endl;
                            cout << "\n\t\t4) GIE"<<endl;
                            cout << "\n\tVeillez choisir une filiaire (1, 2, 3, 4, 5) : ";
                            string filiaire;
                            int filiaireE(0);
                            cin>>filiaireE;
                            switch(filiaireE)
                            {
                                case 1: {filiaire = "GBIO";listerDesEtudiantsDansUneFiliaireDonne(filiaire);break;}
                                case 2: {filiaire = "MIP";listerDesEtudiantsDansUneFiliaireDonne(filiaire);break;}
                                case 3: {filiaire = "GIN";listerDesEtudiantsDansUneFiliaireDonne(filiaire);break;}
                                case 4: {filiaire = "GIE";listerDesEtudiantsDansUneFiliaireDonne(filiaire);break;}
                            }
                        break;}
                        case 'g': positionDuCurseur(); break;
                        case 'h':cout << "\n\tLe fichier etudiant.txt pèse est "<< tailleDuFichier() << " octets" <<endl;break;
                        default:cout << "Votre choix est invalide !!" << endl;break;

                    }

                break;
            }
    }
        cout << "\n\t Voulez-vous continuez (Oui/Non) ? ";
        cin>> select;
    }while( select == "Oui" || select == "O" || select== "o" || select == "OUI");

return 0;
}
