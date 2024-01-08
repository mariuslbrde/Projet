
#include "automate.h"
#include "creer_automate.h"

struct automate * nouvel_automate (int n, int init)
{
   struct automate * new ;
   
   if (n<=0)
      { return NULL; }
   
   new = malloc(sizeof(struct automate)) ;
   new->nb_etats = n ;
   new->matrice_adjacence = malloc(n*sizeof(int *)) ;
   new->matrice_transition = malloc(n*sizeof(char *)) ;
   new->etat_initial = init ;
   new->etat_final = malloc(n * sizeof(int));
   
   for (int i=0 ; i<n ; i++)
   {
      new->matrice_adjacence[i] = malloc(n*sizeof(int)) ;
      new->matrice_transition[i] = malloc(n*sizeof(char)) ;
      for (int j=0 ; j<n ; j++)
      {
         new->matrice_adjacence[i][j] = 0 ;
         new->matrice_transition[i][j] = '\0' ;
      }
      new->etat_final[i] = 0 ;
   }
   return new ;
}


void ajoute_transition (struct automate * A, int i, int j, char l)
{
   if ( (i<0) || (i>=A->nb_etats) )
      { return ; }
   if ( (j<0) || (j>=A->nb_etats) )
      { return ; }
      
   A->matrice_adjacence[i][j] = 1 ;
   A->matrice_transition[i][j] = l ;
}
