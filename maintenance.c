#include "livreDeCompte.h"
#include "utils_v1.h"
#include <string.h>

#define MAX 256
int main(int argc, char const *argv[])
{
	char* str1 = "Entrez une option de 1 à 3\n";
	swrite(1, str1, strlen(str1));
	char buf[MAX];
	sread(0,buf,MAX);
	int choix = atoi(buf);

	int sem_id;
	int shm_id;	

	if(choix==1){

		int *comptes;
		//Creer semaphoress
		sem_id = sem_create(SEM_KEY, 1, PERM, 1);
		//Creer memoire partagé
		shm_id = sshmget(SHM_KEY, MAX_COMPTES*sizeof(int), IPC_CREAT | PERM);
		comptes = (int*)sshmat(shm_id);
		for(int i = 0; i<MAX_COMPTES; i++){
			comptes[i]=0;
		}

	} else if(choix==2){
		shm_id = sshmget(SHM_KEY, MAX_COMPTES*sizeof(int), IPC_CREAT | PERM);
		sem_id = sem_get(SEM_KEY, 1);
		sshmdelete(shm_id);
		sem_delete(sem_id);
	} else if(choix==3){
		char *mess = "Combien de délai?\n";
		swrite(1,mess,strlen(mess));
		char nbr[MAX];
		sread(0,nbr,MAX);
		nbr[strlen(nbr)-1] = '\0';
		int rep = atoi(nbr);
		sem_id = sem_get(SEM_KEY,0);
		sem_down0(sem_id);
		sleep(rep);
		sem_up0(sem_id);

	} else {
		perror("Commande invalide");
		exit(1);
	}

	return 0;
}