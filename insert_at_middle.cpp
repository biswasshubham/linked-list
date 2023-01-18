#include<iostream>
using namespace std ;
 //creation of node 
class Node
{  
    public:
    int data ;
    Node * nxt ;

    //CONSTRUCTOR 
    Node(int data)
    {
        this ->data = data ;
        this ->nxt = NULL;
    }
};

void insertatmiddle(Node * middle , int position , int data )
{
    //STEP-1 TRAVERSE 
    Node * temp = middle ;
    int count = 1;
    
    while (count < position - 1 )
    {
        temp = temp ->nxt ;
        count ++ ;
    }
    
    //STEP -2 
    //new node crested which will b getting insert in btw 
    Node * nodetoinsert = new Node(data) ;
    nodetoinsert->nxt =  temp->nxt ; 
    temp->nxt = nodetoinsert ;

};

void print(Node * & middle)
{
    Node * temp = middle ;//new node created which is pointing on head 

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp ->nxt ;
    } 
    
};

int main()
{
    Node * n1 = new Node(10) ;
    cout<<n1->data<<endl;
    cout<<n1->nxt<<endl;

    Node * middle = n1 ;
    insertatmiddle(middle ,2 ,22 );
   print (middle);
}