#include <stdlib.h>

void	translate(long long n, long long magnitude, long long n_orig);
void	lookup(long long n);
/*
int		main(int argc, char **argv)
{
	if (argc != 1)
	{
		printf("Input number!\n");
		return (1);
	}
	long long n = 1000000;
	translate(n, 1, n);			// Input test number
//	printf("\n");				// CAREFUL: atoi causes problems with numbers higher than 2 billion
}
*/

// Not handling 0 yet
// Logic bug with large numbers like with many zeros like 1000000 and above
void	translate(long long n, long long magnitude, long long n_orig/*, long long z*/)
{
	// 0
	if (n_orig == 0)
		lookup(0);

	// Recursion base case
	if (n == 0)
		return ;

	// RECURSE
	translate(n / 1000, magnitude * 1000, n_orig);

	// 100 - 999
	if (n % 1000 >= 100)
	{
		lookup((n % 1000) / 100);			// One's place
		lookup(100);						// Then literal hundred
	}

	// 1 - 19
	if (n % 100 >= 1 && n % 100 <= 19)
	{
		lookup(n % 100);					// 1 - 19
	}

	// 20 - 99
	else if (n % 100 >= 20 && n % 100 <= 99)
	{
		lookup(n % 100 - n % 10);			// Ten's place
		lookup(n % 10);						// Then one's place
	}

	// thousand, million, billion, etc.
	if (magnitude > 1 && (n_orig / magnitude) % 1000 != 0)
	{
		lookup(magnitude);					// Every 3rd order of magnitude
	}
}

//just for testing
void	lookup(long long n)
{
//	printf("%lld ", n);
}
