#include<bits/stdc++.h>
using namespace std;

int find_stocks(int a[],int n,int k)
{
    vector<pair<int,int> > vec;
    for(int i=0;i<n;i++)
    {
        vec.push_back(make_pair(a[i],i+1));
    }
    sort(vec.begin(),vec.end());
    int sum=0;
    int stocks=0;
    int flag=0;
    for(int i=0;i<vec.size();i++)
    {
        int temp=vec[i].second;
        for(int j=0;j<temp;j++)
        {
            sum+=vec[i].first;
            if(sum<=k)
            {
                stocks++;
            }
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            break;
        }
    }
    return stocks;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int k;
    cin>>k;
    cout<<"the number of stocks are "<<find_stocks(a,n,k)<<endl;
    return 0;
}
