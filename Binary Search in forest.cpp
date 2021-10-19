#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int cuts(int tree[],int mid,int n)
    {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(tree[i] > mid)
            {
                ans+=(tree[i]-mid);
            }
        }
        return ans;
    }
    
    int find_height(int tree[], int n, int k)
    {
        // code here
        int i=0;
        int j=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(tree[i] > j)
            {
                j=tree[i];
            }
        }
        int ans=-1;
        while(i <= j)
        {
            int mid=i+(j-i)/2;
            int temp=cuts(tree,mid,n);
            if(temp == k)
            {
                return mid;
            }
            else if(temp < k)
            {
                j=mid-1;
            }
            else
            {
                i=mid+1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n;

        int tree[n];
        for(int i=0; i<n; i++)
            cin>>tree[i];
        cin>>k;
        Solution ob;
        cout<< ob.find_height(tree,n,k) << endl;
    }
    return 1;
}  // } Driver Code Ends
