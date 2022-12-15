#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
//à changer avec le chemin de la librairie
#include "/home/boyer/Bureau/Cesar/julius/include/check.h"
//pour l'utilisation de CHECK_IF
#define DEBUG

//lecture de l'entrée standard ou d'un fichier
char * lire(FILE *fichier){
	size_t maxtab = 100; //initialise le nb de caractères pour le buffer de caractères
	size_t position = 0; //lecture caractère par caractère
	//tester les valeurs de retour des appels système
	char * buffer; 
	CHECK_IF( buffer = malloc(maxtab * sizeof(char)),NULL,"malloc");
	int c = 0;
	//on parcourt le fichier jusqu'à ce qu'on arrive au dernier retour charriot
	//c =  fgetc(fichier))!='\n' &&
	
	do{	
		c = fgetc(fichier);
		buffer[position] = c;
		//on controle s'il reste de l'espace mémoire
		if (++position == maxtab){
			//s'il n'en reste pas, on alloue deux fois la taille allouée
			CHECK_IF(buffer = realloc(buffer, (maxtab*=2) * sizeof(char)),NULL,"realloc");
		}	
	}while(c != EOF);
	fclose(fichier);
	
	CHECK_IF(buffer = realloc(buffer, (position + 1) * sizeof(char)),NULL,"realloc");
	buffer[maxtab] ='\0';
	
	return buffer;

}


void chiffre(char chaine[], int shift){
	int i=0;
	//on traite le cas négatif: -5 <=> 21
	if(shift < 0) { shift = 26 + (shift % 26);}
	while(chaine[i] != '\0'+'\0'){
		char char_act = chaine[i];
		//gestion des majuscules, code ascii décimal entre 65 et 90
		if (isupper(char_act)){
			char_act = (char_act -'A'+ shift)%26 + 'A';
		}
		//gestion des minuscules, code ascii décimal entre 97 et 122
		if (islower(char_act)){
			char_act = (char_act -'a'+ shift)%26 + 'a';
		}
		//remplacement de la chaîne
		chaine[i] = char_act;
		i++;
	}
	printf("%s \n", chaine);
}

