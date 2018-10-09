#include    <uma.h>
#include    <signal.h>
#include    <assert.h>

void _hand ( int signo ) {

		printf("just caught SIGABRT signal \n"); /* my handler does nothing but prining;) */

		exit ( 0 ) ;  /* otherwise loops infinite times */

		/* because while handling this handler the context of main will be pushed on to the stack

		   the eip value which was pushed is pointing to the instruction that has raised the exception 

		   itself this explains whY its an infinite loop */

}
int main (void) {

		char *killer = "IAM GONNA CRASH PROGRAM" ;

		signal ( SIGABRT , _hand ) ;  /* asking kernel to register my own custom handler */

		assert ( ! printf ( "about to generate a SIGABRT \n" ) ) ;

		//free ( killer ) ;
		
		return  0 ;

}


