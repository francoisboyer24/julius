#include <julius.h>
#include <stdio.h>
#define MAXLEN 100

int main(void) {
	char text[MAXLEN];
  	int key;
  	
  	printf("Enter a message to encrypt: ");
	
  	fgets(text, MAXLEN, stdin);

  	printf("Enter the key: ");
	//il faut rentrer un entier ici, sinon renvoyer un message d'erreur approprié
  	scanf("%d", & key);
	chiffre(text,key);
		
	
}

