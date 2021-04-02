#include "Enregistre/Enregistre.h"

#include <fstream>
#include <string.h>

using namespace std;

unsigned int n = 0;
void EcritureFichier ()
{
    /**OUVERTURE EN ECRITURE**/
    ofstream file;
    file.open("Result.txt");
    if(file){
        file <<"ERREUR : Probleme ou solveur pas défini." << endl;
    }
    else{
        cout <<"ERREUR : fichier impossible à ouvrir."<<endl;
    }
    file.close();
}
void EcritureFichier (struct_Result R)
{
    /**OUVERTURE EN ECRITURE**/
    ofstream file;
    unsigned int i;
    file.open("Result.txt");
    if(file){

        file << "Le minimum de F est : ";
        file << R.Fmin << endl;
        if (n==1)
        {
            file << "Le point ou F est minimum est : (" << R.P[0] << ")"<<  endl;
        }
        else
        {
            file << "Le point ou F est minimum est : (" ;
            for ( i=0; i<n-1; i=i+1)
            {
                file << R.P[i] << ";";
            }
            file << R.P[i] << ")"<<  endl;
        }
    }
    else{
        cout <<"ERREUR : fichier impossible à ouvrir."<<endl;
    }
    file.close();

}
void Calcul(ProblemeOptimisation & p, char S[20])
{
    struct_Result Resultat;
    float * Xmin;
    float * Xmax;




    Xmin = p.GetXmin ();
    Xmax = p.GetXmax ();
    n = p.GetNbreVariable();

    float BufferXmin[n];
    float BufferXmax[n];

    for (unsigned int i=0; i<n; i=i+1)
    {
        BufferXmin[i] = float(Xmin[i]);
        BufferXmax[i] = float(Xmax[i]);
    }

    if (strcmp(S,"S1")==0)
    {
        Resultat = p.Solveur1();
        EcritureFichier(Resultat);
    }
    else if (strcmp(S,"S2")==0)
    {
        Resultat = p.Solveur2();
        EcritureFichier(Resultat);
    }
    else if (strcmp(S,"S3")==0)
    {
        Resultat = p.Solveur3();
        EcritureFichier(Resultat);
    }
    else if (strcmp(S,"S4")==0)
    {
       Resultat = p.Solveur4(BufferXmax, BufferXmin);
       EcritureFichier(Resultat);
    }
    else if (strcmp(S,"S5")==0)
    {
        Resultat = p.Solveur5(BufferXmax, BufferXmin);
        EcritureFichier(Resultat);
    }
    else if (strcmp(S,"S6")==0)
    {
        Resultat = p.Solveur6(true, 0);
        EcritureFichier(Resultat);
    }
    else if (strcmp(S,"S7")==0)
    {
        Resultat = p.Solveur7(true);
        EcritureFichier(Resultat);
    }
    else
    {
        EcritureFichier();
    }
}

