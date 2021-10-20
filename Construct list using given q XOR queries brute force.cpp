#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> constructList(vector<vector<int> > q, int n) {
        // code here
        vector<int> ans;
        ans.push_back(0);
        for(int i=0;i<q.size();i++)
        {
            int a=q[i][0];
            int b=q[i][1];
            if(a == 0)
            {
                ans.push_back(b);
            }
            else if(a == 1)
            {
                for(int j=0;j<ans.size();j++)
                {
                    ans[j] = ans[j] ^ b;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,type,val;
        cin>>N;
        
        vector<vector<int> > Q;
        
        for(int i=0; i<N; i++)
        {
            cin>>type>>val;
            vector<int> temp;
            temp.push_back(type);
            temp.push_back(val);
            Q.push_back(temp);
        }

        Solution ob;
        vector<int> res = ob.constructList(Q,N);
        
        for(int i=0; i<res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
