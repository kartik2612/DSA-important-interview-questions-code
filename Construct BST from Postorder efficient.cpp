#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");
}
	return 0;
}
// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/

/*Node* BST(Node *root,int key)
{
    if(root==NULL)
    {
        return new Node(key);
    }
    if(key<root->data)
    {
        root->left=BST(root->left,key);
    }
    else
    {
        root->right=BST(root->right,key);
    }
    return root;
}*/

Node* BST(int post[],int &i,int n,int min,int max)
{
    if(i<0 || min>max)
    {
        return NULL;
    }
    if(post[i]>max || post[i]<min)
    {
        return NULL;
    }
    int temp=post[i];
    Node *root=new Node(post[i]);
    i--;
    root->right=BST(post,i,n,temp+1,max);
    root->left=BST(post,i,n,min,temp-1);
    return root;
}

Node *constructTree (int post[], int size)
{
//code here

int i=size-1;
int min=INT_MIN;
int max=INT_MAX;
Node *root=BST(post,i,size,min,max);
return root;
/*Node *root=NULL;
for(int i=size-1;i>=0;i--)
{
    root=BST(root,post[i]);
}
return root;*/
}
