//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++



class Solution {
  public:
    bool areKAnagrams(string str1, string str2, int k) {
        // code here
        const int MAX_CHAR = 26;
        int n = str1.length();
    if (str2.length() != n)
        return false;
 
    int count1[MAX_CHAR] = {0};
    int count2[MAX_CHAR] = {0};
 
    // Store the occurrence of all characters
    // in a hash_array
    for (int i = 0; i < n; i++)
        count1[str1[i]-'a']++;
    for (int i = 0; i < n; i++)
        count2[str2[i]-'a']++;
      
    int count = 0;
 
    // Count number of characters that are
    // different in both strings
    for (int i = 0; i < MAX_CHAR; i++)
        if (count1[i] > count2[i])
            count = count + abs(count1[i]-count2[i]);
 
    // Return true if count is less than or
    // equal to k
    return (count <= k);
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		int k;
		cin>>k;
		Solution ob;
		if(ob.areKAnagrams(str1, str2, k) == true)
			cout<<"1\n";
		else
			cout<<"0\n";
	}
}  // } Driver Code Ends
