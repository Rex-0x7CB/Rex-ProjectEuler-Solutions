/*
Summation of primes
Problem 10

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

*/

#include<iostream>
#include<stdio.h>
using namespace std;

int store[200000];

int isprime(int);

int main()
{
	int i,j,flag,max=1;
	store[0]=2;
	long long count=0;
	for(i=2;i<=2000000;i++)
	{
		flag=isprime(i);
		if(flag)
		{
			cout<<endl<<i;
			store[max]=i;
			max++;
			count=count+i;
		}
	}
	cout<<"\nTotal sum : "<<count;
	return 0;
}

int isprime(int i)
{
	unsigned int j;
	for(j=0;store[j]<=i/2;j++)
	{
		if(i%store[j]==0)
		{
			return 0;
		}
	}
	return 1;
}
