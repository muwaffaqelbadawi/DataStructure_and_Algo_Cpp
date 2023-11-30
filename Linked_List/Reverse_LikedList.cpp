#include <bits/stdc++.h>;
using namespace std;

// Introduction to Linked List


// Creating a Node class
class Node
{
public:
    int data;
    Node *next;

// Constructor with both data and next node 
public:
    Node(int data1, Node* next1)
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
Node* convert2LL(vector<int> &arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1; i<arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
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

// Print the length of a LL
int lengthOfLL(Node* head)
{
    int cnt = 0;
    Node *temp = head;

    while (temp)
    {
        temp = temp->next;
        cnt++;
    }

    return cnt;
}

// Search for item in a LL
int searchItem(Node* head, int k)
{
    Node* temp = head;

    while(temp)
    {
        if(temp->data == k) return 1;
        temp = temp->next;
    }
    return 0;
}

// Delete a head of a LL
Node* deleteHead(Node* head)
{
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

// Delete a tale of a LL
Node* deleteTale(Node* head)
{
    if(head == NULL || head->next == NULL) return NULL;

    Node* temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    return  head;
}

// Delete a Kth Node element (0-based indexing)
Node *deleteNode(Node *head, int k)
{
    if (head == NULL) return head;

    if (k == 0)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    int cnt = 0;
    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        cnt++;

        if (cnt == k + 1)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// Delete an element
Node *deleteEl(Node *head, int el)
{
    if (head == NULL) return head;

    if (head->data == el)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->data == el)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// Insert at head
Node* insertHead(Node* head, int val)
{
    Node* temp = new Node(val, head);
    return temp;
}

// Insert at tail
Node* insertTale(Node* head, int val)
{
    if(head == NULL) return new Node(val);

    Node* temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    Node* newNode = new Node(val);
    temp->next = newNode;
    
    return head;
}


// Insert before Kth position
Node* insertPos(Node* head, int el, int k)
{
    if(head == NULL)
    {
        if(k == 1) return new Node(el);
        else return head;
    }

    if(k == 1) return new Node(el, head);
    
    int cnt = 0;
    Node* temp = head;

    while(temp != NULL)
    {
        cnt++;
        if(cnt == k-1)
        {
            Node *x = new Node(el, temp->next);
            temp->next = x;
            break;
        }

        temp = temp->next;
    }
    return head;
}

// Insert before element
Node* insertBeforeEl(Node* head, int el, int val)
{
    if (head == NULL) return NULL;

    if (head->data == val) return new Node(el, head);

    Node *temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->data == val)
        {
            Node *x = new Node(el, temp->next);
            temp->next = x;
            break;
        }

        temp = temp->next;
    }
    return head;
}




int main()
{
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convert2LL(arr);

    head = insertBeforeEl(head, 100, 7);
    print(head);
}
