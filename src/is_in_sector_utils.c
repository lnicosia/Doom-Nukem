#include "env.h"

int     in_range(double nb, double val1, double val2)
{
	double min;
	double max;

	min = (val1 <= val2) ? val1 : val2;
	max = (val1 > val2) ? val1 : val2;
	if (nb > min && nb <= max)
		return (1);
	return (0);
}

/*
** USED BY OLD INSIDE TMP SECT
**
int		in_range_not_included(double nb, double val1, double val2)
{
	double min;
	double max;

	min = (val1 <= val2) ? val1 : val2;
	max = (val1 > val2) ? val1 : val2;
	if (nb > min && nb < max)
		return (1);
	return (0);	
}
*/

int     diff_value(int nb1, int nb2, int a, int b)
{
	if ((nb1 == a && nb2 == b) || (nb1 == b && nb2 == a))
		return (0);
	return (1);
}

int     diff_sign(double nb1, double nb2)
{
	if ((nb1 > 0 && nb2 > 0) || (nb1 < 0 && nb2 < 0) || nb1 == 0)
		return (0);
	return (1);
}
