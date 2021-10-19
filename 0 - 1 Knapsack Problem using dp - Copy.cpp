#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

int dp[1001][1001]; //bcoz two variables are changing

class Solution
{
    public:
    //this is dp=recursion+memoization
    int knapsack_util(int w,int wt[],int val[],int n)
    {
       if(n==0 || w==0) //base condition 
       {
           return 0;
       }
       if(dp[n][w]!=-1) //if we had calculated earlier then we will return that calculated value
       {
           return dp[n][w];
       }
       if(wt[n-1]<=w) //in this we have to choose or not to choose so we will find max of both
       {
           return dp[n][w]=max(val[n-1]+knapsack_util(w-wt[n-1],wt,val,n-1),knapsack_util(w,wt,val,n-1));
       }
       else if(wt[n-1]>w) //if our curr item overloads the capacity then not choose
       {
           return dp[n][w]=knapsack_util(w,wt,val,n-1);
       }
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       //static int dp[n+1][w+1];  //2d matrix bcoz n and w are changing
       memset(dp,-1,sizeof(dp));
       return knapsack_util(w,wt,val,n);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
