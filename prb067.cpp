#include<iostream>
#include<cstdio>
#include<fstream>
#include<string.h>

using namespace std;
int main()
{
	int i,j,parent=0,child=0,p[5500]={3,7, 4,2, 4, 6,8, 5, 9, 3};
	int new_start,prev_start,prev_child;
	int num,k=0;
	char b[5],c;
	
	ifstream f1;
	
	f1.open("prb067_triangle.txt");
	if(!f1)
	{
		cout<<"\nCannot Open File";
		return 1;
	}
	
	while(1)
	{
		f1>>b;
		//cout<<"b="<<b<<"\t";
		//getchar();
		if(f1.eof())
		{
			break;
		}
		else
		{
			num=0;
			for(i=0;i<strlen(b);i++)
			{
				c=b[i];
				c=c-48;
				num=num*10+c;
			}
			//cout<<"num="<<num<<endl;
			p[k++]=num;
		}
	}
	
	for(i=99;i>0;i--)
	{
		child=((i*(i+1))/2);
		parent=(((i-1)*(i))/2);
		for(j=1;j<=i;j++)
		{
			//cout<<"child= "<<child<<"p[child]= "<<p[child]<<"  "<<p[child+1];
			if(p[child]>p[child+1])
				p[parent]=p[parent]+p[child];
			else
				p[parent]=p[parent]+p[child+1];
			
			parent++;
			child++;
			//getchar();
		}
	}
	
	cout<<"\n\nSum = "<<p[0]<<endl;
	
	child=0;

	for(i=1;i<=99;i++)
	{
		new_start= (i*(i+1))/2;
		prev_start= ((i-1)*i)/2;
		prev_child=child;
		child= new_start + (child-prev_start);
		if(p[child]>p[child+1])
		{
			cout<<p[prev_child]-p[child]<<"->";
		}
		else if(p[child+1]>p[child])
		{
			cout<<p[prev_child]-p[child+1]<<"->";
			child=child+1;
		}
	}
	cout<<p[child]<<endl;
	
	return 0;
}
