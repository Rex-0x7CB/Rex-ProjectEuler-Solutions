/*
Counting Sundays
Problem 19

You are given the following information, but you may prefer to do some research for yourself.

    1 Jan 1900 was a Monday.
    Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
    A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

*/

#include<iostream>
#include<stdio.h>

using namespace std;

int isleap(int);

int main()
{
	int year,sum=0,i,j,leapchk,strtday=0;
	for(year=1900;year<=2000;year++)
	{
		cout<<"\n\n01-01-"<<year<<" : "<<strtday;
		if(strtday==6)
			sum++;
		strtday=(strtday+31)%7;
		cout<<"\n01-02-"<<year<<" : "<<strtday;
		if(strtday==6)
			sum++;
		strtday=(strtday+28+isleap(year))%7;
		cout<<"\n01-03-"<<year<<" : "<<strtday;
		if(strtday==6)
			sum++;
		strtday=(strtday+31)%7;
		cout<<"\n01-04-"<<year<<" : "<<strtday;
		if(strtday==6)
			sum++;
		strtday=(strtday+30)%7;
		cout<<"\n01-05-"<<year<<" : "<<strtday;
		if(strtday==6)
			sum++;
		strtday=(strtday+31)%7;
		cout<<"\n01-06-"<<year<<" : "<<strtday;
		if(strtday==6)
			sum++;
		strtday=(strtday+30)%7;
		cout<<"\n01-07-"<<year<<" : "<<strtday;
		if(strtday==6)
			sum++;
		strtday=(strtday+31)%7;
		cout<<"\n01-08-"<<year<<" : "<<strtday;
		if(strtday==6)
			sum++;
		strtday=(strtday+31)%7;
		cout<<"\n01-09-"<<year<<" : "<<strtday;
		if(strtday==6)
			sum++;
		strtday=(strtday+30)%7;
		cout<<"\n01-10-"<<year<<" : "<<strtday;
		if(strtday==6)
			sum++;
		strtday=(strtday+31)%7;
		cout<<"\n01-11-"<<year<<" : "<<strtday;
		if(strtday==6)
			sum++;
		strtday=(strtday+30)%7;
		cout<<"\n01-12-"<<year<<" : "<<strtday;
		if(strtday==6)
			sum++;
		strtday=(strtday+31)%7;
		cout<<"\nSum="<<sum;
		getchar();
	}
	cout<<"\nTotal sundays in 19th centuary : "<<sum-2<<endl;
	return 1;
}

int isleap(int year)
{
	if(year%100==0)
	{
		if(year%400==0)
			return 1;
		else
			return 0;
	}
	else if(year%4==0)
		return 1;
	else
		return 0;
}
