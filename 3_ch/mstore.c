#include "stdio.h"

long	mult2(long x, long y)
{
	long r;
	r = x * y;
	return r;
}

void	mulstore(long x, long y, long *dest)
{
	long 	t;

	t = mult2(x, y);
	*dest	= t;
}

int 	main(void)
{
	long 	t;

	mulstore(4, 5, &t);

	printf("t: %ld\n", t);

	return 0;
}
