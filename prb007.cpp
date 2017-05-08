/*
10001st prime
Problem 7

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

*/

#include<iostream>

using namespace std;

int isprime(unsigned int);

int main()
{
	unsigned int count=0,i;
	for(i=2;count!=10001;i++)
	{
		if(isprime(i))
			count++;
	}
	cout<<"\n10001st prime number : "<<i-1;
	return 0;
}

int isprime(unsigned int i)
{
	unsigned int j,flag;
	for(j=2;j<=i/2;j++)
	{
		flag=1;
		if(i%j==0)
		{
			flag=0;
			break;
		}
	}
	return flag;
}
