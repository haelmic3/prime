#include<stdlib.h>
#include<stdio.h>
#include"prime.h"

void primes_between(Type a, Type b);

int
main (int argc, char**argv)
{
	Type i = 1;
	if (argc > 1)i = atoll(argv[1]);
	if (argc <3)primes_between(1,i);
	else if (argc >=3)primes_between(i,atoll(argv[2]));
	return 0;
}
void primes_between(Type a, Type b)
{
	if (a<b) do
	{
		if (prime(a)) printf("%llu\n",a);
	}
	while(a++<b);
}

