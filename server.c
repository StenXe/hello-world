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
	int running =1;
	void *shm = NULL;
	struct shared_stuff_st *memo;
	char buffer[SHMSZ] = {0};
	int shmid;
	key_t key;
	key = KEY;
	int num,orignum;
	int first = 0,second = 0;
	if((shmid = shmget(key, SHMSZ,IPC_CREAT|0666))==-1)
	{ 
		perror("shmget");
		exit( EXIT_FAILURE );
	} /* if */

	if((shm=shmat(shmid, NULL, 0))==(void*)-1)
	{ 
		perror("shmat");
		exit(EXIT_FAILURE);
	} /* if */
	printf("memory attached at %X with ID %d\n",(int)(uintptr_t)shm,shmid);
	memo=(struct shared_stuff_st*)shm;

	
	while(memo->written_by_you==0)
	{ 
		sleep(1);
		printf("waiting for client...\n");
	} /* while */
	int opt;	
	if(memo->written_by_you==1)
	{
		opt = atoi(memo->some_text);
		
	}
	int i = 0;
	while(1)
	{	
		if(memo->written_by_you==2)
		{
			
			printf("Input Number: %s",memo->some_text);
			num = atoi(memo->some_text);
			orignum = num;
			second = num % 10;
			num =num / 10;
			first = num % 10;
			
			break;
			
			
			//memo->written_by_you = 0;
			
		
		
		} /* if */
	}
	int square = 0;
	if(opt==1)
	{
		int dev = 0,rnum = 0;
		dev = orignum - 10;
		orignum = (orignum + dev) * 10;
		rnum = dev * dev;
		square = orignum + rnum;

	}
	if(opt==2)
	{
		square = 100*first*first + 2*10*first*second + second*second;	
		printf("square %d\n",square);	
	}
	int a = 1000;
	for(i=0;i<4;i++)
	{
		buffer[i] = (char) (square/a+48);
		square = square%a;
		a = a/10;
		
	}
	strncpy(memo->some_text, buffer, SHMSZ);
	memo->written_by_you = 3;
	
	if(shmdt(shm)==-1)
	{ 
		perror("shmdt");
		exit(EXIT_FAILURE);
	} /* if */

	exit( EXIT_SUCCESS );

} /* main */
