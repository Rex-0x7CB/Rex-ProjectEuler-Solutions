/*
Largest palindrome product
Problem 4

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

*/

#include<iostream>
using namespace std;
int main()
{
	int a,b,i,j,k,flag=1,max=0;
	for(a=999;a>99;a--)
	{
		for(b=a;b>99;b--)
		{
			i=a*b;
			k=0;
			while(i>0)
			{
				j=i%10;
				i=i/10;
				k=k*10 + j;
			}
			if(k==a*b)
			{
				if(k>max)
					max=k;
			}
		}
	}
	cout<<"\nLargest 3digit * 3digit palindrome is : "<<max<<endl;
	return 0;
}
