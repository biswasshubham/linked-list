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
void insertathead(Node* &head , int data)
{
    Node* temp = new Node(data) ;

    temp -> next = head ;
    head = temp ;
};

void insertattail(Node * &tail , int data)
{
    Node * temp = new Node(data) ;

    tail -> next = temp ;
    tail = temp ;
};

void print(Node * &head)
{
    Node * temp = head ; //new node created which is pointing on head 

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp ->next ;
    } 
};

int main()
{
    Node* head = new Node(3) ;
    
    insertathead(head , 2);

    insertathead(head , 1) ;

    print(head) ;

    Node * tail = head ;

    insertattail(tail , 4) ;

    insertattail(tail , 5) ;

    insertattail(tail , 6) ;

    print(head);


}