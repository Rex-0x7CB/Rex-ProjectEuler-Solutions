/*
Longest Collatz sequence
Problem 14

The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

*/

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
