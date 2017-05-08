/*
Smallest multiple
Problem 5

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

*/

#include<iostream>
#include<stdio.h>
using namespace std;

int next(int k,int m,int max);
int store[50];

int main()
{
	int i,j,n,max=1,t;
	unsigned int temp;
	store[0]=2;
	cout<<"\nEnter a number : ";
	cin>>t;
	for(i=2;i<=t;i++)
	{
		temp=i;
		j=0;
		while(temp>1)
		{
			for(;j<max;j++)
			{
				if(i%store[j]==0)
					temp=temp/store[j];
			}
			if(j==max && temp>1)
			{
				n=next(temp,store[max-1],max);
				store[max]=n;
				max++;
			}
		}
	}
	temp=1;
	for(j=0;j<max;j++)
	{
		temp=temp*store[j];
	}
	cout<<"\nSmallest (+)ve no evenly divisible by all of the nos. from 1 to "<<t<<" : "<<temp<<endl;
	return 0;
}

int next(int k,int m,int max)
{
	int i,j;
	for(i=2;i<=k;i++)
	{
		for(j=0;j<max;j++)
		{
			if(i%store[j]==0)
				break;
		}
		if(k%i==0)
			break;
	}
	return i;
}
