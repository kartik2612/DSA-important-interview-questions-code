// Initial template for C++
/* TC IS O(NlogN)
   SC IS O(1)   */


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution {
  public:
  
  bool isvalid(int arr[],int n,int m,int maxx)
  {
      int student=1;
      int sum1=0;
      for(int i=0;i<n;i++)
      {
          sum1+=arr[i];
          if(sum1>maxx)
          {
              student++;
              sum1=arr[i];
          }
          if(student>m)
          {
              return false;
          }
      }
      return true;
  }
  
  
    int findPages(int arr[], int n, int m) {
        //code here
        if(n<m)
        {
            return -1;
        }
        int result=-1;
        int start=INT_MIN;
        for(int i=0;i<n;i++)
        {
            start=max(start,arr[i]);
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        int end=sum;
        while(start<=end)
        {
            int mid=start+((end-start)/2);
            if(isvalid(arr,n,m,mid)==true)
            {
                result=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return result;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends
