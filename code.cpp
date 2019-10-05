#include<iostream>
using namespace std;
int main()
{
	int n,r,flag=0,g=0;
	cout<<"Enter Number of Processes"<<endl;
	cin>>n;
	cout<<"Enter Number of Resources System have"<<endl;
	cin>>r;
	int a[n][r],z[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter Maximum Number of resources Needed for process "<<i+1<<" in order of A B C D"<<endl;
		for(int j=0;j<r;j++)
		{
			cin>>a[i][j];
		}
		z[i]=0;
	}
	cout<<"Enter number of Resources Process have"<<endl;
	int h[n][r];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter Number of resources that process "<<i+1<<" have"<<endl;
		for(int j=0;j<r;j++)
		{
			cin>>h[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<r;j++)
		{
			h[i][j]=a[i][j]-h[i][j];
		}
	}
	cout<<"Enter number of Resources System have"<<endl;
	int k[r];
	for(int i=0;i<n;i++)
	{
		cin>>k[i];
	}
	for(int i=0;i<n;i++)
	{
		cout<<"Checking for Process "<<i+1<<endl; 
		for(int j=0;j<r;j++)
		{
			if(k[j]<=h[i][j])
			{
				break;
			}
			else {
				flag=flag+1;
			}
		}
		if(flag>=r)
		{
		for(int j=0;j<r;j++)
		{
			k[j]=k[j]+a[i][j];
		}
		g=g+1;
		cout<<"Process "<<i+1<<" is executed"<<endl;
		z[i]=1;	
		}
	}
	for(int p=0;p<n;p++)
	{
		
	for(int i=0;i<n;i++)
	{
		if(z[i]==0)
		{
		cout<<"Checking for Process "<<i+1<<endl; 
		for(int j=0;j<r;j++)
		{
			if(k[j]<=h[i][j])
			{
				break;
			}
			else {
				flag=flag+1;
			}
		}
		if(flag>=r)
		{
		for(int j=0;j<r;j++)
		{
			k[j]=k[j]+a[i][j];
		}
		g=g+1;
		cout<<"Process "<<i+1<<" is executed"<<endl;
		z[i]=1;	
		}
		}
	}
	}
	if(g>=n)
	{
		cout<<"System is Safe"<<endl;
	}
	else
	{
		cout<<"Deadlock May Occur"<<endl;
	}
	return 0;
}
