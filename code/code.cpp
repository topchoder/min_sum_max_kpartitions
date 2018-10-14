#include <bits/stdc++.h>
using namespace std;

int mini(int *a,int low,int high)
{
	int m=a[low];
	for(int i=low+1;i<=high;i++)
	{
		if(m>a[i])
		{
           m=a[i];
		}
	}
	return m;
}

void minsum(int *a,int n,int k,int idx,int size,int& ans,int cur)
{
   if(size>k)
   {
		return;
   }
   if(size==k&&idx==n)
   {
   	   ans=min(ans,cur);
   	   return;
   }
   for(int i=idx;i<n;i++)
   {
   	   int w=mini(a,idx,i);
   	   minsum(a,n,k,i+1,size+1,ans,cur+w);
   }
}

int main()
{
	int *a,n,k;
	cout<<"n "<<"\n";
	cin>>n;
	cout<<"k "<<"\n";
	cin>>k;
	a=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int ans=INT_MAX;
	int cur=0;
	
	minsum(a,n,k,0,0,ans,cur);
  cout<<"minimum sum of maximums of k partitions "<<ans<<"\n";
	return 0;
}
