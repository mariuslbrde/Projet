#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>


struct automate
{
   int nb_etats ;
   int ** matrice_adjacence ; // contient des 0 ou 1 (transition ou non)
   char ** matrice_transition ; // contient les symboles/lettres des transitions
   int etat_initial ;
   int * etat_final ; // tab de int, pour chaque état : 1 ou 0 (final ou non)
};

