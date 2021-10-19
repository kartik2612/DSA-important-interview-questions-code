#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n;
	cin>>m;
	int a[n];
	int b[m];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
	}
	unordered_map<int,int> m1;
	unordered_map<int,int> m2;
	for(int i=0;i<n;i++)
	{
		m1[a[i]]++;
	}
	for(int i=0;i<m;i++)
	{
		m2[b[i]]++;
	}
	unordered_map<int,int> :: iterator it;
	int count=0;
	for(it=m2.begin();it!=m2.end();it++)
	{
		int k=it->first;
		if(m1.find(k)!=m1.end())
		{
			count++;
		}
	}
	if(count==m2.size())
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	return 0;
}
