/*
 *	s i g n a l . c
 *
 * Trap interupt SIGINT
 * and remove files if neccessary
 *
*/

#include <stdio.h>
#include <signal.h>

extern	char	crossfile[],asfile[],ofile[];
extern	int	l_list,s_flag;

rubout()
{
	signal(SIGINT,rubout);
	if (l_list) {
		if ( access(crossfile,0) == 0 ) {
			unlink(crossfile);
		}
	}
	if (s_flag) {
		if (access(asfile,0) == 0 ) {
			unlink(asfile);
		}
	}
	if (access(ofile,0) == 0 ) {
		unlink(ofile);
	}
	exit(1);
}
