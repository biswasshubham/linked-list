#include<iostream>
using namespace std ;
class Node 
{
    public :
    int data ;
    Node * next ;

    Node(int data)
    {
        this->data=data;
        this->next=NULL ;
    }
};

void insertattail(Node * &tail , int data)
{
    Node * temp = new Node(data) ;

    tail -> next = temp ;
    tail = temp ;
};
    //reverse ll function 
Node * reverse(Node * &head)
{
    Node * previous = NULL ;
    Node * current = head ;
    Node * forward = NULL ;

    while(current != NULL)
    {
        forward = current->next;

        current->next = previous ;
        previous = current ;
        current =  forward ; 
    }
    head = previous ;
    return head ;
};

//middle function
int getlen(Node * head)
{
     int length = 0 ;

     while(head != NULL)
     {
        length ++ ;
        head = head->next ;
     }
     return length ;
};

Node * middle(Node * &head)
{
    int length = getlen(head) ; 
    //int ans = (length / 2) + 1 ; // for position 
    int ans = (length / 2)  ; //for the number at that position
    
    Node * temp = head ;
    int cnt = 0 ;
    while(cnt < ans)
    {
        temp = temp ->next ;
        cnt ++ ;
    }
    return temp ;
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

int main()
{
    Node* head = new Node(13) ;
    
    Node * tail = head ;

    insertattail(tail , 372) ;

    insertattail(tail , 43) ;

    insertattail(tail , 64) ;

     insertattail(tail , 464) ;

    print(head);

    cout<<endl;
    cout<<"revrerse linked list is ::"<<endl;
    reverse(head) ;
    print(head) ; 
    
    cout<<endl;
 
  //  cout<<"middle element present at position:"<<middle(head)<<endl;

     cout<<middle(head)->data ;
    

}