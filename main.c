#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#define PP printf
#define FP() fflush(stdout)
#define PE(X,...) ;//fprintf(stderr,X,##__VA_ARGS__)
int little(unsigned p)
{
	unsigned x = p,a = 1;
	while(--x)a=(a<<1)%p;
	return a;
}
uint64_t sqrsea(uint64_t p)
{
	uint64_t a = p;
	uint8_t i=0,j; // 64bits < 255
	while(a>>=1)i++;
	a = p >> (i/2);
	j = i - (i/2);
	while(p/a>a)
	{
		// shouldn't ever happen
		a<<=1;
		++j;
	}
	while(p/a<a)
	{
		// should only happen once
		a>>=1;
		--j;
	}
	while(--j)
	{
		// j times where j is < 32
		uint64_t t = a+(1<<j);
		if(p/t>t)a=t;
	}
	PE("\n");

	return a;
}
int prime(uint64_t p)
{	if(p<3)return p?p-1:0;
	if(p%2==0)return 0;
	if(p%3==0)return 0;
{
	uint64_t
		a = sqrsea(p)&~3,
		b = 4,
	_;
	PE("%lu(%lu(%lu))",p,a,a/4);

	if(a>b)do
	{
		if(p%(a+1) == 0){PE(":%ld^\n",a);return 0;}
		if(p%(a+3) == 0){PE(":%ld^\n",a);return 0;}
		if(p%(b+1) == 0){PE(":%ldv\n",b);return 0;}
		if(p%(b+3) == 0){PE(":%ldv\n",b);return 0;}
		a-=4;
		b+=4;
	}
	while(a);
	PE("\n");
	return 1;
}
}
void CB(){while(getchar()!='\n');}
int main()
{
	uint64_t a = ~0;
	PP("Starting Program\n");
	while(--a>1)//(++a>1)
	{	if(prime(a))
			PP("\n%lu",a);
		else
			PP("|");
		FP();
	}
	/*{
		unsigned
			l = little(a),
			p = l == 1 && prime(a)|| a == 2,
		_;
		if(p)PP("\n%8d",a);else PP("|");
		//PP("f(%4d) -> %4d -> %c%c%c\n",a,little(a),p?'y':' ',p?'e':'n',p?'s':'o');
		//if(a%16==15){PP("Press ENTER to continue.\n");CB();}
	}*/
	return 0;
}
