#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int vec[n];
	for(int i=0;i<n;i++)
	{
		cin>>vec[i];
	}
	int q;
	cin>>q;
	sort(vec,vec+n);
	int sum[n+1];
	sum[0]=0;
	for(int i=1;i<=n;i++)
	{
	    sum[i]=sum[i-1]+vec[i-1];
	}
	while(q--)
	{
	    int x;
	    cin>>x;
	    int idx=upper_bound(vec,vec+n,x)-vec;
	    cout<<idx<<" "<<sum[idx]<<endl;
	}
	return 0;
}
