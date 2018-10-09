#include    <uma.h>
#include    <signal.h>

void function( void ) {
	
		int a[4] = {1};

		a[5] = a[5] - 2;    /* some how it's a illegal instruction */

}

void _hand ( int signo ) {

		printf("just caught illegal instruction \n"); /* my handler does nothing but prining;) */

		exit ( 0 ) ;  /* otherwise loops infinite times */

		/* because while handling this handler the context of main will be pushed on to the stack

		   the eip value which was pushed is pointing to the instruction that has raised the exception 

		   itself this explains whY its an infinite loop */

}

int main (void) {

		signal ( SIGILL , _hand ) ;  /* asking kernel to register my own custom handler */

		function();            		/* to create a havoc */

		return  0 ;

}


