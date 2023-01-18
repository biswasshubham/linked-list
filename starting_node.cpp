                                // STARTING NODE 
//
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
            cout << "meeting pt of the nos.is::" << slow->data << endl; // dono slow n fast ki pt mh meet kr rhe hai
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

    // joh phele meet hua tha usse pt of intersection boldiya (meeting pt.)
    Node* ptofintersection = flyodDetectionCycle(head) ;

    //after meeting bth the pts . placing slow to head again 
    Node* slow = head ;

    while(slow != ptofintersection) //jbh thk slow == ptofintersection nai ho jata tbh thk loop chalate rhe
    {
        slow = slow ->next ; //slow ko aage badaya
        ptofintersection = ptofintersection -> next ;//pt of intersection ko aage badaya
    }
    return slow  ; //yani ki mil gaya starting node 
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
}