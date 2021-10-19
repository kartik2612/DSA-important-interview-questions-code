#include<bits/stdc++.h>
using namespace std;
struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

void printlist(Node *head)
{
	if (head==NULL)return;
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void append(struct Node** headRef, char data)
{
	struct Node* new_node = new Node(data);
	struct Node *last = *headRef;

	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}

// task is to complete this function
struct Node* arrange(Node *head);

int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        char tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            append(&head, tmp);
        }
        head = arrange(head);
        printlist(head);
    }
	return 0;
}

// } Driver Code Ends


/*
Structure of the node of the linked list is as
struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/

bool isvowel(char val)
{
    if(val == 'a' || val == 'e' || val == 'i' || val == 'o' || val == 'u')
    {
        return true;
    }
    return false;
}

// task is to complete this function
// function should return head to the list after making 
// necessary arrangements
struct Node* arrange(Node *head)
{
   //Code here
   Node *dummy1=new Node('-1');
   Node *temp1=dummy1;
   Node *dummy2=new Node('-2');
   Node *temp2=dummy2;
   Node *temp=head;
   while(temp != NULL)
   {
       if(isvowel(temp->data) == true)
       {
           temp1->next=temp;
           temp1=temp1->next;
       }
       else
       {
           temp2->next=temp;
           temp2=temp2->next;
       }
       temp=temp->next;
   }
   temp2->next=NULL;
   temp1->next=dummy2->next;
   head=dummy1->next;
   return head;
}

