#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char input[450],res[450];
	int a,inlen,i,temp,k,carry;
	for(i=0;i<450;i++)
	{
		input[i]=res[i]=0;
	}
	input[0]='1';
	for(a=1;a<=100;a++)
	{
		k=0;
		carry=0;
		inlen=strlen(input);
		for(i=0;i<inlen;i++)
		{
			temp=(int)input[inlen-i-1];
			temp=temp-48;
			temp=temp*a + carry;
			res[k++]=(char)( (temp%10) + 48 );
			carry=temp/10;
		}
	
		while(carry>0)
		{
			res[k++]=(char)( carry%10 + 48 );
			carry=carry/10;
		}
		res[k]=0;
		
		inlen=strlen(res);
		for(i=0;i<inlen/2;i++)
		{
			temp=(int)res[i];
			res[i]=res[inlen-i-1];
			res[inlen-i-1]=(char)temp;
		}
		strcpy(input,res);
	}
	inlen=strlen(res);
	for(i=0,a=0;i<inlen;i++)
	{
		temp=(int)res[i]-48;
		a=a+temp;
	}
	cout<<"\nTotal Sum : "<<a;
	return 0;
}