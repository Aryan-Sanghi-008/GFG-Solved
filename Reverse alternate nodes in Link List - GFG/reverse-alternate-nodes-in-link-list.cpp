//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{

public:
    struct Node *reverse(struct Node *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        Node *prev = NULL;

        while (head)
        {
            Node *temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    void rearrange(struct Node *odd)
    {
        if (!odd || !odd->next)
        {
            return;
        }

        Node *temp1 = odd;
        Node *temp2 = odd->next;
        Node *curr = temp2;

        while (temp1->next && temp2->next)
        {
            temp1->next = temp1->next->next;
            temp1 = temp1->next;

            temp2->next = temp2->next->next;
            temp2 = temp2->next;
        }

        struct Node *rev = reverse(curr);

        temp1->next = rev;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends