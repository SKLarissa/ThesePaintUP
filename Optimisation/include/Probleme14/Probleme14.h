#ifndef Probleme14_H
#define Probleme14_H

#define LIMIT_INF_P_14_DEFAUT -2     // Limite inférieure par défaut des problèmes 1 et 4
#define LIMIT_SUP_P_14_DEFAUT 2      // Limite supérieure par défaut des problèmes 1 et 4

#include "ProblemeOptimisation/ProblemeOptimisation.h"

#include "optimisation_export.h"

#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;

class OPTIMISATION_EXPORT Probleme14 : public ProblemeOptimisation
{
    public:
        Probleme14(unsigned int n_type);
        Probleme14();
        virtual ~Probleme14();

        unsigned int Gettype() { return m_type; }
        void Settype(unsigned int val) { m_type = val; }

        float Geta() { return a; }
        void Seta(float val) { a = val; }

        float Getb() { return b; }
        void Setb(float val) { b = val; }

        float Getc() { return c; }
        void Setc(float val) { c = val; }


        float def_fonction(float x);

        struct_Result Solveur1 ();
        struct_Result Solveur2 ();
        struct_Result Solveur3 ();
        struct_Result Solveur4 (float Xmax[], float Xmin[]);
        struct_Result Solveur6 (bool Sens, float Pas);

    protected:

    private:
        unsigned int m_type; // L'attribut m_type permet de distinguer le type de problème 1 du type de problème 4
        float a;             // L'équation du second degre a la forme générale suivante : ax^2 + bx + c
        float b;
        float c;
};

#endif // Probleme14_H
