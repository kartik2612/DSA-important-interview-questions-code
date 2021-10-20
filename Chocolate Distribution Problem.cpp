#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int m;
        cin>>m;
        sort(a,a+n);
        int minn=INT_MAX;
        int k;
        for(int i=0;m-1+i<n;i++)
        {
            k=a[m-1+i]-a[i];
            if(k<minn)
            {
                minn=k;
            }
        }
        cout<<minn<<endl;
    }
    return 0;
}
