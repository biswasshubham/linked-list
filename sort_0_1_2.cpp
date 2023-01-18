#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node * next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertattail(Node *&tail, int data)
{
    Node *temp = new Node(data) ;

    tail->next = temp;
    tail = temp ;
};

Node* sortlist (Node* &head) 
{   
    //initialise all zeros 
    int zeroCount = 0 ;
    int oneCount = 0 ;
    int  twoCount = 0 ;

    Node * temp = head ;

    while(temp != NULL)
    {
        if(temp->data == 0)
        {
            zeroCount ++ ;
        }
        else if(temp->data == 1)
        {
            oneCount ++ ;
        }
        else if(temp->data == 2)
        {
            twoCount ++ ;
        }
        temp = temp->next ;
    }

    temp = head ;
      //DATA REPLACEMENT
    while(temp != NULL)
    {
        if(zeroCount != 0)
        {
            temp->data = 0 ;
            zeroCount -- ;
        }
        else if(oneCount != 1)
        {
            temp->data = 1 ;
            oneCount -- ;
        }
       else if(twoCount != 2)
        {
            temp->data = 2 ;
            twoCount -- ;
        }
        temp = temp->next ;
    }
    return head ;
};

void print(Node* head)
 {
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next; 
    }
 }
int main()
{
    Node *head = new Node(1);

    Node *tail = head;

    insertattail(tail, 0);

    insertattail(tail, 1);

    insertattail(tail, 2);

    insertattail(tail, 2);

    print(head) ;

    cout<<"SORT O's , 1's , 2's "<<endl;
    
    sortlist(head) ;
    print(head) ;

}