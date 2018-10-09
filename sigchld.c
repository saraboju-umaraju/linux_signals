#include    <uma.h>
#include    <signal.h>

void _hand ( int signo ) {

		printf("just caught SIGCHLD signal \n"); /* my handler does nothing but prining;) */

}
int main (void) {


		pid_t process_id ;

		process_id = fork ( ) ;

		signal ( SIGCHLD , _hand ) ;  /* asking kernel to register my own custom handler */

		if ( ! process_id ) 

				return 0 ;          /* if its a child process just return */

		else 
				wait ( NULL );		/* parent is waiting to receive status of child */

		return  0 ;

}


