// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int distinct(vector<vector<int>> mat, int N)
    {
        // code here
        int count=0;
        unordered_map<int,int> mp;
 
    // initialize 1st row elements with value 1
    for (int j = 0; j < N; j++)
        mp[mat[0][j]] = 1;
 
    // traverse the matrix
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // If element is present in the map and
            // is not duplicated in current row.
            if (mp[mat[i][j]] == i)
            {
               // we increment count of the element
               // in map by 1
                mp[mat[i][j]]++;
 
                // If this is last row
                if (i==N-1 && mp[mat[i][j]]==N)
                  count++;
            }
        }
    }
    return count;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> M(N, vector<int>(N, 0));
        for(int i = 0;i < N*N; i++)
            cin>>M[i/N][i%N];
        
        Solution ob;
        cout<<ob.distinct(M, N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
