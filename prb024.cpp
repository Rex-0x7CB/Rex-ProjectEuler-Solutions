/*
Lexicographic permutations
Problem 24

A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

*/

#include<iostream>

using namespace std;

struct let
{
	int letter;				//A letter or a digit
	int used_flag;			//Represents whether or not it is already used in forming a string
	int factorial;
	int offset;				//Offset by which "letter" has to be incremented with
};

int main()
{
	int n,i,fact=1,index,temp,flag,j;
	cout<<"\nEnter the number of letters : ";
	cin>>n;

	int answer[n];
	struct let p[n];

	cout<<"\nStart entering numbers from least to most priority";
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter priority "<<(n-i)<<" : ";
		cin>>p[i].letter;
		p[i].used_flag=0;
		p[i].offset=0;
		if(i>0)
		{
			fact=fact*(i);
		}
		p[i].factorial=fact;
	}

	cout<<"\nEnter the index of lexicographic permutation you want to find : ";			//(index)th lexicographic permutation would be found out
	cin>>index;

	temp=index-1;

	for(i=n-1;i>=0;i--)
	{
		cout<<"\ni="<<i<<"\tp[i].factorial="<<p[i].factorial<<"\ttemp="<<temp;
		p[i].offset=temp/p[i].factorial;
		if(p[i].offset>(n-1))
		{
			cout<<"\nInsufficient numbers of \"letter\" to reach index"<<endl;
			return 1;
		}
		temp=temp%p[i].factorial;
	}

	cout<<"\nOffsets : "<<endl;
	for(i=n-1;i>=0;i--)
	{
		cout<<p[i].offset;
	}

	for(i=n-1;i>=0;i--)
	{
		flag=1;
		j=0;
		while(flag)
		{
			if(p[j].used_flag==0)
			{
				answer[i]=p[j].letter;
				flag=0;
			}
			else
			{
				j++;
			}
		}
		cout<<"\nInitial letter for i="<<i<<" : "<<answer[i]<<" with j="<<j;
		//j++;
		if(p[i].offset!=0)
		{
			while(p[i].offset)
			{
				j++;
				if(p[j].used_flag==0)
				{
					p[i].offset--;
				}
				cout<<"\n\ti="<<i<<"\tj="<<j<<"\tanswer[i]="<<answer[i]<<"\tp[j].letter="<<p[j].letter<<"\tp[i].offset="<<p[i].offset;
			}
		}
		answer[i]=p[j].letter;
		p[j].used_flag=1;
		cout<<"\n\t\tSetting p["<<j<<"].used_flag="<<p[j].used_flag;
	}
	cout<<endl;
	cout<<"\nLexicographic permutation with index="<<index<<" for given letters is ";
	for(i=n-1;i>=0;i--)
	{
		cout<<answer[i];
	}
	cout<<endl;
	return 0;
}


/*
 * {
			if(p[j].used_flag==0)
			{

				if(p[i].offset==0)
				{
					p[j].used_flag=1;
					cout<<"\n\t\tSetting p["<<j<<"].used_flag="<<p[j].used_flag;
				}
				else
				{
					j++;
					p[i].offset--;

				}
			}
			cout<<"\n\ti="<<i<<"\tj="<<j<<"\tanswer[i]="<<answer[i]<<"\tp[j].letter="<<p[j].letter<<"\tp[i].offset="<<p[i].offset;
		}while(p[i].offset);
	}
	*/
