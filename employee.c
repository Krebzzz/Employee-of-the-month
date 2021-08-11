#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void showMenu(){
    printf("\n\n\n");
    printf("\t*******************\n"
           "\t*    BIENVENUE    *\n"
           "\t*******************\n"
    "\n\n1.Gerer les employees\n2. Quitter le programme\n>"
    );
}
//----------------------------------------------

void Menu(){
    int choix;
    showMenu();
    scanf("%d%*c",&choix);
    while (choix != 2)
    {
        switch (choix)
        {
        case 1 :boucle_principal(); break;
        
        default: printf("Choix invalide ! Veuillez reesayer"); break;
        }

        showMenu();
        scanf("%d",&choix);
    }
    printf("Arret du programme");
    exit(0);
}

//----------------------------------------------

void create_employee(Employee *e, int i){
     printf("\nEntrer le nom de l'employe n.%d\n> ",i + 1);
     scanf("%s",e->name);

     printf("\nEntrer les 4 notes compris entre 0 et 20 :\n");
     printf("\nNote 1 > ");
     scanf("%f%*c",&e->mark1);

     printf("\nNote 2 > ");
     scanf("%f%*c",&e->mark2);

     printf("\nNote 3 > ");
     scanf("%f%*c",&e->mark3);

     printf("\nNote 4 > ");
     scanf("%f%*c",&e->mark4);
    
}

void moyenne_notes(float *mark1, float *mark2, float *mark3, float *mark4, Employee *e){
    int somme,moyenne;
     somme = *mark1 + *mark2 + *mark3 + *mark4;
     moyenne = somme / 4;
     return moyenne;
     
     
}
//----------------------------------------------

void boucle_principal(){
    Employee *tab = NULL;

    int nbEmployees = 0, taille_logique = 0, taille_physique = 50;
    int i;
    //Boucles principales
    putchar('\n');
    do
    {
        printf("Entrer le nombre d'employee(s), jusqu'a 50 max !\n> ");
        scanf("%d%*c",&nbEmployees);
    } while (nbEmployees < taille_logique || nbEmployees > taille_physique);

//----------------------------------------------

    tab = malloc(nbEmployees * sizeof(int));
    if (tab == NULL)
    {
        printf("Erreur");
        exit(1);
        
    }
 //----------------------------------------------   
    putchar('\n');
    
    for (int  i = 0; i < nbEmployees ; i++)
    {
        
        create_employee(&tab[i], i);
    }
//----------------------------------------------
    //Affichage 
    printf("\n--------------------------------------\n"
           "--------------------------------------\n"
    );
    for ( i = 0; i < nbEmployees ; i++)
        printf("\n> %s a obtenu les notes suivantes :%.1f , %.1f , %.1f , %.1f",tab[i].name, tab[i].mark1, tab[i].mark2, tab[i].mark3, tab[i].mark4);
        
    //Affichage moyenne 
    for ( i = 0; i < nbEmployees ; i++)
         printf("%s a une moyenne de > %d", tab[i].name, moyenne_notes(&tab[i].mark1,&tab[i].mark2,&tab[i].mark3,&tab[i].mark4, &tab[i]));
         
    free(tab);
}
