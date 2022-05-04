#include "livreDeCompte.h"
#include "utils_v1.h"
#include <string.h>

int main(int argc, char const *argv[])
{
	char* str1 = "Entrez une option de 1 à 3\n";
	swrite(1, str1, strlen(str1));
	char* choix;
	sread(0,&choix,strlen(choix));
	int t  = *choix + '0';
	printf("%s\n", choix);
	printf("%d\n", t);

	// if(choix == 1){
	// 	printf("Choix1\n");
	// } else if(choix == 2){
	// 	printf("Choix2\n");
	// } else if(choix == 3){
	// 	printf("Choix3\n");
	// }
	
	return 0;
}