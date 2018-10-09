#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/mman.h>
#include	<fcntl.h>
void _hand ( int signo ) {

		printf("just caught SIGBUS siganl \n");

		exit ( 0 ) ;                                  			  /* otherwise loops infinitely here */ 

}
int main()  
{

		signal (SIGBUS , _hand ) ;  								/* registering custom handler with kernel */

		int fd = open("./file.txt", O_RDWR);

		perror("");

		//ftruncate(fd , 12 ) ;

		int *m = 0;
		
//		printf("address= %08x\n", m);					
		m = mmap(0, 4, PROT_WRITE, MAP_PRIVATE, fd, 0);  /* mapping 4len bytes of data with flags to tmpfile() */ 
		
		//m = mmap(0, 4, PROT_WRITE,MAP_SHARED, fd, 0);  /* mapping 4len bytes of data with flags to tmpfile() */ 
		perror("");
		
//		printf("address= %08x\n", m);
		
//		printf("pid= %d\n", getpid());
		
		getchar();

		*m = 0;   										/* this instruction causes bus error */

	
		
		return 0;
}

