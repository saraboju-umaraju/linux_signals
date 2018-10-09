#include    <uma.h>
#include    <signal.h>

void _hand ( int signo ) {

		printf("just caught floating point exception \n"); /* my handler does nothing but prining;) */

		exit ( 0 ) ;  /* otherwise loops infinite times */

		/* because while handling this handler the context of main will be pushed on to the stack

		   the eip value which was pushed is pointing to the instruction that has raised the exception 

		   itself this explains whY its an infinite loop */

}
int main (void) {

		int dead ; 

		int variable1 = 0 ;

		int variable2 = 0 ;

		signal ( SIGFPE , _hand ) ;  /* asking kernel to register my own custom handler */

		dead = variable1 / variable2 ; /* will generate a floating point exception */

		return  0 ;

}


