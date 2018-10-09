#include	<stdio.h>
#include	<signal.h>
void _hand() {
	puts("in action");
	getchar();
}
int main ( void ) 
{
	signal ( SIGSEGV , _hand ) ;
	asm ( "int $0x16");
	getchar();
}
