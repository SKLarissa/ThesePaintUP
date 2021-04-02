
#include "Probleme14/Probleme14.h"
#include <math.h>


#include <iostream>
using namespace std;



Probleme14::Probleme14(): ProblemeOptimisation(), m_type (1)
{
a = 4.0;
b = 3.0;
c = 2.0;
m_Xmin [0]= LIMIT_INF_P_14_DEFAUT;
m_Xmax [0] = LIMIT_SUP_P_14_DEFAUT;
}

Probleme14::Probleme14(unsigned int n_type): ProblemeOptimisation(), m_type (n_type)
{
a = 4.0;
b = 3.0;
c = 2.0;
m_Xmin [0]= LIMIT_INF_P_14_DEFAUT;
m_Xmax [0] = LIMIT_SUP_P_14_DEFAUT;
}

Probleme14::~Probleme14()
{
    //dtor
}
float Probleme14:: def_fonction(float x)
{
    float y;
    y = c + b*x + a*x*x;
    if (m_type == 2)
    {
        y = exp (y);
    }
    return y;
}
struct_Result Probleme14 :: Solveur2 ()
{
    float Ecart;
    float f;                                           // Variable contenant le resultat de la fonction
    float x;                                           // Variable contenant le point discretiser
    struct_Result Result;
    Result.P = new float[1];
    Ecart = (m_Xmax [0] - m_Xmin [0])/9;               // Discretisation par 10 de l'espace de travail
    Result.Fmin = def_fonction(m_Xmin [0]) ;
    Result.P[0] = m_Xmin [0];
    for (unsigned int i=0; i<9; i=i+1)
        {
          x = m_Xmin [0] + i*Ecart;
          f = def_fonction(x);
          if (f < Result.Fmin)
          {
            Result.Fmin = f;
            Result.P[0] = x;

          }
        }

    return Result;

}
struct_Result Probleme14 ::Solveur3 ()
{
    struct_Result Result;
    Result = Solveur2();
    return Result;

}
struct_Result Probleme14 ::Solveur4 (float Xmax[], float Xmin[])
{
    struct_Result Result;
    Result.P = new float[1];
    float x ;
    float f;

    float Buffer_Xmax;
    float Buffer_Xmin;


    Buffer_Xmax = Xmax[0];
    Buffer_Xmin = Xmin[0];

    if (m_Xmin [0] > Buffer_Xmin)
    {
        Buffer_Xmin = m_Xmin [0];
    }
    x = Buffer_Xmin;
    Result.Fmin = def_fonction(x) ;
    Result.P[0] = Buffer_Xmin;
    if (Buffer_Xmax  >= m_Xmax[0])
    {
        Buffer_Xmax = m_Xmax [0];
    }


    srand(time(NULL));                                     //  (time(NULL) permet d'utiliser le temps comme graine du générateur)

    for (unsigned int i=0; i<1000; i=i+1)
        {
          x = GenerateurAleatoire(Buffer_Xmin,Buffer_Xmax);
          f = def_fonction(x);
          if (f < Result.Fmin)
          {
            Result.Fmin = f;
            Result.P[0] = x;
          }
        }
        return Result;
}
struct_Result Probleme14 ::Solveur6 (bool Sens, float Pas)
{
    struct_Result Result;
    Result.P = new float[1];

    float NouvFmin ;
    float AncienFmin ;



    float  x =0;
    float  Buffer_x ;
    float  Buffer_pas;                                                              // pas

    float LargDim ;



    // initialisation de x au point milieu de l'espace de recherche


        Buffer_x = m_Xmin [0] + (m_Xmax [0]- m_Xmin [0])/2;

    // Initialisation de la plus petite valeur de f
    NouvFmin = def_fonction (Buffer_x);
    AncienFmin = NouvFmin;



    // Définition du pas
    if (Pas == 0.0)
    {
        LargDim = m_Xmax [0] - m_Xmin [0];
        Buffer_pas = LargDim/10;
    }
    else
    {
        Buffer_pas = Pas;
    }
    while ((NouvFmin <= AncienFmin) && (x != m_Xmax[0]) && (x != m_Xmin[0]))
    {

        AncienFmin = NouvFmin;
        x = Buffer_x;
        if (Sens==true)
            {
                Buffer_x = Buffer_x + Buffer_pas;

                // Lorsque nous sommes hors limite, on ramène la valeur du buffer dans la limite
                if (Buffer_x > m_Xmax[0])
                {
                    Buffer_x = m_Xmax[0];
                }
            }
            else
            {
                Buffer_x = Buffer_x - Buffer_pas;
                if (Buffer_x<= m_Xmin[0])
                {
                    Buffer_x= m_Xmin[0];
                }
            }
            NouvFmin =  def_fonction (Buffer_x);
    }
    Result.Fmin = AncienFmin;
    Result. P[0] = x;

    return Result;
}
struct_Result Probleme14 :: Solveur1 ()
{
    struct_Result Result;
    Result.P = new float[1];

    // On cherche le minimum de l'espace de travail

    Result.P[0] = m_Xmin[0] + (m_Xmax[0]- m_Xmin[0])/2;

    Result.Fmin = def_fonction (Result.P[0]);

    return Result;
}

