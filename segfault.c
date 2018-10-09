#include    <uma.h>
#include    <signal.h>

void _hand ( int signo ) {

		printf("just caught segmentation fault \n"); /* my handler does nothing but prining;) */

		//exit ( 0 ) ;  /* otherwise loops infinite times */

}
int main (void) {

		signal ( SIGSEGV , _hand ) ;  /* asking kernel to register my own custom handler */

		printf("%s\n", 1 ); /* will generate a sementation fault */

		return  0 ;

}


