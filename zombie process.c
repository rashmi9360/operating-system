//Zombie Process....

/* Zombie Process is a process whose execution is finished in but it still has
   entry in the process table. In this the parent process is put to sleep for 
   long time while child process is terminated using exit(0). When child process
   is terminated using exit(0) then parent process still reads the status of 
   child process.
	
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	printf("\nName- Rashmi \n");	
	
	int pid = fork();
	
	if(pid > 0)
	{	
		sleep(10);
		printf("\nThis is Parent Process....\n");
		printf("PID: %d\n",getpid());
	}
	else
	{
		printf("\nThis is Child Process....\n");
		printf("PID: %d\n",getpid());
		exit(0);
	}
	
	
	return 0;
}





























