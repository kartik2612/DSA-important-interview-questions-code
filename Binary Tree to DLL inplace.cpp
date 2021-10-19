#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}



 // } Driver Code Ends
/* Structure for tree and linked list

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

// This function should return head to the DLL
class Solution
{
    public:    
    
    /*void helper(Node *root,vector<int> &vec)
    {
        if(root==NULL)
        {
            return;
        }
        helper(root->left,vec);
        vec.push_back(root->data);
        helper(root->right,vec);
    }
    
    void DLL(Node **head_ref,Node **tail_ref,int data)
    {
        Node *newnode=newNode(data);
        if(*head_ref==NULL)
        {
            *head_ref=newnode;
            *tail_ref=newnode;
        }
        else
        {
            (*tail_ref)->right=newnode;
            newnode->left=*tail_ref;
            *tail_ref=newnode;
        }
    }*/
    
    void bToDLL_helper(Node **head_ref,Node **tail_ref,Node *root)
    {
        if(root==NULL)
        {
            return;
        }
        bToDLL_helper(head_ref,tail_ref,root->left);
        if(*head_ref==NULL)
        {
            *head_ref=root;
            *tail_ref=root;
        }
        else
        {
            (*tail_ref)->right=root;
            (*tail_ref)->right->left=*tail_ref;
            *tail_ref=(*tail_ref)->right; //*tail_ref=root;
        }
        bToDLL_helper(head_ref,tail_ref,root->right);
    }
    
    Node * bToDLL(Node *root)
    {
        // your code here
        
        Node *head=NULL,*tail=NULL;
        bToDLL_helper(&head,&tail,root);
        return head;
        /*vector<int> vec;
        helper(root,vec);
        Node *head=NULL,*tail=NULL;
        for(int i=0;i<vec.size();i++)
        {
            DLL(&head,&tail,vec[i]);
        }
        return head;*/
    }
};



// { Driver Code Starts.


/* Function to print nodes in a given doubly linked list */
void printList(Node *node)
{
    Node *prev = NULL;
    while (node!=NULL)
    {
        cout << node->data << " ";
        prev = node;
        node = node->right;
    }
    cout << endl;
    while (prev!=NULL)
    {
        cout << prev->data << " ";
        prev = prev->left;
    }
    cout << endl;
}

void inorder(Node *root)
{
   if (root != NULL)
   {
       inorder(root->left);
       cout << root->data;
       inorder(root->right);
   }
}

/* Driver program to test size function*/
int main()
{
  int t;
  cin >> t;
  getchar();
  
  while (t--)
  {
     string inp;
     getline(cin, inp);
     Node *root = buildTree(inp);
     
     Solution ob; 
     Node *head = ob.bToDLL(root);
     printList(head);

  }
  return 0;
}

  // } Driver Code Ends
