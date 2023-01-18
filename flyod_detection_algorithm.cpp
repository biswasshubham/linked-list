// FLYOD CYCLE DETECTION ALGORIHTM :-
//1.yani ki slow or fast sbhse phele head ko point karenge
//2.phir slow ko 1 step se aage badao 
//3.fatst ko 2 step se aage badao
//4.agar slow or fast milgaya toh yani ki cycle hai agar nai mile toh cycle nai hai
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertattail(Node *&tail, int data)
{
    Node *temp = new Node(data);

    tail->next = temp;
    tail = temp;
};

            // function for flyodDetectionCyclealgorithm
bool flyodDetectionCycle(Node *head)
{
    if (head == NULL)
    {
        return false; // head he null yani khali hai toh loop kaha se he hoga ...isliye false
    }
    // sbhse phele slow or fast dono ki hai head mh pt krva diya
    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        // abhi fast ko 2 baar badana hai yani ki 2 steps ..
        // or slow ko 1 baar badana hai yani ki single step ..
        fast = fast->next->next; //fast = 2 steps 
        slow = slow->next; // slow = 1 step 

        if (slow == fast)
        {
            cout << "prsent at " << slow->data << endl; // dono slow n fast ki pt mh meet kr rhe hai
            return true; // yani ki loop toh hai bhai..
        }
    }
    return false; // loop he nai hai
};

void print(Node *&head)
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
    Node *head = new Node(10);

    Node *tail = head;
    insertattail(tail, 12);

    insertattail(tail, 15);

    insertattail(tail, 22);

    print(head);

    cout << endl;
    
     tail ->next = head ->next ;
    if (flyodDetectionCycle(head))
    {
        cout << "cycle is present" << endl;
    }
    else
    {
        cout << "cycle is not present" << endl;
    }

   

}