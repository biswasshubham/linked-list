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
        this->next=NULL;
    }
};

void insertattail(Node * &tail , int data)
{
    Node * temp = new Node(data) ;
    tail->next=temp ;
    tail = temp ;
};

Node* removeDupliactes(Node* &head)
{
    //if the list is empty
    if(head == NULL)
    return NULL ;

    Node * current = head ;

    while(current != NULL && current->next == NULL)
    {
        Node * temp = current->next ;

        while (temp != NULL)
        {
           if(current->data == temp->data)
           {    
              temp = temp->next ;  
               Node * nodetodelete = current->next;
               delete(nodetodelete) ;
           }
           else
            {
                current = current->next ;
            }
        
        }
    
    }
    return head ;
} ;

void print(Node * &head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next; 
    }
};

int main()
{
    Node* head = new Node(10) ;

    Node * tail = head ;

    insertattail(tail , 2) ;

    insertattail(tail , 2) ;

    insertattail(tail , 13) ;

    insertattail(tail , 4) ;

    print(head) ;

    removeDupliactes(head) ;
    print(head) ;
}