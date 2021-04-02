#include "Probleme23/Probleme23.h"
#include <math.h>

#include <iostream>

#include <stdio.h>
#include <time.h>

using namespace std;

Probleme23::Probleme23() : ProblemeOptimisation(2), m_type(2)                   // Constructeur sanas argument. Par défaut, on considère qu'il s'agira d'un problème de type P2
{
        // initialisation des valeurs limites de l'espace de recherche
        m_Xmin[0]= LIMIT_INF_P_23_DEFAUT;
        m_Xmin[1]= LIMIT_INF_P_23_DEFAUT;
        m_Xmax[0]= LIMIT_SUP_P_23_DEFAUT;
        m_Xmax[1]= LIMIT_SUP_P_23_DEFAUT;

        m_P1 = new float[2];
        m_P2 = new float[2];
        m_P3 = new float[2];
        m_P4 = new float[2];

        m_P1[0]=-1.0;
        m_P1[1]=2.0;

        m_P2[0]=-3.0;
        m_P2[1]=5.0;

        m_P3[0]=0.0;
        m_P3[1]=0.0;

        m_P4[0]=0.0;
        m_P4[1]=0.0;


}

Probleme23::Probleme23(int n_type): ProblemeOptimisation(2), m_type(n_type)
// Constructeur avec un seul argument correspondant au type de problème.
// En effet, l'on peut minimiser la distance par rapport à 2, 3 ou 4 points.


{
    // initialisation des valeurs limites de l'espace de recherche
    m_Xmin[0]= LIMIT_INF_P_23_DEFAUT;
    m_Xmin[1]= LIMIT_INF_P_23_DEFAUT;
    m_Xmax[0]= LIMIT_SUP_P_23_DEFAUT;
    m_Xmax[1]= LIMIT_SUP_P_23_DEFAUT;

    m_P1 = new float[2];
    m_P2 = new float[2];
    m_P3 = new float[2];
    m_P4 = new float[2];


    if (m_type == 3)                        // Bonus : Minimisation par rapport à 3 points
    {
        m_P1[0]=-1.0;
        m_P1[1]=2.0;

        m_P2[0]=-3.0;
        m_P2[1]=5.0;

        m_P3[0]=-2.5;
        m_P3[1]=-3.5;

        m_P4[0]=0;
        m_P4[1]=0;
    }
    else if (m_type == 4)                 // Minimisation par rapport à 4 points
    {
        m_P1[0]=-1.0;
        m_P1[1]=2.0;

        m_P2[0]=-3.0;
        m_P2[1]=5.0;

        m_P3[0]=-2.5;
        m_P3[1]=-3.5;

        m_P4[0]=-4.2;
        m_P4[1]=3.7;
    }
    else                                 // Minimisation par rapport à 2 points
    {
        m_P1[0]=-1.0;
        m_P1[1]=2.0;

        m_P2[0]=-3.0;
        m_P2[1]=5.0;

        m_P3[0]=0.0;
        m_P3[1]=0.0;

        m_P4[0]=0.0;
        m_P4[1]=0.0;
    }
}


//  Bonus : Ce dernier cas d'initialisation sera utilisé lorsque la dimension des vecteurs est supérieure à 2.
// Les valeurs initiales n'étant pas précisées dans le texte, j'ai initialisé les deux premières composantes.
// Les autres composantes sont à 0. De cette façon, un objet de cette classe se comportera comme s'il était de
// dimension 2. Il faudra faire des "Set" sur les points P1,P2,P3 et P4 pour définir les coordonnées voulues.

Probleme23::Probleme23(int n_type, int n_NbreVar): ProblemeOptimisation(n_NbreVar), m_type(n_type)
{
    // initialisation des valeurs limites de l'espace de recherche
    for (unsigned int i=0; i<m_NbreVariable; i=i+1)
        {
            m_Xmin[i]= LIMIT_INF_P_23_DEFAUT;
            m_Xmax[i]= LIMIT_SUP_P_23_DEFAUT;
        }

    m_P1 = new float[m_NbreVariable];
    m_P2 = new float[m_NbreVariable];
    m_P3 = new float[m_NbreVariable];
    m_P4 = new float[m_NbreVariable];

    // Initialisation des deux premières coordonnées des points P
    if (m_type == 3)
    {
        m_P1[0]= -1.0;
        m_P1[1]= 2.0;

        m_P2[0]= -3.0;
        m_P2[1]= 5.0;

        m_P3[0]= -2.5;
        m_P3[1]= -3.5;

        m_P4[0]= 0.0;
        m_P4[1]= 0.0;
    }
    else if (m_type == 4)
    {
        m_P1[0]=-1.0;
        m_P1[1]=2.0;

        m_P2[0]=-3.0;
        m_P2[1]=5.0;

        m_P3[0]=-2.5;
        m_P3[1]=-3.5;

        m_P4[0]=-4.2;
        m_P4[1]=3.7;
    }
    else
    {
        m_P1[0]=-1.0;
        m_P1[1]=2.0;

        m_P2[0]=-3.0;
        m_P2[1]=5.0;

        m_P3[0]=0.0;
        m_P3[1]=0.0;

        m_P4[0]=0.0;
        m_P4[1]=0.0;
    }

    // Initialisation des autres coordonnées des points P
    for (unsigned int i=2; i<m_NbreVariable; i=i+1)
        {
            m_P1[i]=0.0;
            m_P2[i]=0.0;
            m_P3[i]=0.0;
            m_P4[i]=0.0;
        }
}

Probleme23::~Probleme23()
{
    //dtor
}

float Probleme23 :: def_fonction(float P[])                      // definition de la fonction f(P)
{
    float y = 0;
    for (unsigned int i=0; i<m_NbreVariable; i=i+1)
        {
            if (m_type == 3)                                     // Evaluation de la distance par rapport à 3 points
            {
                y = y + (P[i]-m_P1[i])*(P[i]- m_P1[i]) + (P[i] - m_P2[i])*(P[i] - m_P2[i]) + (P[i]-m_P3[i])*(P[i] - m_P3[i]);
            }
            else if (m_type == 4)                                // Evaluation de la distance par rapport à 34points
            {
                y = y + (P[i]-m_P1[i])*(P[i]- m_P1[i]) + (P[i]- m_P2[i])*(P[i]-m_P2[i]) + (P[i]-m_P3[i])*(P[i]-m_P3[i]) + (P[i]-m_P4[i])*(P[i]-m_P4[i]);
            }
            else                                                // Evaluation de la distance par rapport à 2 points
            {
                y = y + (P[i]-m_P1[i])*(P[i]- m_P1[i]) + (P[i]- m_P2[i])*(P[i]-m_P2[i]);
            }
        }
    return y;
}
struct_Result Probleme23 ::Solveur2 ()
{
    float *Ecart;
    float f;
    float *x;
    struct_Result Result;
    Result.P = new float[m_NbreVariable];
    Ecart =  new float[m_NbreVariable];
    x = new float[m_NbreVariable];

    Result.Fmin = def_fonction(m_Xmin) ;
    for (unsigned int i=0; i<m_NbreVariable; i=i+1)
        {
            Result.P[i] = m_Xmin [i];
        }

        for (unsigned int i=0; i<m_NbreVariable; i=i+1)
        {
            Ecart[i] = (m_Xmax [i] - m_Xmin [i])/9;
        }

    switch(m_NbreVariable)
    {
    case 2:

        for (unsigned int i=0; i<9; i=i+1)
        {
            x[0] = m_Xmin [0]+ i*Ecart[0];
            for (unsigned int j=0; j<9; j=j +1)
            {
              x[1] = m_Xmin [1] + j*Ecart[1];
              f = def_fonction(x);
              if (f < Result.Fmin)
              {
                Result.Fmin = f;
                for (unsigned int l=0; l<m_NbreVariable; l=l+1)
                {
                    Result.P[l] = x [l];
                }

              }
            }
        }
        break;
    case 3:
        for (unsigned int i=0; i<9; i=i+1)
        {
            x[0] = m_Xmin [0]+ i*Ecart[0];
            for (unsigned int j=0; j<9; j=j +1)
            {
              x[1] = m_Xmin [1] + j*Ecart[1];
              for (unsigned int k=0; k<9; k=k +1)
                {
                  x[2] = m_Xmin [2] + k*Ecart[2];

                  f = def_fonction(x);
                  if (f < Result.Fmin)
                  {
                    Result.Fmin = f;
                    for (unsigned int l=0; l<m_NbreVariable; l=l+1)
                    {
                        Result.P[l] = x[l];
                    }
                  }
                }
            }
        }

    }
    return Result;
}
struct_Result Probleme23 :: Solveur3 ()
{
    struct_Result Result;                                        // Structure contenant le resultat
    Result.P = new float[m_NbreVariable];

    float Ecart;                                                 // Variable contenant l'ecart entre les différents points
    float f;                                                     // Variable contenant le resultat de la fonction

    float * x ;                                                  // Variable contenant les coordonnées du point recherché (conduisant au minimum de la fonction ).Cette variable se balade dans l'espace de recherche
    x = new float [m_NbreVariable];

    // Initialisation du point recherché au point central de l'espace
    for (unsigned int i=0; i<m_NbreVariable; i=i+1)
    {
        x[i]= m_Xmin [i] + (m_Xmax [i]- m_Xmin [i])/2;
        Result.P[i] = x[i];
    }

    Result.Fmin = def_fonction(x) ;

    for (unsigned int i=0; i<m_NbreVariable; i=i+1)
    {
        Ecart = (m_Xmax [i] - m_Xmin [i])/9;                      // Calcul de l'écart
        for (unsigned int j=0; j<10; j=j+1)                       // Pour chacune des 10 valeurs
        {
          x[i] = m_Xmin [i] + j*Ecart;
          f = def_fonction(x);
          if (f < Result.Fmin)
          {
            Result.Fmin = f;
            Result.P[i] = x[i];
          }
        }
        x[i] = Result.P[i];
    }


    return Result;
}
struct_Result  Probleme23 ::Solveur4 (float Xmax[], float Xmin[])  // Xmin représente le vecteur  contenant les limites inférieures de l'espace de recherche (pour toutes les dimension).
                                                                   // Xmax représente le vecteur  contenant les limites supérieures de l'espace de recherche (pour toutes les dimensions).
{
    struct_Result Result;
    Result.P = new float[m_NbreVariable];

    float * Buffer_Xmax;
    float * Buffer_Xmin;

    float * x ;
    float f;

    x = new float [m_NbreVariable];
    Buffer_Xmax = new float [m_NbreVariable];
    Buffer_Xmin = new float [m_NbreVariable];

    // Copie des paramètres d'entrées
    for (unsigned int i=0; i<m_NbreVariable; i=i+1)
    {
        Buffer_Xmax[i]= Xmax[i];
        Buffer_Xmin[i]= Xmin[i];
    }

    // On vérifie que l'espace entrée en paramètre est dans l'espace de travail du problème.
    // Si ce n'est pas le cas, on rogne juste l'espace de travail.
    for (unsigned int i=0; i<m_NbreVariable; i=i+1)
    {
        if (m_Xmin [i] > Buffer_Xmin[i])
        {
           Buffer_Xmin[i] = m_Xmin [i];
        }

        x[i]= Buffer_Xmin [i];                    // Initialisation du vecteur recherché.
        Result.P[i] = Buffer_Xmin [i];

        if (Buffer_Xmax [i] >= m_Xmax[i])
        {
            Buffer_Xmax [i] = m_Xmax [i];
        }
    }

    Result.Fmin = def_fonction(x) ;

    srand(time(NULL));                                                                      //  (time(NULL) permet d'utiliser le temps comme graine du générateur)
    for (unsigned int i=0; i<1000; i=i+1)
        {

            for (unsigned int j=0; j<m_NbreVariable; j=j+1)
             {
                    x[j] = GenerateurAleatoire(Buffer_Xmin[j],Buffer_Xmax[j]);             // Appel de la fonction qui génère les nombres aléatoires

             }
          f = def_fonction(x);
          if (f < Result.Fmin)
          {                                                                                // Copie de la solution trouvée
            Result.Fmin = f;
            for (unsigned int j=0; j<m_NbreVariable; j=j+1)
             {
                    Result.P[j] = x[j];
             }
          }
        }
        return Result;
}

struct_Result Probleme23 ::Solveur6 (bool Sens, float Pas)                              // La variable Sens renseigne sur le sens du chemin
{
    struct_Result Result;
    Result.P = new float[m_NbreVariable];

    float AncienFmin;
    float NouvFmin;
    unsigned int IndiceMin = 0;                                                         // Conserve l'indice ou la fonction est minime


    float * x ;
    float * Buffer_x ;
    float f;
    float Buffer_pas;                                                              // pas
    float MaxLargDim = 0;                                                          // Plus large dimension
    float LargDim ;

    x = new float [m_NbreVariable];
    Buffer_x = new float [m_NbreVariable];

    // initialisation de x au point milieu de l'espace de recherche

    for (unsigned int i=0; i<m_NbreVariable; i=i+1)
    {
        x[i] = m_Xmin [i] + (m_Xmax [i]- m_Xmin [i])/2;
        Buffer_x[i]= m_Xmin [i] + (m_Xmax [i]- m_Xmin [i])/2;
    }

    // Initialisation de la plus petite valeur de f
    NouvFmin = def_fonction (x);
    AncienFmin = 0;


    // Définition du pas
    if (Pas == 0.0)
    {
        // Evaluation de la plus large dimension
        for (unsigned int i=0; i<m_NbreVariable; i=i+1)
        {
            LargDim = m_Xmax [i] - m_Xmin [i];
            if (LargDim > MaxLargDim )
            {
                MaxLargDim = LargDim;
            }
        }
        Buffer_pas = MaxLargDim/10;
    }
    else
    {
        Buffer_pas = Pas;
    }
    while (NouvFmin!=AncienFmin)
    {
        AncienFmin = NouvFmin;
        for (unsigned int i=0; i<m_NbreVariable; i=i+1)
        {

            // En fonction du sens choisi, on enlève ou un retranche le pas
            if (Sens==true)
            {
                Buffer_x[i] = x[i] + Buffer_pas;

                // Lorsque nous sommes hors limite, on ramène la valeur du buffer dans la limite
                if (Buffer_x[i] > m_Xmax[i])
                {
                    Buffer_x[i] = m_Xmax[i];
                }
            }
            else
            {
                Buffer_x[i] = x[i] - Buffer_pas;
                if (Buffer_x[i]<= m_Xmin[i])
                {
                    Buffer_x[i] = m_Xmin[i];
                }
            }
            f =  def_fonction (Buffer_x);
            if ( f < NouvFmin)
            {
                NouvFmin = f;
                IndiceMin = i;
            }
            Buffer_x[i] = x[i];                                 // Remet la valeur de Buffer sans pas dans la direction donnée.
        }
        if (NouvFmin!=AncienFmin)                               // Actualisation de la valeur conduisant à minimiser f.
        {
            if (Sens==true)
            {
                x[IndiceMin] = x[IndiceMin] + Buffer_pas;

                // Lorsque nous sommes hors limite, on ramène la valeur du buffer dans la limite
                if (x[IndiceMin] >= m_Xmax[IndiceMin])
                {
                    x[IndiceMin]  = m_Xmax[IndiceMin];
                }
            }
            else
            {
                x[IndiceMin] = x[IndiceMin] - Buffer_pas;
                if (x[IndiceMin] <= m_Xmin[IndiceMin])
                {
                    x[IndiceMin] = m_Xmin[IndiceMin];
                }
            }

        }
    }
    Result.Fmin = NouvFmin;
    for (unsigned int i=0; i<m_NbreVariable; i=i+1)
    {
        Result.P[i]=x[i];
    }
    return Result;
}
struct_Result Probleme23 :: Solveur1 ()
{
    struct_Result Result;
    Result.P = new float[m_NbreVariable];

    // On cherche le minimum de l'espace de travail

    for (unsigned int i=0; i<m_NbreVariable; i=i+1)
    {
        Result.P[i] = m_Xmin[i] + (m_Xmax[i]- m_Xmin[i])/2;
    }

    Result.Fmin = def_fonction (Result.P);

    return Result;
}


