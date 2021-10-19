#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node* solve(vector<int> &nums,int low,int high)
{
    if(low>high)
    {
        return NULL;
    }
    int mid=low+(high-low)/2;
    Node *root=new Node(nums[mid]);
    root->left=solve(nums,low,mid-1);
    root->right=solve(nums,mid+1,high);
    return root;
}

void preorder(Node *root,vector<int> &vec)
{
    if(root==NULL)
    {
        return;
    }
    vec.push_back(root->data);
    preorder(root->left,vec);
    preorder(root->right,vec);
}

    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        vector<int> vec;
        int low=0;
        int high=nums.size()-1;
        Node *root=solve(nums,low,high);
        preorder(root,vec);
        return vec;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends
