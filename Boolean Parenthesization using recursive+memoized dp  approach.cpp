
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

int dp[201][201][2];
int mod=1003;

class Solution{
public:

int solve(string &str,int i,int j,int isTrue)
{
    //base condition
    if(i>j)
    {
       return dp[i][j][isTrue]=0;
    }
    if(i==j)
    {
        if(isTrue==1)
        {
            return dp[i][j][isTrue]=(str[i]=='T') ? 1 : 0;
        }
        else
        {
            return dp[i][j][isTrue]=(str[i]=='F') ? 1 : 0;
        }
    }
    if(dp[i][j][isTrue]!=-1)
    {
        return dp[i][j][isTrue];
    }
    int ans=0;
    for(int k=i+1;k<=j-1;k+=2)
    {
        int lt=solve(str,i,k-1,1);
        int lf=solve(str,i,k-1,0);
        int rt=solve(str,k+1,j,1);
        int rf=solve(str,k+1,j,0);
        if(str[k]=='|')
        {
            if(isTrue==1)
            {
                ans+=(lt*rt)+(lt*rf)+(lf*rt);
            }
            else
            {
                ans+=(lf*rf);
            }
        }
        else if(str[k]=='^')
        {
            if(isTrue==1)
            {
                ans+=(lt*rf)+(lf*rt);
            }
            else
            {
                ans+=(lt*rt)+(lf*rf);
            }
        }
        else if(str[k]=='&')
        {
            if(isTrue==1)
            {
                ans+=(lt*rt);
            }
            else
            {
                ans+=(lt*rf)+(lf*rt)+(lf*rf);
            }
        }
    }
    return dp[i][j][isTrue]=ans%mod;
}

    int countWays(int N, string str){
        // code here
        int i=0;
        int j=N-1;
        memset(dp,-1,sizeof(dp));
        int ans=solve(str,0,N-1,1);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
