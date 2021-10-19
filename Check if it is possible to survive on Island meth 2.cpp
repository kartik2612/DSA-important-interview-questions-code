#include<bits/stdc++.h>
using namespace std;

void solve(int s,int n,int m)
{
    int food_amt;
    int result=0;
    int count_day=1;
    int day;
    int i;
    for(i=1;i<=s;)
    {
        if(count_day%7!=0)
        {
            food_amt=n;
            day=food_amt/m;
            count_day+=day;
            if(n<m)
            {
                break;
            }
            result++;
            i+=day;
        }
        else
        {
            break;
        }
    }
    if(i>=s)
    {
        cout<<"YES"<<" "<<result<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}

int main()
{
    int s,n,m;
    cin>>s>>n>>m;
    solve(s,n,m);
    return 0;
}
