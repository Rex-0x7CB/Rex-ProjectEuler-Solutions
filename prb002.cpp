/*

Even Fibonacci numbers
Problem 2

Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.


*/

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
