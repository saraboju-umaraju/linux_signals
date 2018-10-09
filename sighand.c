#include    <uma.h>
#include    <signal.h>
__sighandler_t _isr () {

		printf("babes caught\n");

//		raise(11);
}

int main (void) {

		signal( 2, (__sighandler_t)_isr);

		printf("have a dabba day\n");

		//while(1);

		//pause ();

		getchar();

		printf("cont \n");

getchar();

}
