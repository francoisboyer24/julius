#include <julius.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
  	int key;
  	
  	printf("Enter a message to encrypt: ");
  	// utilisation de la fonction de la librairie lire_stdin
	
	char * text = lire_stdin();

  	printf("Enter the key: ");
	//il faut rentrer un entier ici, sinon renvoyer un message d'erreur approprié
  	scanf("%d", & key);
  	//fonction de chiffrement
	chiffre(text,key);
	//ne pas oublier de vider le buffer
	free(text);
	return 0;
		
	
}

