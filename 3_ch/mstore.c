

long	mult2(long, long);

void	multsore(long x, long y, long *dest)
{
	long 	t;

	t = mult2(x, y);
	*dest	= t;
}
