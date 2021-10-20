#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
  
  void solve_util(vector<int> &A,vector<vector<int> > &ans,vector<int> temp,int index,int sum)
  {
      if(sum==0)
      {
          ans.push_back(temp);
          return;
      }
      for(int i=index;i<A.size();i++)
      {
          if((sum-A[i])>=0)
          {
              temp.push_back(A[i]);
              sum-=A[i];
              solve_util(A,ans,temp,i,sum);
              sum+=A[i];
              temp.pop_back();
          }
      }
  }
  
    vector<vector<int> > combinationSum(vector<int> &A, int sum) {
        // Your code here
        vector<vector<int> > ans;
        vector<int> temp;
        unordered_set<int> s(A.begin(),A.end());
        A.clear();
        unordered_set<int> :: iterator it;
        for(it=s.begin();it!=s.end();it++)
        {
            A.push_back(*it);
        }
        sort(A.begin(),A.end());
        solve_util(A,ans,temp,0,sum);
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends
