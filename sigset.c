#include    <uma.h>
#include    <stdio.h>
#include    <signal.h>

void _ ( int num  , siginfo_t *ptr  )  {

		printf("     IVE GOT %d \n",num);
		
		printf(" SIGNAL NUMBER IS %d \n",ptr -> si_signo);
		
		printf(" ERROR ( IF ANY ) NUMBER IS %d \n",ptr -> si_errno);
		
		printf(" SIGNAL CODE IS %d \n",ptr -> si_code);
		
//		printf(" SIGNAL TRAP NUM  IS %d \n",ptr -> si_trapno);
		
		printf(" SENDING PROCESS ID IS %d \n",ptr -> si_pid);
		
		printf(" REAL USER IS %d \n",ptr -> si_uid);
		
		printf(" EXIT VALUE OR SIGNAL %d \n",ptr -> si_status);

		getchar();

}

int main (void) {

	struct sigaction instance ;
	
	instance . sa_sigaction = &_ ;

	instance.sa_flags = SA_SIGINFO | SA_NODEFER | SA_RESETHAND ;

	//sigaddset ( &instance.sa_mask , SIGTSTP ) ;
	
	sigfillset ( &instance.sa_mask ) ;
	
	//sigaddset ( &instance.sa_mask , SIGINT ) ;
	
	//sigaddset ( &instance.sa_flags , SIGQUIT ) ;

	printf("%d\n",getpid());

	sigaction ( SIGINT, &instance , NULL ) ;

	getchar();

}


