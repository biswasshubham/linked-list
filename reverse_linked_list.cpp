#include<iostream>
using namespace std ;
class Node
{
    public :
    int data ;
    Node * next ;
    
    Node(int data  )
    {
       this -> data = data ;
       this -> next = NULL ;
       
    }
};

void insertinghead(int data , Node * &head)
{
    Node * temp = new Node(data) ;
    
    temp -> next = head ;
    head = temp ;
};



Node* reverselinkedlist(Node * &tail)
{
        Node * previous = NULL ;
        Node * current = tail ;
        Node * forward = NULL ;
        
        while(current != NULL )
        {   
            forward = current -> next ;
            current -> next = previous ;
            previous = current ;
            current = forward ;
        }
        tail = previous ;
       
}


void print(Node * & tail)
{
    Node * temp = tail ; 

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp ->next ;
    } 
    
};


int main()
{
    Node * practice = new Node(10) ;
    
    cout<<practice -> data<<endl;    //10
    cout<<practice -> next <<endl;
    
    //HEAD
    Node * head = new Node(20) ;

    insertinghead(30 , head);
    print(head) ;
    cout<<endl;
   
    
    insertinghead(40 , head);
    print(head) ; 
     cout<<endl;
    
    insertinghead(50 , head);
    print(head) ;
     cout<<endl;
     
    cout<<"before reverse head is ::"<<head -> data <<endl;

    cout<<"REVERSE LINKED LIST IS::"<<endl;
    
    Node * reverse = head ;
    reverselinkedlist(head) ;
    
    print (head);
    cout<<endl;
    cout<<"after reverse head is ::"<<head -> data <<endl;//bcoz now previous value is change ..
                                                           // head = previous  
    
}