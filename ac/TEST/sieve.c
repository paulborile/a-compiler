#include <stdio.h>

/*
 * 'C' translation of 'A' program named fatt1
 */

int	flag[3000];
int	cnt, i;

main()
{
	i = 0;
	while ( (i < 3000) ) {
		flag[i] = 1;
		i = i + 1;
	}
	i = 2;
	while ( (i < 3000) ) {
		if ( (flag[i] == 1) ) {
			printf("%d\n", i);
			cnt = i;
			while ( (cnt < 3000) ) {
				flag[cnt] = 0;
				cnt = cnt + i;
			}
		} else;
		i = i + 1;
	}
}


