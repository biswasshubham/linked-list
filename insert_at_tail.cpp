#include<iostream>
using namespace std ;
class Node
{
    public :
    int data ;
    Node * next ; //iska mtlb ek pointer hai joh ki next address ko print kr rha hai 

    //constructor 
    Node(int data)
    {
        this -> data = data ;
        this -> next = NULL ;
    }
};

//function for tail
void insertattail(int data , Node*  &tail)
{
    //create a new node with a name of temp 
    Node * temp = new Node (data) ; 
    tail -> next = temp ;
    tail = temp ; 
   
};

void print(Node * & head)
{
    Node * temp = head ;//new node created which is pointing on head 

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp ->next ;
    } 
    
};

int main()
{
    //create a node 
    Node * n1 = new Node(10) ;
    
    cout<<n1->data<<endl;
    // cout<<n1->next<<endl;

    //tail pointing to head 
    //create a new node 
    Node* tail =  n1 ;
    insertattail (20 , tail);
    print(tail) ;
    insertattail (30 , tail);
    print(tail) ;
    insertattail (40 , tail);
    print(tail) ;
}