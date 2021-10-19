
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node* reverse(Node *head)
{
    Node *curr = head;
    Node *next = NULL;
    Node *prev = NULL;
    
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}
void addBack(Node *&head, Node *&last, int data){
   
   Node *newNode=new Node(data);
//   newNode->data=data;
   newNode->next=NULL;
   
   if(last==NULL){
       head=newNode;
   }
   else{
       last->next=newNode;
   }
   last=newNode;
   
}
Node*  addTwoLists(Node* first, Node* second){
    
  Node *head1=reverse(first);
  Node *head2=reverse(second);
  Node *res;
  Node *last=NULL; // Last node of new list
  int total,carry=0;
  // One of them not NULL
  while(head1|| head2){
      
      int a=(head1)?(head1->data):(0); // If NULL contri is 0
      int b=(head2)?(head2->data):(0);
      
      total=(a+b+carry);
      carry=(total/10);
      total=total%10;
      
      // Add this to back of new list
      addBack(res,last,total);
      
      if(head1){
          head1=head1->next;
      }
      
      if(head2){
           head2=head2->next;
      }
  }
  if(carry!=0){
      addBack(res,last,carry);
  }
  res = reverse(res);
  return res;
}
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends
