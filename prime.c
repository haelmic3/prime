#include"prime.h"
int prime(Type n)
{
	switch(n)
	{
	case 0:
	case 1:
	case 4:
	case 6:
		return 0;
	case 2:
	case 3:
	case 5:
	case 7:
		return 1;
	}
	if(n%2==0)return 0;
	if(n%3==0)return 0;
	{
		Type i = 1,p;
		for(;;i++)
		{
			p = 6*i;
			if(n<(p-1)*(p-1))return 1;
			if(n%(p-1)==0)return 0;
			if(n%(p+1)==0)return 0;
		}
	}
}
