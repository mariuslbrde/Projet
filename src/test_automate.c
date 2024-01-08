#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include <automate.h>
#include <creer_automate.h>
#include <lire_automate.h>
#include <liberer_automate.h>

int main(void)
{
   struct automate * A = nouvel_automate(4,0) ;
   
    ajoute_transition (A, 0, 1, 'b') ;
    ajoute_transition (A, 0, 2, 'a') ;
    ajoute_transition (A, 2, 2, 'b') ;
    ajoute_transition (A, 1, 3, 'b') ;
    ajoute_transition (A, 2, 3, 'a') ;
    ajoute_transition (A, 1, 1, 'b') ;
    A->etat_final[2] = 1 ;
    A->etat_final[3] = 1 ;//état final

   char mot[20] ;
   printf("Entrez un mot (avec l'alphabet {a,b}) :  ") ;
   scanf("%s", mot) ;
   lire_mot(A, mot) ;
   
    libere_automate(A);
   
   return 0 ;
}
