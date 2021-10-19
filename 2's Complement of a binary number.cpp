
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string complement(string bi){
        // code here
        int i=0;
        while(i<bi.size())
        {
            if(bi[i]=='0')
            {
                bi[i]='1';
                i++;
            }
            else if(bi[i]=='1')
            {
                bi[i]='0';
                i++;
            }
        }
        string temp="1";
        string ans="";
        i=bi.size()-1;
        while(i>=0)
        {
            if(bi[i]=='0' && temp=="0")
            {
                ans+="0";
                temp="0";
                i--;
            }
            else if(bi[i]=='0' && temp=="1")
            {
                ans+="1";
                temp="0";
                i--;
            }
            else if(bi[i]=='1' && temp=="0")
            {
                ans+="1";
                temp="0";
                i--;
            }
            else if(bi[i]=='1' && temp=="1")
            {
                ans+="0";
                temp="1";
                i--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string bi;
        cin>>bi;
        
        Solution ob;
        cout<<ob.complement(bi)<<endl;
    }
    return 0;
}  // } Driver Code Ends
