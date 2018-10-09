      /* int getrlimit(int resource, struct rlimit *rlim);
       int setrlimit(int resource, const struct rlimit *rlim);

       int prlimit(pid_t pid, int resource, const struct rlimit *new_limit,
                   struct rlimit *old_limit);

   Feature Test Macro Requirements for glibc (see feature_test_macros(7)):

       prlimit(): _GNU_SOURCE && _FILE_OFFSET_BITS == 64

DESCRIPTION
       The  getrlimit() and setrlimit() system calls get and set resource lim‐
       its respectively.  Each resource has an associated soft and hard limit,
       as defined by the rlimit structure:*/

          // struct rlimit {
            //   rlim_t rlim_cur;  /* Soft limit */
              // rlim_t rlim_max;  /* Hard limit (ceiling for rlim_cur) */
          // };*/

#include	<stdio.h>
#include	<stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

int main ( void ) 
{
	struct rlimit kill , two ;

	kill . rlim_cur = 12 ;

	kill . rlim_max = 13 ;	

	if ( setrlimit( RLIMIT_CPU  ,  &kill) ) {

		perror("status setlimit");

		exit ( EXIT_FAILURE ) ;

	}
    if ( getrlimit( RLIMIT_CPU  ,  &two) ) {

        perror("status setlimit");

        exit ( EXIT_FAILURE ) ;

    }

	printf("%d\n" , two . rlim_max);
	printf("%d\n" , two . rlim_cur);

	getchar();

}

