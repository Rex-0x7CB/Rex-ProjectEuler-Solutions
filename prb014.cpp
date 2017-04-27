#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int i,count,copy=0,i_copy;
	long long n;
	for(i=1;i<1000000;i++)
	{
		n=i;
		count=1;
		while(n!=1)
		{
			if(n%2==0)
				n=n/2;
			else
				n=n*3+1;
			count++;
		}
		if(count>copy)
		{
			copy=count;
			i_copy=i;
		}
	}
	cout<<"\nLargest count registered = "<<copy<<" for i="<<i_copy;
	return 0;
}