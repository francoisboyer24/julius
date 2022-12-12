#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

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

