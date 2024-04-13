//{ Driver Code Starts
//Initial Template for C++
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <bits/stdc++.h>
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


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/

// } Driver Code Ends
/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
class Solution{
public:
    int getNthFromLast(Node *head, int n)
{
    // Your code here
    if (head == nullptr)
        return -1; // Empty list
    
    Node *temp = head;
    int totalNodes = 0;
    
    while (temp != nullptr) {
        totalNodes++;
        temp = temp->next;
    }
    
    // Check if n is greater than the total number of nodes
    if (n > totalNodes || n <= 0)
        return -1; // Invalid value of n
    
    int target = totalNodes - n;
    
    // If n is equal to the total number of nodes, return the data of the head node
    if (target == 0)
        return head->data;
    
    temp = head;
    // Traverse to the target node
    while (target > 0) {
        temp = temp->next;
        target--;
    }
    
    return temp->data;
}

};



//{ Driver Code Starts.

int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
    cout<<obj.getNthFromLast(head, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends