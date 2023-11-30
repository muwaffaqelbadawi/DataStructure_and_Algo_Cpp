#include <bits/stdc++.h>;
using namespace std;

// Creating a Node class
class Node
{
public:
    int data;
    Node *next;
    Node *back;

    // Constructor with both data and next node
public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

public:
    // Constructor with only data (assuming next is initially null)
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// convert a list to Linked List
Node *convert2DLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node* prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

// Print all the nodes
Node* print(Node* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* deleteHead(Node* head)
{
    if(head == nullptr || head->next == nullptr) return nullptr;
    
    Node* prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}

// Deletion of Tail
Node* deleteTail(Node* head)
{
    
}



int main()
{
    vector<int> arr = {12, 5, 8, 7};
    Node *head = convert2DLL(arr);

    head = deleteHead(head);
    print(head);

    return 0;
}