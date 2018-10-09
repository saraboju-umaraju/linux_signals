#include    <uma.h>
#include    <signal.h>
#include    <assert.h>

void _hand ( int signo ) {

		printf("just caught SIGQUIT signal \n"); /* my handler does nothing but prining;) */

}
int main (void) {

		char *killer = "IAM GONNA CRASH PROGRAM" ;

		signal ( SIGQUIT , _hand ) ;  /* asking kernel to register my own custom handler */

		printf ( "enter Ctrl + \ to generate SIGQUIT\n" ); 

		pause ( ) ;

		return  0 ;

}


