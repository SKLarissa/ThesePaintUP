#ifndef PROBLEMEOPTIMISATION_H
#define PROBLEMEOPTIMISATION_H

#define LIMIT_INF_DEFAUT -1000
#define LIMIT_SUP_DEFAUT 1000

#include "optimisation_export.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
using namespace std;

struct OPTIMISATION_EXPORT struct_Result       // Structure contenant le resultat
        {
            float * P;     // Pointeur vers le point X conduisant à la plus petite valeur de F.
            float Fmin;    // Plus petite valeur de F correspondant
        };

class OPTIMISATION_EXPORT ProblemeOptimisation
{
    public:

        ProblemeOptimisation(unsigned int n_NbreVar);
        ProblemeOptimisation();
        virtual ~ProblemeOptimisation();

        unsigned int GetNbreVariable() { return m_NbreVariable; }
        void SetNbreVariable(unsigned int val) { m_NbreVariable = val; }

        float * GetXmin(){ return  m_Xmin; }
        void SetXmin(float * val ) { m_Xmin = val; }

        float * GetXmax(){ return  m_Xmax; }
        void SetXmax( float * val) { m_Xmax = val; }

        float GenerateurAleatoire (float Min, float Max);

        virtual struct_Result Solveur1 ();
        virtual struct_Result Solveur2 ();
        virtual struct_Result Solveur3 ();
        virtual struct_Result Solveur4 (float Xmax[], float Xmin[]);
        virtual struct_Result Solveur6 (bool Sens, float Pas);

        struct_Result Solveur5 (float Xmax[], float Xmin[]);
        struct_Result Solveur7 (bool Sens);





    protected:

        unsigned int m_NbreVariable; // contient le nombre de variable du problème.

        // Les tableaux m_Xmin et m_Xmax contiennent respectivement les valeurs minimales et maximales de chaque dimension

        float * m_Xmin;
        float * m_Xmax;



    private:
};

#endif // PROBLEMEOPTIMISATION_H
