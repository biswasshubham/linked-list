#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this ->data = data ;
        this ->next = NULL ;
    }
};

void deleteNode (int position , int data , Node * dell)
{
    if(position == 1)
    {
        Node * temp = dell ;
    }



};

int main()
{
    Node * node1 = new Node(120) ;

    Node * dell = node1 ;

}