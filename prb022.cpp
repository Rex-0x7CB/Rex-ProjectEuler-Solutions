#include<iostream>
#include<string>
#include<fstream>
#include<cstdio>
#include<string.h>

using namespace std;

void sort(char name[6000][15],int count);
void calc(char name[6000][15],int count);

int main()
{
	char name[6000][15],temp;
	int i=0,j,k,index=0,flag=0,highest=0,count=0;
	ifstream f1;
	f1.open("prb022_names.txt");
	if(!f1)
		cout<<"\nFile opening error";
	while(1)
	{
		//cout<<"\nInitiating loop....";
		f1.get(temp);
		if(f1.eof())
			break;
		if(temp==',')
			continue;
		else if((temp<='Z' && temp>='A') && flag==1)
			name[index][i++]=temp;
		else if(temp=='\"' && flag==0)
			flag=1;
		else if(temp=='\"' && flag==1)
		{
			flag=0;
			name[index][i]='\0';
			i=0;
			index++;
		}		
	}
	cout<<"\nTotal records found : "<<index;
	f1.close();
	sort(name,index);
	calc(name,index);
}

void sort(char name[6000][15],int count)
{
	int min,index,i,j;
	char temp[15];
	for(i=0;i<count-1;i++)
	{
		min=100;
		for(j=i+1;j<count;j++)
		{
			if(strcmp(name[i],name[j])>0)
			{
				strcpy(temp,name[i]);
				strcpy(name[i],name[j]);
				strcpy(name[j],temp);
			}
		}
	}
}

void calc(char name[6000][15],int count)
{
	int i,sum,l,j,rem,k,carry,endf,endt;
	char feed[20],total[100];
	for(i=0;i<99;i++)
	{
		total[i]=0;
	}
	for(i=0;i<20;i++)
	{
		feed[i]=0;
	}
	for(i=0;i<count;i++)
	{
		sum=0;
		l=strlen(name[i]);
		for(j=0;j<l;j++)
		{
			sum=sum + name[i][j] -64;
		}
		cout<<"\ni= "<<i<<" name[i]="<<name[i];
		cout<<"\nSum before multiplication : "<<sum;
		sum=sum*(i+1);
		cout<<"\nSum after multiplication : "<<sum;
		k=0;
		while(sum>0)
		{
			rem=sum%10;
			rem=rem+48;
			feed[k++]=rem;
			sum=sum/10;
		}
		feed[k]=0;
		cout<<endl<<feed;
		if(strlen(total)>strlen(feed))
			l=strlen(total);
		else
			l=strlen(feed);
		endf=1;
		endt=1;
		carry=0;
		for(j=0;j<l || carry!=0;j++)
		{
			if(total[j]==0)
				endt=0;
			if(feed[j]==0)
				endf=0;
			
			carry = carry + (total[j]-48)*endt + (feed[j]-48)*endf;
			total[j] = (carry%10)+48;
			carry=carry/10;
		}
		total[j]=0;
		cout<<"\nTotal="<<total;
	}
	l=strlen(total);
	for(i=0;i<l/2;i++)
	{
		feed[0]=total[i];
		total[i]=total[l-i-1];
		total[l-i-1]=feed[0];
	}
	cout<<"\nTotal : "<<total;
}