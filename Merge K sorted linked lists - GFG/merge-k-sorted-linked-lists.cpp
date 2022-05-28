// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 
struct node{
      Node* ptr;
      int idx;
    };
    struct compare{
        bool operator()(node a,node b){
        return a.ptr->data>b.ptr->data;
    }};
class Solution{
  public:
    //Function to merge K sorted linked list.
    
    
    Node * mergeKLists(Node *arr[], int k)
    {
        if(k==0){
            return NULL;
        }
        Node* head,*tail;
        head=tail=NULL;
        priority_queue<node,vector<node>,compare>heap;
        vector<Node*>p(k);
        for(int i=0;i<k;i++){
            p[i]=arr[i];
            if(p[i]!=NULL){
                node curr;
                curr.ptr=p[i];
                curr.idx=i;
                heap.push(curr);
                
            }
        }
        while(!heap.empty()){
            auto p=heap.top();
            heap.pop();
            if(head==NULL && tail==NULL){
                Node* temp=new Node(p.ptr->data);
                temp->next=NULL;
                head=temp;
            }
            else if(tail==NULL){
                Node* temp=new Node(p.ptr->data);
                temp->next=NULL;
                head->next=temp;
                tail=temp;
            }
            else{
                Node* temp=new Node(p.ptr->data);
                temp->next=NULL;
                tail->next=temp;
                tail=temp;
            }
            if(p.ptr->next!=NULL){
                node curr;
                curr.ptr=p.ptr->next;
                curr.idx=p.idx;
                heap.push(curr);
            }
        }
        return head;
    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
  // } Driver Code Ends