#include	<stdio.h>
#include	<signal.h>
#include	<unistd.h>

void sig_handlr(int sig_num)

{

	printf("the signal is received : %d\n", sig_num);

}

int main(void)
{

	int ret;
	
	int status;

	ret = fork();

	if(ret > 0){

		printf("parent process id: %d\n", getpid());

		signal(SIGUSR1, sig_handlr);

		pause();

//		wait(&status);

		printf("parent terminated\n");

	}else if(ret == 0){

		printf("child process : %d\n", getpid());

		printf("the signal is sent to parent\n");

		kill(getppid(), SIGUSR1);

//		sleep(5);

		printf("child is executed\n");

	}else{

		printf("fork is failed\n");

	}

	return 0;

}
