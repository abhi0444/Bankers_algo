#include<iostream>
using namespace std;
int main()
{
	int n,r,flag=0,g=0;
	cout<<"Enter Number of Processes"<<endl;  			     //input number of processes
	cin>>n;
	cout<<"Enter Number of Resources System have"<<endl;     //input number of instances/resources that system have
	cin>>r;
	int a[n][r],z[n];
	for(int i=0;i<n;i++)							   		//loop for input maximum number of resources that each process needed
	{
		cout<<"Maximum Number of resources Needed by Process- "<<i+1<<endl;
		for(int j=0;j<r;j++)
		{
			cin>>a[i][j];
		}
		z[i]=0;
	}
	int h[n][r];
	for(int i=0;i<n;i++)								   //loop for input how many resources that each process hold's			
	{
		cout<<"Number of resources that "<<i+1<<" Process have"<<endl;
		for(int j=0;j<r;j++)
		{
			cin>>h[i][j];
		}
	}
	cout<<"\t\t\t\tResources needed table"<<endl<<endl<<endl;
	cout<<"Process No.\t\t";
	for(int i=0;i<r;i++)
	{
		cout<<"R"<<i+1<<"\t\t";
	}
	for(int i=0;i<n;i++)								  //loop to calculate need of resources by processes
	{	cout<<endl<<"P"<<i+1<<"\t\t\t";
		for(int j=0;j<r;j++)
		{
			h[i][j]=a[i][j]-h[i][j];
			cout<<h[i][j]<<"\t\t";
		}
	}
	cout<<endl<<"Number of Resources System have"<<endl;
	int k[r];
	for(int i=0;i<r;i++)								//loop to input number of resources system have
	{
		cin>>k[i];
	}
	for(int ab=g;ab<n;)
	{
		for(int i=0;i<n;i++)
		{
			flag=0;
			for(int j=0;j<r;j++)
			{
				if(k[j]<h[i][j])
				{	
					break;
				}
				else 
				{
					flag=flag+1;	
				}
			}
			if(flag>=r)
			{
				for(int j=0;j<r;j++)
				{
					k[j]=k[j]+a[i][j];
					h[i][j]=10000;
				}
				g=g+1;
				cout<<"P"<<i+1<<" is executed"<<endl;				
			}
		}
		if(ab==g)
		{
			break;
		}
		ab=g;
	}
	if(g>=n)
	{
		cout<<"\t\t\t\t\tSystem is Safe"<<endl<<endl;
	}
	else
	{
		cout<<"\t\t\t\t\t\tDeadlock Occurs"<<endl;
	}
	return 0;
}
