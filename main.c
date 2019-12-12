//***************************************Jeu du pendu****************************************

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>   //Permet d'utliser la fonction toupper() qui met en majuscule les lettre entrer par l'utilisateur
#include <string.h> // Permet de rechercher une lettre dans un mots
#include "dictionnaire.h"//Apelle de la fonction dictionnaire
#define SIZE    32
#define TAILLE_MAX 1000

FILE    *fichier = NULL;
int gagner(int lettreTrouver[],long tailleMot);
int rechercheLettre(char lettre, char motSecret[], int lettreTrouver[]);
int verification(char *name, char *nom);
char lireCaractere();

int main()
{
    char    pseudo[SIZE];
    FILE* fichier = NULL;
    int menu1,menu2,z;
    char lettre = 0; // Enregistre en memoire la lettre proposéepar l'utilisateur
    char motSecret[100] = {0}; // Le mot à Trouverr
    char chaine[TAILLE_MAX] = "";
    int *lettreTrouver = NULL; // Un tableau de booléens.
    long coupsRestants = 7; // Nombre de vie
    long i = 0; // Variable pour parcourir les tableaux
    long tailleMot = 0;
                    printf ("===============Jeu du Pendu=================\n\n");

    //while(!fin)
    //{

        fichier = fopen ("test.txt","a");
        if (fichier != NULL)
        {
           printf ("Entrer votre pseudo\n");
           scanf ("%s",&pseudo);
           fprintf(fichier,"\n%s ",pseudo);
        }
        fclose(fichier);
        printf ("\n\n");

    menu3:
    printf("=====     Menu             =====\n\n");
    printf("=====  1. Jouer            =====\n");
    printf("=====  2. Regle du jeu     =====\n");
    printf("=====  3. Plus grand score =====\n");
    printf("=====  0. Quitter          =====\n\n");
    scanf("%d",&menu1);
    printf("\n");
    switch(menu1)
    {
        case 0:
             return 0;

        break;

        case 1:

            men:
            printf("Bienvenue %s dans le Jeu de Pendu !\n Voulez vous commencer une partie ?\n\n============Tapez 1pour commencer et 0 pour revenir au menu===========\n",pseudo);
            scanf("%d",&z);

            if (z==0) goto menu3;
            else  if (z==1)

            {
            if (!selectMot(motSecret)) exit(0);

                tailleMot = strlen(motSecret);// On stocke la taille du motSecret

                lettreTrouver = malloc(tailleMot * sizeof(int)); // On alloue dynamiquement le tableau lettreTrouver (dont on ne connaissait pas la taille au départ)

            if (lettreTrouver == NULL) exit(0); //on verifie si le pointeur n'est pas null

            for (i = 0 ; i < tailleMot ; i++)  lettreTrouver[i] = 0; //mets les cases du tableau a 0

            while (coupsRestants > 0 && !gagner(lettreTrouver, tailleMot))// On continue à jouer tant qu'il reste au moins un coup à jouer ou qu'on n'a pas gagné
            {
                printf("\n Il vous reste %ld coups a jouer", coupsRestants);
                printf("\n Quel est le mot secret ? ");

//***********************On affiche le mot secret en masquant les lettres non trouvées******************************

                for (i = 0 ; i < tailleMot ; i++)
                {
                    if (lettreTrouver[i]) printf("%c", motSecret[i]); // Si on a trouvé une lettre on l'affiche
                    else printf("*"); // Sinon, on affiche une étoile pour les lettres non trouvées
                }

                printf("\n Choisissez une lettre : ");
                    lettre = lireCaractere();

                // Si ce n'était PAS la bonne lettre
                if (!rechercheLettre(lettre, motSecret, lettreTrouver))
                {
                    coupsRestants--; // On enlève un coup au joueur
                }
            }

            if (gagner(lettreTrouver, tailleMot))
                {
                    printf("\n  Vous avez gagner ! Le mot secret etait : %s\n", motSecret);
            fichier = fopen ("score.txt","a");
           // fichier = fopen ("test.txt","a");
            if (fichier != NULL)
            {
                    fprintf(fichier,"%ld",coupsRestants);
            }
                    fclose(fichier);
                }
            else
                {
                    printf("\n  Vous avez perdu ! Le mot secret etait : %s\n", motSecret);
                }
            free(lettreTrouver); // On libère la mémoire allouée manuellement
            }
            else
            {
                printf("Vous etes tetu reessayer\n");
                goto men;
            }

        coupsRestants = 7;
        break;

        case 2:
            printf ("Les regles de ce jeu sont tres simple\n\n");
            printf ("   1- L\'orsqu\'une lettre est correcte le nombre d'essaie reste inchange\n");
            printf ("   2- L\'orsqu\'une lettre est incorrecte le nombre d'essaie dimunie de 1\n");
            printf ("   3- L\'orsque tout le mot a ete deviner vous avez gagnerr\n");
            printf ("   4- L\'orsque le nombre d'essaie est a zero vous aver perdu\n\n");
            printf ("****************************BONNE CHANCE****************************\n\n\n\n");

            printf("===============Revenir au menu principal=============\n");
            scanf ("%d",&z);
            if(z==1) goto menu3;
            if(z==0) return 0;
        break;


        case 3:

               /* fichier = fopen("test.txt", "r+");
                if (fichier != NULL)
                {
                    while (fgets(chaine, TAILLE_MAX,fichier)!= NULL)
                    {
                        printf ("%s",chaine);
                    }
                    fclose(fichier);
                }
                printf ("\n\n");

                fichier = fopen("score.txt", "r+");
                if (fichier != NULL)
                {
                    int chaine[TAILLE_MAX];
                    int scoreMax=0,i=0,j=0;
                    int nbrElement=count(chaine);


                    while (coupsRestants !=0)
                    {
                        coupsRestants /=10;
                       count++;
                    }
                    printf ("Number of digits : %d",count);
                 nbrElement=count;
                    for (i=0;i<nbrElement;i++)
                    {
                        for(j=1;j<=nbrElement;j++)
                        {
                           int min=chaine[i],max=chaine[j];
                           if (min>max)
                           {
                               if(min>max) scoreMax=min;
                               printf("le score maximal est %d",scoreMax);
                           }
                           else
                           {
                               if(max>scoreMax) scoreMax=max;
                               printf("le score maximal est %d",scoreMax);
                           }
                        }

                    }

                    fclose(fichier);

                }*/


        break;


       // }

    }
        printf("\n=====        Voulez vous revenir au Menu ?          =====\n");
        printf("=====        Taper 1 pour revenir au menu principal ou 0 pour terminer        =====\n");
        scanf("%d",&menu2);
        printf("\n");

        menu4:
        if(menu2==1) goto menu3;
        else if(menu2==0) return 0;
        else goto menu4;

     return 0;

}




char lireCaractere()
{
    char caractere = 0;

    caractere = getchar(); // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà

    // On lit les autres caractères mémorisés un à un jusqu'à l'\n
    while (getchar() != '\n') ;

    return caractere; // On retourne le premier caractère qu'on a lu
}

int gagner(int lettreTrouver[], long tailleMot)
{
    long i = 0;
    int joueurgagner = 1;

    for (i = 0 ; i < tailleMot ; i++)
    {
        if (lettreTrouver[i] == 0)
            joueurgagner = 0;
    }

    return joueurgagner;
}






int rechercheLettre(char lettre, char motSecret[], int lettreTrouver[])
{
    long i = 0;
    int bonneLettre = 0;
    // On parcourt motSecret pour vérifier si la lettre proposée y est
    for (i = 0 ; motSecret[i] != '\0' ; i++)
    {
        if (lettre == motSecret[i]) // Si la lettre y est
        {
            bonneLettre = 1; // On mémorise que c'était une bonne lettre
            lettreTrouver[i] = 1; // On met à 1 le case du tableau de booléens correspondant à la lettre actuelle
        }
    }

    return bonneLettre;
}


