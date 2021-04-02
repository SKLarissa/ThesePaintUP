#include <iostream>
#include <ProblemeOptimisation/ProblemeOptimisation.h>
#include <Probleme14/Probleme14.h>
#include <Probleme23/Probleme23.h>
#include <Enregistre/Enregistre.h>

#include <string.h>

using namespace std;


int main()
{


    ProblemeOptimisation * Pb;

    char NomSolveur[5];
    char NomProbleme[5];
    cout << "Saisir le Solveur et le Probleme respectivement : " << endl;
    cin >> NomSolveur >> NomProbleme;


    // Identification du type de problème



    if (strcmp(NomProbleme,"P1")==0)
    {
        Pb = new Probleme14;
    }
    else if (strcmp(NomProbleme,"P2")==0)
    {
        Pb = new Probleme23;
    }
    else if (strcmp(NomProbleme,"P3")==0)
    {
        Pb = new Probleme23(4);
    }
    else if (strcmp(NomProbleme,"P4")==0)
    {
        Pb = new Probleme14(2);
    }
    else
    {
        EcritureFichier();                                                // On ecrit ERREUR dans le fichier
    }

    // Resolution du problème

    Calcul(*Pb,NomSolveur);

    return 0;
}





