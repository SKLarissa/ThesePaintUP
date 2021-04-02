#include "ProblemeOptimisation/ProblemeOptimisation.h"
#include <iostream>


using namespace std;

ProblemeOptimisation::ProblemeOptimisation(unsigned int n_NbreVar) : m_NbreVariable(n_NbreVar) // constructeur avec argument, initialisation de la variable "m_NbreVariable"
{

    m_Xmin = new float[m_NbreVariable];
    m_Xmax = new float[m_NbreVariable];
    for (unsigned int i=0; i<m_NbreVariable; i=i+1)
    {
        // initialisation de toutes les valeurs minimales et maximales aux valeurs par défaut

        m_Xmin[i]= LIMIT_INF_DEFAUT;
        m_Xmax[i]= LIMIT_SUP_DEFAUT;
    }
}
ProblemeOptimisation::ProblemeOptimisation() : m_NbreVariable(1) // lorsqu'on ne met pas d'argument au constructeur, la variable "m_NbreVariable" est par defaut initialisée à 1.
{
    m_Xmin = new float[1];
    m_Xmax = new float[1];
    m_Xmin[0] = LIMIT_INF_DEFAUT;
    m_Xmax[0] = LIMIT_SUP_DEFAUT;
}

ProblemeOptimisation::~ProblemeOptimisation()
{
    //dtor
}
struct_Result ProblemeOptimisation :: Solveur1 ()   // la méthode solveur1
{

}
struct_Result ProblemeOptimisation ::Solveur2 ()
{

}
struct_Result ProblemeOptimisation ::Solveur3 ()
{

}
struct_Result ProblemeOptimisation ::Solveur4 (float Xmax[], float Xmin[])
{

}
struct_Result ProblemeOptimisation ::Solveur5 (float Xmax[], float Xmin[])
{
    struct_Result Result;
    Result.P = new float[m_NbreVariable];

    float * EspXmin ;                                                     // Tableau contenant les valeurs limites inférieures du nouvel espace de recherche
    float * EspXmax ;                                                     // Tableau contenant les valeurs limites supérieures du nouvel espace de recherche
    double * NouvLargeur;                                                 // Tableau contenant Largeur du nouvel espace de recherche

    // Initialisation des tableaux


    NouvLargeur = new double [m_NbreVariable];
    EspXmin = new float [m_NbreVariable];
    EspXmax = new float [m_NbreVariable];

    Result = Solveur4 (Xmax, Xmin);                                      // Initialisation du resultat


    for (unsigned int i=0; i<m_NbreVariable; i=i+1)
    {
        NouvLargeur[i] = (Xmax[i]-Xmin[i])/2;                             // Divion par deux des largeurs initiales
    }



    for (unsigned int j=0; j<100; j=j+1)                                  // On reitère le processus 100 fois
        {
            for (unsigned int i=0; i<m_NbreVariable; i=i+1)
            {
                    EspXmin[i] = Result.P[i] - NouvLargeur[i]/2;           // Définition du nouvel espace de recherche
                    EspXmax[i] = Result.P[i] + NouvLargeur[i]/2;
                    NouvLargeur[i] = (EspXmax[i] - EspXmin[i])/2;          // On calcul la nouvelle largeur
            }

            Result = Solveur4 (EspXmax, EspXmin);
        }
    return Result;
}
struct_Result ProblemeOptimisation ::Solveur6 (bool Sens, float Pas)
{

}
struct_Result ProblemeOptimisation ::Solveur7 (bool Sens)
{
        struct_Result Result;
        Result.P = new float[m_NbreVariable];
        float pas;                                                              // pas
        float MaxLargDim = 0;                                                   // Plus large dimension
        float LargDim =0 ;

        // Evaluation de la plus large dimension
        for (unsigned int i=0; i<m_NbreVariable; i=i+1)
        {
            LargDim = m_Xmax [i] - m_Xmin [i];
            if (LargDim > MaxLargDim )
            {
                MaxLargDim = LargDim;
            }
        }

        pas = MaxLargDim/10;                                                    // Initialisation du pas

        while ( pas >= 0.001 )
        {
            Result = Solveur6 (Sens, pas);                                      // Appel du solveur 6
            pas = pas/10;
        }
        return Result;
}
float ProblemeOptimisation :: GenerateurAleatoire (float Min, float Max)
{
    float nRand ;

        nRand = float(Min + (float)(rand() * (Max-Min) / (RAND_MAX-1)));
        if ((nRand > Max) || (nRand < Min))
        {
            nRand = GenerateurAleatoire(Min, Max);
        }

    return nRand;
}
