#include <julius.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	FILE* fichier = NULL;
	int key;
    	int caractereActuel = 0;
    	//printf("veuillez saisir le chemin du fichier que vous souhaitez cripter: ");
    	//on lit le chemin du fichier à cripter depuis stdin, rentré par l'utilisateur
 	//char * cheminFichier = lire(stdin);
    	fichier = fopen(argv[1],"r");
    	//free(cheminFichier);
	char * text = lire(fichier);

  	printf("Enter the key: ");
	//il faut rentrer un entier ici, sinon renvoyer un message d'erreur approprié
  	scanf("%d", & key);
  	//fonction de chiffrement
	chiffre(text,key);
	//ne pas oublier de vider le buffer
	free(text);
    	
 
    return 0;
}

