#include    <uma.h>
#include    <stdio.h>
#include    <signal.h>

void
_(int num, siginfo_t * ptr)
{

    sigset_t set;

    sigfillset(&set);

    sigprocmask(SIG_UNBLOCK, &set, NULL);

    printf("     ive got %d \n", num);

    printf(" signal number is %d \n", ptr->si_signo);

    printf(" error ( if any ) number is %d \n", ptr->si_errno);

    printf(" signal code is %d \n", ptr->si_code);

//      printf(" SIGNAL TRAP NUM  IS %d \n",ptr -> si_trapno);

    printf(" sending process id is %d \n", ptr->si_pid);

    printf(" real user is %d \n", ptr->si_uid);

    printf(" exit value or signal %d \n", ptr->si_status);

    getchar();

}

int
main(void)
{

    struct sigaction instance;

    instance.sa_sigaction = &_;

    instance.sa_flags = SA_SIGINFO | SA_NODEFER | SA_RESETHAND;

    sigfillset(&instance.sa_mask);  //fill all

//  sigprocmask  ( SIG_UNBLOCK , &set , NULL ) ;

    printf("%d\n", getpid());

    sigaction(SIGINT, &instance, NULL);

    getchar();

}
