#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int n;
	cin>>n;
	if(n<0)
	{
		n=-n;
	}
	long long int t=n;
	long long int ans=0;
	for(int i=31;i>=0;i--)
	{
		if((1<<i)<=n)
		{
			ans+=(n<<i);
			n=n-(1<<i);
		}
	}
	cout<<ans<<endl;
	return 0;
}

//tc o(logn)  sc o(1)
