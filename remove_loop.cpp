// FLYOD CYCLE DETECTION ALGORIHTM
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
Node* flyodDetectionCycle(Node *head)
{
    if (head == NULL)
    {
        return NULL; // head he null yani khali hai toh loop kaha se he hoga ...isliye false
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
            //cout << "meeting pt of the nos.is::" << slow->data << endl; // dono slow n fast ki pt mh meet kr rhe hai
            return slow; // yani ki loop toh hai bhai..
        }
    }
    return NULL; // loop he nai hai
};

                // STARTING NODE OF THE LOOP
Node* getStartingNode(Node* head)
{
    if(head == NULL)
    {
        return NULL ;
    
    }

    Node* ptofintersection = flyodDetectionCycle(head) ;

    Node* slow = head ;

    while(slow != ptofintersection)
    {
        slow = slow ->next ;
        ptofintersection = ptofintersection -> next ;
    }
    return slow  ;
};

void removeLoop(Node* head)
{
    if(head == NULL)
    return ;

    Node * startloop = getStartingNode(head) ; //stroing starting node 
    Node* temp = startloop ; 

    while(temp->next != startloop) //jbh thk aagli node meri starting  node na ho tbh thk loop chalate jao
    {
        temp = temp ->next ; 
    }
    temp->next = NULL ;//jaise he start node mil gaya uss position ko hata k usse null define krdiya

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

    cout << endl;
    cout<<"STSRTING NODE "<<endl ;
    Node * loop = getStartingNode(head) ;
    cout<<"starting node of the loop is ::"<<loop -> data <<endl;

    cout << endl;
    cout<<"REMOVE LOOP "<<endl;

    removeLoop(head) ;
    print(head) ;
}