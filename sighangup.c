#include    <uma.h>
#include    <signal.h>

void _hand ( int signo ) {

		FILE *fp = fopen ( "SIG_HUP.txt" , "a+" ); /* as bash dies we cant see output so redirect it */

		fprintf( fp, "just caught hangup siganl from parent ( bash ) \n"); /* my handler does nothing but prining;) */

}
int main (void) {

		printf("pass SIGKILL to %d \n",getppid());

		signal ( SIGHUP , _hand ) ;  /* asking kernel to register my own custom handler */

	//	kill ( getppid() , SIGKILL ); /* killing the parent of current process */

		pause ( );

		return  0 ;

}


