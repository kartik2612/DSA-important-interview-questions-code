#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    vector<int> temp;
	    vector<int> temp1;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]>=0)
	        {
	            temp.push_back(arr[i]);
	        }
	        else
	        {
	            temp1.push_back(arr[i]);
	        }
	    }
	    int i=0;
	    int j=0;
	    int k=0;
	    while(i < temp.size() and j < temp1.size())
	    {
	        arr[k++]=temp[i++];
	        arr[k++]=temp1[j++];
	    }
	    while(j < temp1.size())
	    {
	        arr[k++]=temp1[j++];
	    }
	    while(i < temp.size())
	    {
	        arr[k++]=temp[i++];
	    }
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
