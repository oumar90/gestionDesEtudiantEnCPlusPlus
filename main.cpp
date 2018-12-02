#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
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

                cout << "************Veillez entrer la taille (N) du tableau ***************** "<<endl;
                cout << "\n\tmyconsole@taille~$ ";
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
                cout << "\n\tLe nombre nombre des occurences de  " << val << " est : " << nombresDesOccurences<<endl;

                break;
            }
            case 2 : {

                int N(0),elts(0);
                 int tab[N];

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

                get_nombresImpaires(tab, N);
            break;
            }
            case 3 : {
                //Declarations et initialisations des variables
                int elts(0), n(0);
                int sommePrecedent[n];

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
                cout <<"]" <<endl;
            break;
            }
            case 4: {
                string chaine;
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
                cout << chaine.length() <<endl;
            break;
            }

            case 5 : {
                    //Sous menu
                    menuPrincipaleEtudiant();
                    cout << "*****************************************************************************************"<<endl;
                    cout << "**                 VEILLEZ FAIRE VOTRE CHOIX [a-c]                                     **"<<endl;
                    cout << "*****************************************************************************************"<<endl;
                    cout <<"\n\tmyconsole@choix~$ ";
                    char chois;
                    cin>>chois;
                    switch(chois)
                    {
                        case 'a':
                            ajouterEtudiantDansLaListe();
                        break;
                        case 'b':
                            lireLaListeEtudiant();
                        break;
                        case 'c':
                             listerDesEtudiantsFeminin();
                        break;
                        default:
                            cout << "Votre choix est invalide !!" << endl;
                    }


                break;
            }



    }



        cout << "\n\t Voulez-vous continuez (Oui/Non) ? ";
        cin>> select;
    }while( select == "Oui" || select == "O" || select== "o");

return 0;
}
