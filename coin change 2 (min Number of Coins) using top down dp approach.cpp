#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int n, int sum) 
	{ 
	    // Your code goes here
	    int dp[n+1][sum+1];
	    //initialize 1st row and 1st coloumn
	    for(int i=0;i<n+1;i++)
	    {
	        for(int j=0;j<sum+1;j++)
	        {
	            if(i==0)
	            {
	                dp[i][j]=INT_MAX-1;
	            }
	            if(j==0)
	            {
	                dp[i][j]=0;
	            }
	        }
	    }
	    dp[0][0]=INT_MAX-1;
	    //then initialize 2nd row
	    for(int j=1;j<sum+1;j++)
	    {
	        if(j%coins[0]==0)
	        {
	            dp[1][j]=j/coins[0];
	        }
	        else
	        {
	            dp[1][j]=INT_MAX-1;
	        }
	    }
	    //then fill the matrix with main code
	    for(int i=2;i<n+1;i++)
	    {
	        for(int j=1;j<sum+1;j++)
	        {
	            if(coins[i-1]<=j)
	            {
	                dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
	            }
	            else if(coins[i-1]>j)
	            {
	                dp[i][j]=dp[i-1][j];
	            }
	        }
	    }
	    if(dp[n][sum]==INT_MAX-1)
	    {
	        return -1;
	    }
	    return dp[n][sum];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
