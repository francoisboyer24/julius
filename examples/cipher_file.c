#include <julius.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	FILE* fichier = NULL;
    	int caractereActuel = 0;
 
    	fichier = fopen("/home/boyer/Bureau/Cesar/julius/examples/fichier_test.txt", "r");
	
    	if (fichier != NULL)
    {
        printf("bonjour le fichier");// Boucle de lecture des caractères un à un
        do
        {
            caractereActuel = fgetc(fichier); // On lit le caractère
            printf("%c", caractereActuel); // On l'affiche
        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
 
        fclose(fichier);
    }
 
    return 0;
}

