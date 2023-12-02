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

// Delte Head
Node* deleteHead(Node* head)
{
    if(head == NULL || head->next == NULL) return NULL;
    
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
    if (head == nullptr || head->next == nullptr) return nullptr;

    Node *tail = head;

    while(tail->next != NULL)
    {
        tail = tail->next;
    }

    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    delete tail;
    
    return head;
}

// Delete Kth Node
Node* deleteKthNode(Node* head, int k)
{
    if(head == NULL) return NULL;

    int cnt = 0;
    Node* temp = head;

    while(temp != NULL)
    {
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* front = temp->next;

    if(prev == NULL && front == NULL)
    {
        return NULL;
    }

    else if(prev == NULL)
    {
        return deleteHead(head);
    }

    else if(front == NULL)
    {
        return deleteTail(head);
    }

    prev->next = front;
    front->back = prev;
    
    temp->next = nullptr;
    temp->back = nullptr;

    delete temp;

    return head;
}

// Delete Node
void deleteNode(Node* temp)
{
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == NULL)
    {
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }

    prev->next = front;
    front->back = prev;

    temp->next = temp->back = nullptr;
    free(temp);
}

// Insertion before head
Node* insertBeforeHead(Node* head, int val)
{
   Node* newHead = new Node(val, head, nullptr);
   head->back = newHead;

   return newHead; 
}

// Insertion before tail
Node* insertBeforeTail(Node* head, int val)
{
    if(head->next == NULL) return insertBeforeHead(head, val);

    Node* tail = head;

    while(tail->next != NULL)
    {
        tail = tail->next;
    }

    Node* prev = tail->back;
    Node* newNode = new Node(val, tail, nullptr);
    prev->next = newNode;
    tail->back = newNode;

    return  head;
}

// Insertion before Kth Node
Node* insertBeforKthNode(Node* head, int k, int val)
{
    if(k == 1) return insertBeforeHead(head, val);

    Node* temp = head;
    int cnt = 0;

    while (temp != NULL)
    {
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;

    return head;
}

// Insert before node
void insertBeforeNode(Node* node, int val)
{
    Node* prev = node->back;
    Node* newNode = new Node(val, node, prev);
    prev->next = newNode;
    node->back = newNode;
}


// Reverse a doubly LL
Node* reverseDLL(Node* head)
{
    if(head == NULL || head->next == NULL) return head;

    Node* prev = NULL;
    Node* current = head;

    while (current != NULL)
    {
        prev = current->back;
        current->back = current->next;
        current->next = prev;
        current = current->back;
    }
    return prev->back;
}

int main()
{
    vector<int> arr = {12, 5, 8, 7};
    Node *head = convert2DLL(arr);

    insertBeforeNode(head->next->next, 100);
    print(head);

    return 0;
}