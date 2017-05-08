/*
Lattice paths
Problem 15

Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down,
there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?

*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	long long a[20][20];
	int i,j;
	for(i=0;i<20;i++)
	{
		a[i][0]=a[0][i]=i+2;
	}

	for(i=1;i<20;i++)
	{
		for(j=1;j<20;j++)
		{
			a[i][j] = a[i-1][j] + a[i][j-1];
		}
	}
	for(i=0;i<20;i++)
	{
		cout<<"\n"<<i+1<<'x'<<i+1<<" -> "<<a[i][i];
	}
}
