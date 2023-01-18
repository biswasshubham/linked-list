    // REMOVE DUPLICATES IN AN SORTED ORDER 
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

Node* removeDuplicates(Node * &head)
{
    //empty list
    if(head == NULL)
    {
        return NULL ;
    }

    //non-empty list
    Node* current = head ;

    while(current != NULL )
    {
        //WHEN CURRENT ELEMENT N ITS NEXT IS SAME (EQUAL)
        if( (current->next!=NULL) && current->data == current->next->data) //current->next->data dis means ki aagle vala
        {
            Node * next_next = current->next->next ;
            Node * nodetodelete = current->next;
            delete(nodetodelete) ;
            current->next = next_next ;
        }
        else  //WHEN CURRENT ELEMENT N ITS NEXT IS NOT SAME (!=)
        {
            current = current->next ;
        }
    } 
   return head ;

};

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
    Node* head = new Node(1) ;

    Node * tail = head ;

    insertattail(tail , 2) ;

    insertattail(tail , 2) ;

    insertattail(tail , 3) ;

    insertattail(tail , 4) ;

    print(head) ;
    cout<<"\n";
    cout<<"remove duplicates in an sorted order::"<<endl;
    removeDuplicates(head) ;
    print(head) ;

}