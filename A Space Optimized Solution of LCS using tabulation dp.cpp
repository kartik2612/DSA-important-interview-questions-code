#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int dp[2][y+1];
        //lets do initialization
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<y+1;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i%2][j]=0;
                }
            }
        }
        //lets fil the matrix with code
        for(int i=1;i<x+1;i++)
        {
            for(int j=1;j<y+1;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i%2][j]=1+dp[(i+1)%2][j-1];
                }
                else
                {
                    dp[i%2][j]=max(dp[(i+1)%2][j],dp[i%2][j-1]);
                }
            }
        }
        return dp[x%2][y];
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends
