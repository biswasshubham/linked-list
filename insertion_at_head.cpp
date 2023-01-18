#include<iostream>
using namespace std ; 
class Node
{
    public :
    int data ; // data 
    Node * next ; // address for nxt node 

    //parameterised constructor 
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL ;
    }

};

//function for insert at head
void insertathead(Node * &tail , int data)  
{
    //jbhi ek naya data ata hai usk liye ek naya node banana padega 

    //STEP-1
    //new node creation temp type
    Node * temp = new Node(data) ;

     //STEP-2
     //joh nai node create ki hai uska joh nxt vala joh hai voh abhi null hai ..
     //so voh null ko hata k hume head vale node pr pt. krna padega..
    temp -> next = tail ;
    
    //STEP - 3
    // joh mera head tha voh purane vale node pr point kr rha tha abhi usse temp vale node mh point krna hai.
    tail = temp; 

};

//printing linked list 
void print(Node * & head)
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
    //cretion of node 
    Node * n1 = new Node(10) ;
    cout<<"previously data :: "<<n1 ->data <<endl;
    cout<<" next mh abhi  padha hai ::"<<n1->next<<endl;

    //creation of node again for head which is poitning to n1 
    Node * head = n1 ;

    insertathead(head , 20);
    print(head) ;
    cout<<endl;
     insertathead(head , 30);
    print(head) ;
} 

