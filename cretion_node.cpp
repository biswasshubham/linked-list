#include <iostream>
using namespace std;

class Node
{
    // creation of NODE

public:
    int data;
    Node *next; // created node with a name of next -->which will indicate next address.

    // PARAMETERISED CONSTRUCTOR -- to i/p values
    Node(int data) // jaise he line no.24 call hoga voh direct line no.13 pr aayega phir jake sare line no.14 k process krna k bhad voh line n.26 aayega
    {
        this->data = data;
        this->next = NULL;
    }
};

int main()
{
    // creating a object heap type

    Node *n1 = new Node(10);      // here new keywrd stores address
    cout << n1 << endl;           // address
    cout << new Node(10) << endl; // address

    cout << n1->data << endl; // '->' this sign bcoz it is a type of ptr .
    cout << n1->next << endl;
}