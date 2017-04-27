#include<iostream>

using namespace std;
int main()
{
	int n;
	cout<<"\nEnter the number n : ";
	cin>>n;
	cout<<"Difference is : "<<(  ( ((n*(n+1))/2)*((n*(n+1))/2) ) - ( (n*(n+1)*(2*n+1))/6 )  )<<endl;
	return 0;
} 