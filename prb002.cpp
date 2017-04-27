#include<iostream>
using namespace std;

int main()
{
	int a=1,b=1,c=1,i=0;
	for(;c<4000000;)
	{
		//cout<<c<<"\t";
		b=a;
		a=c;
		c=a+b;
		if(c%2==0)
			i=i+c;
	}
	cout<<"\nTotal : "<<i<<endl;
	return 0;
}