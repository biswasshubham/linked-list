#include<iostream>
#include<map>
using namespace std ;
class Node 
{
    public :
    int data ;
    Node * next ;

    Node(int data)
    {
        this -> data = data ;
        this -> next = NULL ;
    }
};

void insertattail(Node* &tail , int data)
{
    Node * temp = new Node(data) ;

    tail -> next = temp ;
    tail  = temp ;
};

bool detectCycle(Node * head)
{   
    if(head == NULL)
    {
        return false ;
    }

    //map creation
    map <Node* , bool > visited ; //sare nos k liye true denote krliya 
    Node * temp1 = head ;

    while(temp1 != NULL)
    {   //cycle is present
        if(visited[temp1] == true ) //yani ki phele se he koi element true mark kiya hua hai 
        {   
            cout<<"cycle is present on data "<<temp1->data<<endl;
            return true ;
        }
        //agar koi element true mark nai kiya hai
        visited[temp1] = true ; //sare ko elements ko true mark kr rha hu
        temp1 = temp1 ->next ;  //temp ko aage bada liya
    }
    return false ; //agar cycle present nai HAI TOH 


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
    Node * n1 = new Node(10) ;

    //insert head
    Node* head = n1 ;
    Node * tail = n1 ;
    insertattail(tail , 12) ;

    insertattail (tail , 15) ;

    insertattail (tail , 22) ;

    
    print(head);

    tail -> next = head ->next ; //cycle present hone k liye kiya 

    cout<<endl;
    if(detectCycle(head))
    {
        cout<<"cycle is present"<<endl;
    } 
    else{
        cout<<"cycle is not present"<<endl;
    }
}