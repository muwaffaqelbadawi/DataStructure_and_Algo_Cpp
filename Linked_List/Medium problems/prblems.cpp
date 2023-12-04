#include <bits/stdc++.h>;
using namespace std;

// Creating a Node class
class Node
{
public:
    int data;
    Node *next;

    // Constructor with both data and next node
public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    // Constructor with only data (assuming next is initially null)
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// convert a list to Linked List
Node *convert2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// Print all the nodes
Node *print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Adding 2 numbers in LL
Node *Adding2NumbersLL(Node *head1, Node* head2)
{
    Node *dummyNode = new Node(-1);
    Node *curr = dummyNode;

    Node* t1 = head1;
    Node* t2 = head2;

    int carry = 0;

    while (t1 != NULL || t2 != NULL)
    {
        int sum = carry;

        if(t1) sum += t1->data;
        if(t2) sum += t2->data;

        carry = sum / 10;

        Node *newNode = new Node(sum % 10);

        curr->next = newNode;
        curr = curr->next;

        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next;
    }

    if(carry)
    {
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummyNode->next;
}






int main()
{
    vector<int> arr1 = {4, 3, 2, 1};
    vector<int> arr2 = {8, 7, 6, 5};

    Node *head1 = convert2LL(arr1);
    Node *head2 = convert2LL(arr2);

    Node* head = Adding2NumbersLL(head1, head2);
    print(head);

    return 0;
}