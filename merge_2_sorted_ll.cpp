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

// Node* removeDuplicates(Node * &head)
// {
//     Node * current = head ;

//     while (current != NULL)
//     {
//        if( (current->next!=NULL) && current->data == current->next->data)
//        {
//         Node * next_next = current->next->next ;
//         Node * nodetodelete = current->next ;
//         delete(nodetodelete) ;
//         current->next=next_next;
//        }
//        else{
//         current = current->next ;
//        }
//     }
//     return head ;
// };
Node* removeDuplicates(Node* &head)
{
    //if the list is empty
   if(head==NULL)return NULL;
        Node*curr=head;
        while(curr!=NULL && curr->next!=NULL)
        {
            if((curr->data==curr->next->data))
            {
                Node*forward=curr->next->next;
                Node*to_be_deleted=curr->next;
                delete(to_be_deleted);
                curr->next=forward;;
            }
            else{
                curr=curr->next;
            }
        }
        return head;
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

    insertattail(tail , 15) ;

    insertattail(tail , 15) ;

    insertattail(tail , 18) ;

    insertattail(tail , 23) ;

    insertattail(tail , 18) ;

    print(head);
    cout<<endl;
    removeDuplicates(head) ;
    print(head) ;
    
}