#include <bits/stdc++.h>;
using namespace std;

// Introduction to Linked List
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// TC ---> O(N)
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

int lengthOfLL(Node* head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int main()
{
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convert2LL(arr);
    Node* temp = head;

    while(temp)
    {
        cout << lengthOfLL(head);
        // cout << temp->data << " ";
        // temp = temp->next;
    }
}





/*
// Reverse a linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {

        // step 1
        ListNode *prev_p = NULL;
        ListNode *current_p = head;
        ListNode *next_p;

        // step 2
        while (current_p)
        {
            next_p = next_p->next;
            current_p->next = prev_p;

            prev_p = current_p;
            current_p = next_p;
        }

        // step 3
        head = prev_p;
        return head;
    }
};

// Implement Queue using Stacks - leetcode
class MyQueue
{
public:
    // push element in queue
    void push(int x)
    {
        // Pop out all elements from the stack input
        while (!input.empty())
        {
            output.push(input.top());
            input.pop();
        }

        // Insert the desired element in the stack input
        cout << "The element pushed is " << x << endl;
        input.push(x);

        // Pop out elements from the stack output and push them into the stack input
        while (!output.empty())
        {
            input.push(output.top());
            output.pop();
        }
    }

    // Pop the element from the Queue
    int pop()
    {
        if (input.empty())
        {
            cout << "Stack is empty";
            exit(0);
        }
        int val = input.top();
        input.pop();
        return val;
    }

    // Return the Topmost element from the Queue
    int peek()
    {
        if (input.empty())
        {
            cout << "Stack is empty";
            exit(0);
        }
        return input.top();
    }

    bool empty()
    {
        return input.empty();
    }

private:
    stack<int> input, output;
};

// Implement Stack using Queues

*/





