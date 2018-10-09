#include  <uma.h>

#include  <signal.h>

void _ () {

		puts("caught SIGPIPE signal");
}

int main(void)
{
		//signal ( SIGPIPE , _ );
		
		int fds[2];

		pipe(fds);  
		
		close(fds[0]); // read end of pipe has been closed
		
		write(fds[1], fds, sizeof(*fds)); // writing from buffer to write end of pipe

		puts("hello world");
		
		return 0;
}
