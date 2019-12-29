#include<bits/stdc++.h>
using namespace std;

//segment tree to find minimum in the given range to process Range Minimum Queries

void constructTree(int a[],int segTree[],int low,int high,int pos)
{
	if(low==high)
	{
		segTree[pos] = a[low];
		return;
	}
	int mid = (low+high)/2;
	constructTree(a,segTree,low,mid,2*pos+1);
	constructTree(a,segTree,mid+1,high,2*pos+2);
	segTree[pos] = min(segTree[2*pos+1],segTree[2*pos+2]);
}
int RMQuery(int segTree[],int qlow,int qhigh,int low,int high,int pos)
{
	if(qlow<=low&&qhigh>=high)
	   return segTree[pos];
	if(qlow>high||qhigh<low)
	   return INT_MAX;
	int mid = (low+high)/2;
	return min(RMQuery(segTree,qlow,qhigh,low,mid,2*pos+1),RMQuery(segTree,qlow,qhigh,mid+1,high,2*pos+2));
}
int main()
{
	int n;
	cin>>n;
	int a[100000],segTree[100000];
	for(int i=0;i<n;i++)
	  cin>>a[i];
	constructTree(a,segTree,0,n-1,0);
    int q;
	cin>>q;
	int b,c;
	while(q--) 	  
	{
	   cin>>b>>c;
	   cout<<RMQuery(segTree,b,c,0,n-1,0)<<"\n";
	}
}
