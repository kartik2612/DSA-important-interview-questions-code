#include<bits/stdc++.h>
using namespace std;  
// Linked list Node structure
struct Node
{
    char c;
    struct Node *next;
    
    Node(char x){
        c = x;
        next = NULL;
    }
    
};  


int compare(Node *list1, Node *list2); 


int main()
{
 int t,n;
 cin>>t;
 char x;
 while(t--)
 {
 cin>>n;
 cin>>x;
  Node *list1 = new Node(x);
    Node *temp=list1;
    for(int i=0;i<n-1;i++){
			cin>>x;
		temp->next = new Node(x);
		temp=temp->next;
		}
		int m;
		cin>>m;
    cin>>x;
    Node *list2 = new Node(x);
    temp=list2;
    for(int i=0;i<m-1;i++){
			cin>>x;
		temp->next = new Node(x);
		temp=temp->next;
		}
 
    cout << compare(list1, list2)<<endl;
    }
    return 0;
}
// } Driver Code Ends


/* Linked list Node structure
struct Node
{
    char c;
    struct Node *next;
    
    Node(char x){
        c = x;
        next = NULL;
    }
    
};
*/

// Compare two strings represented as linked lists
int compare(Node *list1, Node *list2) 
{
     // Code Here
     string temp1="";
     string temp2="";
     Node *temp=list1;
     while(temp!=NULL)
     {
         temp1+=(temp->c);
         temp=temp->next;
     }
     temp=list2;
     while(temp!=NULL)
     {
         temp2+=(temp->c);
         temp=temp->next;
     }
     if(temp1.compare(temp2)==0)
     {
         return 0;
     }
     else if(temp1.compare(temp2)>0)
     {
         return 1;
     }
     else
     {
         return -1;
     }
}
