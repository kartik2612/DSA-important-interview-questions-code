
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
  public:
    //Function to check if S is a subtree of tree T.
    
    void inorder(Node * root, vector<int> &v)
{
    if(root==NULL)
    {
        v.push_back(-5);
        return ;
    }
    inorder(root->left,v);
   
    v.push_back(root->data);
    inorder(root->right,v);
}

void preorder(Node * root, vector<int> &v)
{
    if(root==NULL)
    {
        v.push_back(-5);
        return ;
    }
    v.push_back(root->data);
    preorder(root->left,v);
    preorder(root->right,v);
}

bool issubtre( vector<int> parent ,vector<int> child)
{
    string s1="";
    string s2="";
    
    for(int i=0;i<parent.size();i++)
      s1+= to_string(parent[i]);
    for(int i=0;i<child.size();i++)
      s2+= to_string(child[i]);
     
     if( s1.find(s2) != -1)
       return true;
       
       return false;
}

bool isSubTree(Node*  T1 ,Node * T2)
{
   vector<int> int1;
   vector<int> int2;
   vector<int> pret1;
   vector<int> pret2;
   
   inorder(T1,int1);
   inorder(T2,int2);
   preorder(T1,pret1);
   preorder(T2,pret2);
  return issubtre(int1,int2) && issubtre(pret1,pret2); 
 }
};

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string strT, strS;
        getline(cin, strT);
        Node *rootT = buildTree(strT);
        getline(cin, strS);
        Solution obj;
        Node *rootS = buildTree(strS);
        cout << obj.isSubTree(rootT, rootS) << "\n";

    }
    return 0;
}  // } Driver Code Ends
