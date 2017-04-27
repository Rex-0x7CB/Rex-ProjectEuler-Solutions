#include<iostream>
#include<math.h>
using namespace std;

int isint(float);

int main()
{
	int a,i,flag,c,product;
	float b;
	for(i=1;i<=500;i++)
	{
		b=(((500-(float)i)*1000)/(1000-i));
		flag=isint(b);
		if(flag==1)
		{
			cout<<"\na="<<i<<" b="<<(int)b;
			c=1000-(i+b);
			cout<<" c="<<c;
			product=i*b*c;
			cout<<"\nProduct = "<<product;
		}
	}
	return 0;
}

int isint(float b)
{
	int p;
	p=(int)b;
	b=b-p;
	if(b==0)
		return 1;
	return 0;
}