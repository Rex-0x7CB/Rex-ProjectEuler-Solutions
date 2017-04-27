#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int i,j,k,arr[2000],arr_index=0,sum,sum2,flag,flag2;
	
	for(i=1;i<=10000;i++)
	{
		sum=0;
		sum2=0;
		flag=1;
		
		for(j=1;j<=i/2;j++)
		{
			if(i%j==0)
				sum=sum+j;
			if(sum>10000)
			{
				flag=0;
				break;
			}
		}
		if(i==220)
			cout<<"sum for 220 = "<<sum;
		if(flag)
		{
			flag2=1;
			for(j=1;j<=sum/2;j++)
			{
				if(sum%j==0)
					sum2=sum2+j;
			}
			
			if(i==sum2)
			{
				for(j=0;j<arr_index;j++)
				{
					if(arr[j]==i)
					{
						flag2=0;
						break;
					}
				}
				if(flag2==1 && i!=sum)
				{
					arr[arr_index++]=i;
					arr[arr_index++]=sum;
				}
			}
		}
	}
	cout<<"\narr_index="<<arr_index;
	cout<<endl;
	sum=0;
	for(i=0;i<arr_index;i++)
	{
		cout<<arr[i]<<endl;
		sum=sum+arr[i];
	}
	cout<<"\nSum of Amicable pairs : "<<sum;
	getchar();
}