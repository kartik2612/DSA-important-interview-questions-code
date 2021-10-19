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
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        int count1=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==1)
            {
                count1++;
            }
        }
        double prod=1;
        for(int i=count1+1;i<n;i++)
        {
            prod*=a[i];
        }
        double ans=pow(a[count1],prod);
        prod=1;
        double prod1=1;
        for(int i=n-2;i>=count1;i--)
        {
            prod1*=a[i];
        }
        double ans1=pow(a[n-1],prod1);
        if(ans<ans1)
        {
            for(int i=0;i<count1;i++)
            {
                cout<<a[i]<<" ";
            }
            for(int i=count1;i<n;i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        else
        {
            for(int i=0;i<count1;i++)
            {
                cout<<a[i]<<" ";
            }
            for(int i=n-1;i>=count1;i--)
            {
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
