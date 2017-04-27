#include<iostream>
using namespace std;

unsigned int next(long long,unsigned int,unsigned int);

unsigned int store[500];

int main()
{
	long long k;
	unsigned int max=1;
	unsigned int j,min=0,i;
	store[0]=2;
	cout<<"\nEnter a number : ";
	cin>>k;
	cout<<"\nPrime factors of the entered number are : \n";
	while(k>1)
	{
		for(i=min;i<max;i++)
		{
			if(k%store[i]==0)
			{
				k=k/store[i];
				break;
			}
		}
		if(i==max)
		{
			j=next(k,store[max-1],max);
			store[max]=j;
			min=max;
			max++;
			
		}
	}
	for(i=0;i<max;i++)
		cout<<"\n"<<i<<" "<<store[i];
	return 0;
}

unsigned int next(long long k,unsigned int m,unsigned int max)
{
	long long i,j;
	int flag=0;
	for(i=m+1;i<=k;i++)
	{
		flag=0;
		for(j=0;j<max;j++)
		{
			if(i%store[j]==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0 && k%i==0)
			break;
	}
	return i;
}