#ifndef PROBLEME23_H
#define PROBLEME23_H


#define LIMIT_INF_P_23_DEFAUT -100     // Limite inf�rieure par d�faut des probl�mes 2 et 3
#define LIMIT_SUP_P_23_DEFAUT 100      // Limite sup�rieure per d�faut des probl�mes 2 et 3

#include "ProblemeOptimisation/ProblemeOptimisation.h"
#include "optimisation_export.h"

#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;

class OPTIMISATION_EXPORT Probleme23 : public ProblemeOptimisation
{
    public:
        Probleme23();
        Probleme23(int n_type);
        Probleme23(int n_type, int n_NbreVar);

        virtual ~Probleme23();

       unsigned int Gettype() { return m_type; }
        void Settype(unsigned int val) { m_type = val; }

        float * GetP1() { return m_P1; }
        void SetP1(float * val) { m_P1 = val; }

        float * GetP2() { return m_P2; }
        void SetP2(float * val) { m_P2 = val; }

        float * GetP3() { return m_P3; }
        void SetP3(float * val) { m_P3 = val; }

        float * GetP4() { return m_P4; }
        void SetP4(float * val) { m_P4 = val; }


        float def_fonction(float P[]);   // le vecteur x represente les coordonnees du point P le plus proche des points P1, P2, P3 et P4

        struct_Result Solveur1 ();
        struct_Result Solveur2 ();
        struct_Result Solveur3 ();
        struct_Result Solveur4 (float Xmax[], float Xmin[]);
        struct_Result Solveur6 (bool Sens, float Pas);

    protected:

    private:
        float * m_P1;       // Premier point par rapport auquel on �valu la distance
        float * m_P2;       // Deuxi�me point par rapport auquel on �valu la distance
        float * m_P3;       // Troisi�me point par rapport auquel on �valu la distance
        float * m_P4;       // Quatri�me point par rapport auquel on �valu la distance
        unsigned int m_type;// definit le type sp�cifique de probl�me. Il peut s'agir d'un probl�me de type P2 ou P3.

};

#endif // PROBLEME23_H
