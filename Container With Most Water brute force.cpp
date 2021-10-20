//Initial template for C++

#include<iostream>
using namespace std;
int maxArea(int A[], int len);

 // } Driver Code Ends
//User function template for C++

long long maxArea(long long a[], int n)
{
    // Your code goes here
    long long int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            long long int temp=(j-i)*min(a[i],a[j]);
            if(temp > ans)
            {
                ans=temp;
            }
        }
    }
    return ans;
}

// { Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}
  // } Driver Code Ends
