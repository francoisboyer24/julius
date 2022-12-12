#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

char * lire_stdin(){
	size_t maxtab = 100; //initialise le nb de caractères pour le buffer de caractères
	size_t position = 0; //lecture caractère par caractère
	char * buffer = malloc(maxtab * sizeof(char));
	int c;
	//on parcourt stdin jusqu'à ce qu'on arrive au dernier retour charriot
	while((c =  fgetc(stdin))!='\n' && !feof(stdin)){
		buffer[position] = c;
		//on controle s'il reste de l'espace mémoire
		if (++position == maxtab){
			//s'il n'en reste pas, on alloue deux fois la taille allouée
			buffer = realloc(buffer, (maxtab*=2) * sizeof(char));
		}
		
		
		
		
	}
	buffer = realloc(buffer, (position + 1) * sizeof(char));
	buffer[maxtab] ='\0';
	
	return buffer;

}

void chiffre(char chaine[], int shift){
	int i=0;
	
	while(chaine[i] != '\0'){
		char char_act = chaine[i];
		printf("ok %i \n",char_act);
		//gestion des majuscules, code ascii décimal entre 65 et 90
		if (isupper(char_act)){
			char_act = (char_act -'A'+ shift)%26 + 'A';
			printf("après chiffrement: %i \n",char_act);
		}
		//gestion des minuscules, code ascii décimal entre 97 et 122
		if (islower(char_act)){
			char_act = (char_act -'a'+ shift)%26 + 'a';
			printf("après chiffrement: %i \n",char_act);
		}
		//remplacement de la chaîne
		chaine[i] = char_act;
		i++;
	}
	printf("%s \n", chaine);
}

