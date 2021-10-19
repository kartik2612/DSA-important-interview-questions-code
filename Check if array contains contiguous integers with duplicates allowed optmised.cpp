// C++ implementation to check whether the array
// contains a set of contiguous integers
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    // Function to check whether the array contains
    // a set of contiguous integers
    bool areElementsContiguous(int arr[], int n)
    {
	// Complete the function
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
	{
	    mp[arr[i]]++;
	}
	int minn=*min_element(arr,arr+n);
	int maxx=*max_element(arr,arr+n);
	for(int i=minn;i<=maxx;i++)
	{
	    if(mp.find(i) == mp.end())
	    {
	        return false;
	    }
	}
	return true;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n + 1];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        if (ob.areElementsContiguous(arr, n))
            cout << "Yes" <<endl;
        else
            cout << "No" <<endl;
    }
	return 0;
}
  // } Driver Code Ends
