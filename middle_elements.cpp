    //APPROACH 2 
#include<iostream>
using namespace std ; 
class Node
{
    public :
    int data ;
    Node * next ;

    Node(int data)
    {
        this->data = data ;
        this ->next = NULL ;
    }
};

void insertattail(Node * &tail , int data)
{
    Node * temp = new Node(data) ;

    tail -> next = temp ;
    tail  = temp  ;
} ;

//approach -2 
Node * middle(Node * &head)
{
    if(head == NULL || head->next == NULL)
    return head ;
    
    if(head->next->next == NULL)
    return head->next ;
    
     Node* slow = head ;
    Node * fast = head->next;
   
    while(fast != NULL)
    {
        fast = fast ->next ;

        if(fast != NULL)
        {
            fast = fast ->next ;
        }
        slow = slow->next ;
    }
    return slow ;
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
    Node * head = new Node(13); 
    Node * tail  = head ;

    insertattail(tail , 372) ;

    insertattail(tail  ,43) ;

    insertattail(tail  ,64) ;

    insertattail(tail  ,464) ;

    print(head) ;

    cout<<middle(head)->data<<endl;
}