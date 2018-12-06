#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#define N 5



int main(int argc, char *argv[])
{
	
	for(int i = 0; i < N; i++){
		switch (fork()){
			case -1 : // ERREUR
				fprintf(stderr, "Erreur de fork\n");
				exit(-1);
			case 0 : // Creation des fils
				printf("je suis %d, mon pid %d, mon pere Pid %d\n", i, getpid(), getppid());
				exit(-1);
	/****************************************************************************************/
			default :
			/* comportement du pere */
				while (wait(NULL)!=-1);
				printf("Done\n");
		}
	}	
    return 0;
}



