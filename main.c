#include<stdlib.h>
#include<stdio.h>
#include"prime.h"

void primes_between(u_int64_t a, u_int64_t b);

int
main (int argc, char**argv)
{
	u_int64_t i = 1;
	if (argc > 1)i = atoll(argv[1]);
	if (argc <3)primes_between(1,i);
	else if (argc >=3)primes_between(i,atoll(argv[2]));
	return 0;
}
void primes_between(u_int64_t a, u_int64_t b)
{
	if (a<b) do
	{
		if (prime(a)) printf("%llu\n",a);
	}
	while(a++<b);
}

