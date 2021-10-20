#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1,string &s2)
    {
        // Your code here
        //brute force solution 
        //rotate the s1 one by one and simultaneously compare with s2 ......if matches
        //then return true .and after the loop return false;
        int n=s1.size();
        if(s1.size()==s2.size())
        {
            for(int i=0;i<s1.size();i++)
            {
                //doing rotation
                reverse(s1.begin(),s1.begin()+1);
                reverse(s1.begin()+1,s1.begin()+n);
                reverse(s1.begin(),s1.begin()+n);
                if(s1.compare(s2)==0)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}
  // } Driver Code Ends
