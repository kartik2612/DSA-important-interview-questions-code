#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int isPossiblePalindrome(string s, int k)
	{
	    // Your code goes here
	    string s1=s;
	    reverse(s1.begin(),s1.end());
	    int n=s.size();
	    int dp[n+1][n+1];
	    for(int i=0;i<n+1;i++)
	    {
	        for(int j=0;j<n+1;j++)
	        {
	            if(i==0 || j==0)
	            {
	                dp[i][j]=0;
	            }
	        }
	    }
	    for(int i=1;i<n+1;i++)
	    {
	        for(int j=1;j<n+1;j++)
	        {
	            if(s[i-1]==s1[j-1])
	            {
	                dp[i][j]=1+dp[i-1][j-1];
	            }
	            else
	            {
	                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	            }
	        }
	    }
	    int pal=s.size()-dp[n][n];
	    if(pal<=k)
	    {
	        return 1;
	    }
	    else
	    {
	        return 0;
	    }
	}
	  
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        int k;
        cin >> k;

       
	    Solution ob;
	    cout << ob.isPossiblePalindrome(s, k) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
