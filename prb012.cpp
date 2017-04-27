#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	long long t,i,count=0,n,great=0;
	for(n=1;count<500;n++)
	{
		t=((n*(n+1))/2);
		count=0;
		i=1;
		cout<<"\nt="<<t<<" :";
		while(i<=(t/i))
		{
			//cout<<"Entered while";
			if(t%i==0)
			{
				count=count+2;
				cout<<" "<<i;
			}
			i++;
			//getchar();
		}
		if(great<count)
			great=count;
		cout<<"\ncount : "<<count;
		//getchar();
	}
	cout<<"\nGreatest value : "<<great;
	return 0;
}
		