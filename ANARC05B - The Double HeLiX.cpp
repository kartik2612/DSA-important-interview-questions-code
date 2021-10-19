#include<bits/stdc++.h>
using namespace std;
int main()
{
    while(true)
    {
        int n;
        cin>>n;
        if(n==0)
        {
            break;
        }
        else
        {
            int m;
            cin>>m;
            int a[n],b[m];
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
            }
            for(int i=0;i<m;i++)
            {
                cin>>b[i];
            }
            int i=0;
            int j=0;
            int sum1=0,sum2=0;
            int ma=0;
            while(i<n && j<m)
            {
                if(a[i]<b[j])
                {
                    sum1+=a[i];
                    i++;
                }
                else if(a[i]>b[j])
                {
                    sum2+=b[j];
                    j++;
                }
                else
                {
                    ma=ma+max(sum1,sum2)+a[i];
                    sum1=0;
                    sum2=0;
                    i++;
                    j++;
                }
            }
            while(i<n)
            {
                sum1=sum1+a[i];
                i++;
            }
            while(j<m)
            {
                sum2=sum2+b[j];
                j++;
            }
            ma=ma+max(sum1,sum2);
            cout<<ma<<endl;
        }
    }
}
