
/*      char    pseudo[SIZE];
        FILE    *fichier = NULL;
        int     test = 0;

int verification(char *name, char *nom)
{
        char    mot[SIZE];
        FILE    *fic;

        fic = fopen(name, "r");
        if (fic == NULL) {
                printf("Erreur lors de l'ouverture\n");
                return -1;
        }
        while (fgets(mot, SIZE, fic) != NULL) {
                char    *tmp;

                tmp = strchr(mot, '\n');
                if (tmp != NULL)
                        *tmp = '\0';
                if (strcmp(mot, nom) == 0) {
                        fclose(fic);
                        return 1;
                }
        }
        fclose(fic);
        return 0;
}*/
