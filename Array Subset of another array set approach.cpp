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
	set<int> s1;
	set<int> s2;
	for(int i=0;i<n;i++)
	{
		s1.insert(a[i]);
	}
	for(int i=0;i<m;i++)
	{
		s2.insert(b[i]);
	}
	int count=0;
	set<int> :: iterator it;
	for(it=s2.begin();it!=s2.end();it++)
	{
		if(s1.find(*it)!=s1.end())
		{
			count++;
		}
	}
	if(count==s2.size())
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}
