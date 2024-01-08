
#include "automate.h"

void libere_automate (struct automate * A)
{
   for (int i=0 ; i<A->nb_etats ; i++)
   {
      free(A->matrice_adjacence[i]) ;
      free(A->matrice_transition[i]) ;
   }
   
   free(A->matrice_adjacence) ;
   free(A->matrice_transition) ;
   free(A->etat_final) ;
   free(A) ;
}
