#include    <uma.h>
#include    <signal.h>
int main (void) {

		signal ( 2 , SIG_IGN ) ;
		
		raise (SIGTRAP);

		getchar();

}
