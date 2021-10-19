#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
  
  Node* reverse(Node *head)
  {
      Node *prev=NULL;
      Node *curr=head;
      Node *next=NULL;
      while(curr!=NULL)
      {
          next=curr->next;
          curr->next=prev;
          prev=curr;
          curr=next;
      }
      head=prev;
      return head;
  }
  
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node *temp=head;
        int n=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            n++;
        }
        //cout<<"value of n is "<<n<<endl;
        Node *first=NULL;
        Node *temmp=NULL;
        if(n %2 != 0)
        {
            int odd=(n/2)+1;
            first=head;
            temmp=head;
            while(odd--)
            {
                temmp=temmp->next;
            }
            //cout<<"velue of temmp is "<<temmp->data<<endl;
            Node *t=reverse(temmp);
            //cout<<"affer reverse the value of temmp ie "<<t->data<<endl;
            while(first && t)
            {
                if(first->data == t->data)
                {
                    first=first->next;
                    t=t->next;
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            int even=n/2;
            first=head;
            temmp=head;
            while(even--)
            {
                temmp=temmp->next;
            }
            //cout<<"velue of temmp is "<<temmp->data<<endl;
            Node *t=reverse(temmp);
            //cout<<"affer reverse the value of temmp ie "<<t->data<<endl;
            while(first && t)
            {
                if(first->data == t->data)
                {
                    first=first->next;
                    t=t->next;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends
