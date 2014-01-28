#include <stdio.h>

/*
 * 'C' translation of 'A' program named pippo
 */

int	a, b;

main()
{
	a = 1;
	b = 7;
	while ( (b > 1) ) {
		a = a * b + 3;
		b = b - 1 * a;
	}
}


