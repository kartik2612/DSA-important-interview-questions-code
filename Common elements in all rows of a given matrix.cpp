#include<bits/stdc++.h>
using namespace std;

void common_elements(vector<vector<int> >& vec,int n,int m)
{
	unordered_map<int,int> mp;
	for(int i=0;i<m;i++)
	{
		mp[vec[0][i]]++;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(mp.find(vec[i][j])!=mp.end())
			{
				mp[vec[i][j]]++;
			}
		}
	}
	unordered_map<int,int> :: iterator it;
	for(it=mp.begin();it!=mp.end();it++)
	{
		if(it->second>(n-1))
		{
			cout<<it->first<<" ";
		}
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	int ele;
	vector<vector<int> > vec(n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>ele;
			vec[i].push_back(ele);
		}
	}
	common_elements(vec,n,m);
}
