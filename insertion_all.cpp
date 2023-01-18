//inserton 
#include<iostream>
using namespace std ; 

//creating Node 
class Node
{
    public :
    int data ;
    Node * next ;
    
    //data dalneki koshish by using parameterized constructor 
    Node (int data )
    {
        this -> data = data ;
        this -> next = NULL ;
    }
    
};

//inserton head funtion
void insertonhead(int data , Node * head )
{
    Node * temp = new Node (data) ;//new data new node 
    
    temp -> next = head ;
    head = temp ;
}

//insertion tail function
void insertontail(int data , Node * tail)
{
    Node * temp = new Node (data);//new data new node 
    
    tail -> next = temp ;
    temp = tail ;
}

//insertion on middle
void insertiononmiddle(int position , int data , Node * middle)
{
    Node * temp = middle ;//new data new node
    int count = 1 ;
    
    while(count < position)
    {
        temp = temp -> next ; //middle++ (middle ko aage kiya)
        count ++ ;
    }
    
    Node * nodetobinsert = new Node (data) ;
    nodetobinsert -> next = temp -> next ;
    temp -> next = nodetobinsert ;
    
}

//printing 
void print(Node *  head)
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
    //creating new node 
    Node * node1 = new Node(100) ;
    
    //joh data dala hai usse print krne ki koshish
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;
    
    //insert on head 
    Node * head = node1 ;
    insertonhead(10 , head) ;
    print (head) ;
    cout<<endl;
    cout<<"the element present at head is "<<head->data<<endl;
    cout<<endl;
    
    //insert on tail 
    Node * tail = node1 ;
    insertontail(200 , tail);
    print(head);
    cout<<endl;
    //cout<<"the element present at tail is "<<tail->data<<endl;
    cout<<endl;
    
    //insert on middle 
    Node * middle = node1 ;
    insertiononmiddle(1 , 22 , middle) ;
    print(head) ;
   // cout<<"the element present at middle is "<<middle->data<<endl;
    
    
    
}