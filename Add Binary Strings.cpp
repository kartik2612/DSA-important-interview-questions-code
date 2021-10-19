#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string a, string b)
	{
	    // your code here
	    string ans="";
	    string temp="0";
	    int i=a.size()-1;
	    int j=b.size()-1;
	    while(i>=0 && j>=0)
	    {
	        if(a[i]=='0' && b[j]=='0' && temp=="0")
	        {
	            ans+="0";
	            temp="0";
	            i--;
	            j--;
	        }
	        else if(a[i]=='0' && b[j]=='0' && temp=="1")
	        {
	            ans+="1";
	            temp="0";
	            i--;
	            j--;
	        }
	        else if(a[i]=='0' && b[j]=='1' && temp=="0")
	        {
	            ans+="1";
	            temp="0";
	            i--;
	            j--;
	        }
	        else if(a[i]=='0' && b[j]=='1' && temp=="1")
	        {
	            ans+="0";
	            temp="1";
	            i--;
	            j--;
	        }
	        else if(a[i]=='1' && b[j]=='0' && temp=="0")
	        {
	            ans+="1";
	            temp="0";
	            i--;
	            j--;
	        }
	        else if(a[i]=='1' && b[j]=='0' && temp=="1")
	        {
	            ans+="0";
	            temp="1";
	            i--;
	            j--;
	        }
	        else if(a[i]=='1' && b[j]=='1' && temp=="0")
	        {
	            ans+="0";
	            temp="1";
	            i--;
	            j--;
	        }
	        else if(a[i]=='1' && b[j]=='1' && temp=="1")
	        {
	            ans+="1";
	            temp="1";
	            i--;
	            j--;
	        }
	    }
	    while(i>=0)
	    {
	        if(a[i]=='1' && temp=="1")
	        {
	            ans+="0";
	            temp="1";
	            i--;
	        }
	        else if(a[i]=='0' && temp=="0")
	        {
	            ans+="0";
	            temp="0";
	            i--;
	        }
	        else if(a[i]=='0' && temp=="1")
	        {
	            ans+="1";
	            temp="0";
	            i--;
	        }
	        else if(a[i]=='1' && temp=="0")
	        {
	            ans+="1";
	            temp="0";
	            i--;
	        }
	    }
	    while(j>=0)
	    {
	        if(b[j]=='1' && temp=="1")
	        {
	            ans+="0";
	            temp="1";
	            j--;
	        }
	        else if(b[j]=='0' && temp=="0")
	        {
	            ans+="0";
	            temp="0";
	            j--;
	        }
	        else if(b[j]=='0' && temp=="1")
	        {
	            ans+="1";
	            temp="0";
	            j--;
	        }
	        else if(b[j]=='1' && temp=="0")
	        {
	            ans+="1";
	            temp="0";
	            j--;
	        }
	    }
	    if(temp=="1")
	    {
	        ans+="1";
	    }
	    reverse(ans.begin(),ans.end());
	    while(ans[0]!='1')
	    {
	        ans.erase(ans.begin());
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends
