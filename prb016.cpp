#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void multiply(char result[50],char input[45],int a);
int main()
{
	unsigned int i,j,count=0;
	char input[1245],result[1290];
	for(i=0;i<45;i++)
		input[i]=0;
	input[0]='1';
	for(i=1;i<=1000;i++)
	{
		multiply(result,input,2);
		cout<<endl<<"i="<<i<<"\t";
		//cout<<"\ni="<<i<<"\tres="<<result;
		/*for(j=1;j<=strlen(result);j++)
		{
			cout<<result[j-1];
			if(j%3==0)
				cout<<" ";
		}*/
		strcpy(input,result);
	}
	for(i=0;i<strlen(result);i++)
	{
		count=count + (result[i] - 48);
	}
	cout<<"\n\nSum of thre digits : "<<count;
	cout<<endl;
	return 0;
}

void multiply(char* res,char* input,int a)
{
	int inlen,i,temp,k=0,carry=0;
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
}