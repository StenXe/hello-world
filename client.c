#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include "shared_stuff.h"

int main(void)
{ 
	int running = 1;
	void *shm = NULL;
	struct shared_stuff_st *memo;
	int shmid;
	key_t key;
	key = KEY;
	char buffer[SHMSZ] = {0};
	if((shmid=shmget(key, SHMSZ, IPC_CREAT|0666))==-1)
	{ 
		perror("shmget");
		exit(EXIT_FAILURE);
	} /* if */

	if((shm=shmat(shmid, NULL, 0))==NULL)
	{ 
		perror("shmat");
		exit(EXIT_FAILURE);
	} /* if */
	printf("memory attached at %X with ID %d\n",(int)(uintptr_t)shm,shmid);
	memo=(struct shared_stuff_st*)shm;

	printf("Select Method:\n1.Method 1\n2.Method 2\n");
	fgets(buffer, BUFSIZ, stdin);
	strncpy(memo->some_text, buffer, SHMSZ);
	memo->written_by_you = 1;	
	printf("Enter Number: ");
	fgets(buffer, BUFSIZ, stdin);
	strncpy(memo->some_text, buffer, SHMSZ);
	
	memo->written_by_you = 2;
		
	while(memo->written_by_you!=3)
		sleep(1);
	printf("Square is %s\n",memo->some_text);


	if(shmdt(shm)==-1)
	{ 
		
		perror("shmdt");
		exit(EXIT_FAILURE);
	} /* if */

	if(shmctl(shmid, IPC_RMID, 0)==-1)
	{ 
		
		perror("shmctl");
		exit(EXIT_FAILURE);
	} /* if */
	exit(EXIT_SUCCESS);
} /* main */

