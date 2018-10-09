#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

static void hdl (int sig, siginfo_t *siginfo, void *context)
{
	
		printf ("**********************%d\n" , *(int*)context) ;

		printf ("Sending PID: %ld, UID: %ld\n",
						(long)siginfo->si_pid, (long)siginfo->si_uid);
}

int main (int argc, char *argv[])
{
		struct sigaction act;

		memset (&act, '\0', sizeof(act));

		act.sa_sigaction = &hdl;

		int x = 22 ;

		act.sa_flags = SA_SIGINFO;

		if (sigaction(SIGINT, &act, &x ) < 0) {
				perror ("sigaction");
				return 1;
		}

		while (1)
				sleep (10);

		return 0;
}
