#include <bits/stdc++.h>
using namespace std;

void kth_Largest_MaxHeap(vector<int> &arr, int k)
{
    priority_queue<int> pq;
    int n = arr.size();

    for (int i = 0; i < arr.size(); i++)
    {
        pq.push(arr[i]);
    }

    int f = k - 1;

    while (f > 0)
    {
        pq.pop();
        f--;
    }

    cout << "Kth Largest element " << pq.top() << "\n";
}

void kth_Smallest_MinHeap(vector<int> &arr, int k)
{

    priority_queue<int, vector<int>, greater<int>> pq;
    int n = arr.size();

    for (int i = 0; i < arr.size(); i++)
    {
        pq.push(arr[i]);
    }

    int f = k - 1;

    while (f > 0)
    {
        pq.pop();
        f--;
    }

    cout << "Kth Smallest element " << pq.top() << "\n";
}

class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int len;

public:
    KthLargest(int k, vector<int> &nums)
    {
        len = k;

        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);

            if(k > pq.size())
            {
                pq.pop();
                
            }
        }
        
    }

    int add(int val)
    {
        pq.push(val);

        if (len > pq.size())
        {
            pq.pop();
        }

        return pq.top();
    }
       
};


int main()
{
    vector<int> arr = {1, 2, 6, 4, 5, 3};
    // 1 2 3 4 5 6

    // kth_Largest_MaxHeap(arr, 3); //4
    kth_Smallest_MinHeap(arr, 3); //3

    return 0;
}