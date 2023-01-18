#include<iostream>
using namespace std ;
class Node
{
    public :
    int data ;
    Node * next ;
    
    Node(int data)
    {
        this -> data = data ;
        this -> next = NULL ;
    }
};

void inserttail (Node * &tail , int data)
{
    Node * temp = new Node(data) ;
    
    tail -> next = temp ;
    tail = temp ;
    
};

void print(Node * &head)
{
    Node * temp = head ; 

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp ->next ;
    }   
};

Node* reversell(Node* head ,int k )
{   
    //base case
    if(head==NULL)
    {
        return NULL ;
    }
    
    Node * prev = NULL ;
    Node * curr = head ;
    Node * forward = NULL ;
    int cnt =0;
    
    while(curr != NULL)
    {   
        forward = curr -> next ;
        curr -> next = prev ;
        prev = curr ;
        curr = forward ;
       cnt ++;
    }
   
    
    if(forward != NULL)
    {
        head -> next = reversell( forward , k) ;
    }
    
     return prev ;
} ;



int main()
{   
    Node * head = new Node (10) ;
    Node* tail = head ;
   
    inserttail(tail , 20) ;
    
    inserttail(tail , 30) ;
    
    inserttail(tail , 40) ;
    print(head) ;
    cout<<endl;
    
    Node *reverse = reversell(head , 2 ) ; //k=2
    print(reverse) ;
    
    
}