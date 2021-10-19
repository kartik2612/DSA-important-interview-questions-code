#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int prices[n];
	for(int i=0;i<n;i++)
	{
		cin>>prices[i];
	}
	int minprice=INT_MAX;
	int maxprofit=0;
	for(int i=0;i<n;i++)
	{
		if(prices[i]<=minprice)
		{
			minprice=prices[i];
		}
		else if(prices[i]>minprice)
		{
			maxprofit=max(maxprofit,prices[i]-minprice);
		}
	}
	cout<<maxprofit;
	return 0;
}
