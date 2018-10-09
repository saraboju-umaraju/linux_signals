#include    <uma.h>
#include    <signal.h>
#include    <assert.h>

void _hand ( int signo ) {

		printf("just caught SIGQUIT signal \n"); /* my handler does nothing but prining;) */

}
int main (void) {

		char *killer = "IAM GONNA CRASH PROGRAM" ;

		signal ( SIGUSR1 , _hand ) ;  /* asking kernel to register my own custom handler */

		if(!fork()){

		sleep(3);

		printf("parent : %d\n", getppid());

//		getchar();

		sleep ( 10 ) ;

		kill(getppid(), SIGUSR1);

		}

		return  0 ;

}


