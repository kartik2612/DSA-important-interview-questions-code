#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            set<int> s1;
            set<int> s2;
            set<int> s3;
            for(int i=0;i<n1;i++)
            {
                s1.insert(A[i]);
            }
            for(int i=0;i<n2;i++)
            {
                s2.insert(B[i]);
            }
            for(int i=0;i<n3;i++)
            {
                s3.insert(C[i]);
            }
            vector<int> vec;
            set<int> :: iterator it;
            for(it=s1.begin();it!=s1.end();it++)
            {
                if(s2.find(*it)!=s2.end())
                {
                    if(s3.find(*it)!=s3.end())
                    {
                        vec.push_back(*it);
                    }
                }
            }
            return vec;
        }

};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends
