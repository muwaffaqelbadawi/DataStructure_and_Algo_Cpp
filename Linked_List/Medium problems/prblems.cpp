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

// Adding 2 numbers in LL
Node *Adding2NumbersLL(Node *head, int n1, int n2)
{

    return head;
}




int main()
{
    vector<int> arr = {12, 5, 8, 7};


    /* Node *head = convert2DLL(arr);

    insertBeforeNode(head->next->next, 100);
    print(head); */

    return 0;
}