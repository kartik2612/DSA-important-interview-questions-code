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
	int min=INT_MAX;
	int max=INT_MIN;
	for(int i=0;i<n;i++)
	{
	    if(arr[i] > max)
	    {
	        max=arr[i];
	    }
	    if(arr[i] < min)
	    {
	        min=arr[i];
	    }
	    mp[arr[i]]++;
	}
	int target=max-min+1;
	int size=mp.size();
	if(target == size)
	{
	    return true;
	}
	return false;
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