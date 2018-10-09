#include	<stdio.h>
#include	<signal.h>
#include	<unistd.h>
void _ () {

	puts("generated SIGALRM");

}

int main ( void ) {

	signal ( SIGALRM , _ ) ;

	alarm(3);

	getchar();
	
	return 0 ;

}
	
