//Orphan Process....

/*Orphan Process is a process in which Parent process terminates before the
  child process. Child process is put to sleep for long time using sleep 
  function. This will put child process to sleep and parent process is 
  terminated making the child process orphan.
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	
		
	int pid = fork();
	
	if(pid > 0)
	{
		printf("\nThis is Parent Process....\n");
		printf("PID: %d\n",getpid());
	}
	else
	{
		sleep(10);
		printf("\nThis is Child Process....\n");
		printf("PID: %d\n",getpid());
	}
	
	
	return 0;
}




































