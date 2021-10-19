#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int n;
	cin>>n;
	long long int t=n;
	long long int ans=0;
	while(t--)
	{
		ans+=n;
	}
	cout<<ans;
	return 0;
}

//tc o(n)  sc o(1)
