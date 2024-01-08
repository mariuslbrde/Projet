
#include "automate.h"
#include "lire_automate.h"
#include <stdio.h>


void lire_mot(struct automate * A, char * mot)
{
    int etat_actuel = A->etat_initial ;

    for (int i=0 ; mot[i] != '\0' ; i++)
    {
        char lettre = mot[i] ;
        int etat_prochain = -1 ;

        for (int j=0 ; j < A->nb_etats ; j++)
        {
            // si on peut aller quelque part avec la bonne lettre
            if (A->matrice_adjacence[etat_actuel][j] == 1 && A->matrice_transition[etat_actuel][j] == lettre)
            {
                etat_prochain = j ;
                break ;
            }
        }

        if (etat_prochain == -1) // si on a pu aller nul part
        {
            printf("La transition pour la lettre '%c' depuis l'état %d n'a pas été trouvée. Le mot est refusé.\n", lettre, etat_actuel) ;
            return  ; // quitte la fonction si la transition n'est pas trouvée
        }

        etat_actuel = etat_prochain ;
    }


    printf("L'automate termine dans l'état %d.\n", etat_actuel) ;
    
    if ( A->etat_final[etat_actuel] == 1 )
    {
        printf("L'automate a atteint un état final. Le mot est accepté.\n");
        return ;
    }
    else
    {
        printf("L'automate n'a pas atteint un état final. Le mot est rejeté.\n");
        return ;
    }
}
