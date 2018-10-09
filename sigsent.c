#include    <uma.h>
#include    <signal.h>

void hand ( void ) {

		printf("killed bt ill signal\n");

}
int main (void) {

		pid_t t = fork ( );

		int status ;

		if ( t )  {

				printf("iam parent %d \n",getpid ( ));

				signal ( SIGUSR1 , hand ) ;

				pause ( ) ;

				t = wait ( &status );

		}

		if ( !t ) {

				printf("iam chiald %d \n",getpid ( ));

				sleep( 2 );

				printf("chiald sendi sig \n");

				kill ( getppid () , SIGUSR1 ) ;

				sleep ( 2 ) ;
		}

}
