#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int a,i,j,temp,count=0,counter,flag,flag2;
	char s[50],number[10][7]={"One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine "};
	for(j=1;j<=1000;j++)
	{
		counter=0;
		for(i=0;i<50;i++)
			s[i]=0;
		a=j;
		if(a>100)
			flag=1;
		else 
			flag=0;
		temp=a/1000;
		if(temp>0)
		{
			strcat(s,number[temp-1]);
			strcat(s,"Thousand ");
		}
		a=a%1000;
	
		temp=a/100;
		if(temp>0)
		{
			strcat(s,number[temp-1]);
			strcat(s,"Hundred ");
		}
		a=a%100;
		
		if(a<20 && a>9)
		{
			if(strlen(s)!=0)
				strcat(s,"And ");
			switch(a)
			{
				case 10:
					strcat(s,"Ten ");
					break;
				case 11:
					strcat(s,"Eleven ");
					break;
				case 12:
					strcat(s,"Twelve ");
					break;
				case 13:
					strcat(s,"Thirteen ");
					break;
				case 14:
					strcat(s,"Fourteen ");
					break;
				case 15:	
					strcat(s,"Fifteen ");
					break;
				case 16:
					strcat(s,"Sixteen ");
					break;
				case 17:
					strcat(s,"Seventeen ");
					break;
				case 18:
					strcat(s,"Eighteen ");
					break;
				case 19:
					strcat(s,"Nineteen ");
					break;
			}
		}	
		else
		{
			temp=a/10;
			if(temp>0)
			{
				if(strlen(s)!=0)
				{
					strcat(s,"And ");
					flag=0;
				}
				switch(temp)
				{
					case 2:
						strcat(s,"Twenty ");
						break;
					case 3:
						strcat(s,"Thirty ");
						break;
					case 4:
						strcat(s,"Forty ");
						break;
					case 5:
						strcat(s,"Fifty ");
						break;	
					case 6:
						strcat(s,"Sixty ");
						break;
					case 7:
						strcat(s,"Seventy ");
						break;
					case 8:
						strcat(s,"Eighty ");
						break;
					case 9:
						strcat(s,"Ninety ");
						break;
				}
			}
			a=a%10;
			if(a>0)
			{
				if(strlen(s)!=0 && flag)
					strcat(s,"And ");
				strcat(s,number[a-1]);
			}
		}
		for(i=0;i<strlen(s);i++)
		{
			if(isalpha(s[i]))
				counter++;
		}
		cout<<"\nFinal Result : "<<s<<"\tcounter="<<counter;
		count=count+counter;
	}
	cout<<"\nTotal length : "<<count;
	return 0;
}