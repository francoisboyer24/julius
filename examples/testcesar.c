#include <stdio.h>
#include "cesar.h"
#include <string.h>
#define SHIFT 4
#define CHAINE "BONJOUR"
int main(void) {
	char chaine[] = CHAINE;
	cesar(chaine,SHIFT);	
}
