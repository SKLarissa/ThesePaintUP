#ifndef ENREGISTRE_H
#define ENREGISTRE_H
#include "optimisation_export.h"
#include "ProblemeOptimisation/ProblemeOptimisation.h"

void OPTIMISATION_EXPORT EcritureFichier ();
void OPTIMISATION_EXPORT EcritureFichier (struct_Result R);
void OPTIMISATION_EXPORT Calcul(ProblemeOptimisation & p, char S[5]);

#endif