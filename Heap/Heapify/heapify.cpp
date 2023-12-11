#include <bits/stdc++.h>
using namespace std;

// Using the same logic as delete_from_heap
vector<int> heapify(vector<int> &arr)
{
    // If arr is empty or has only element it's already a heap
    if (arr.empty() || arr.size() == 1)
    {
        return arr;
    }

    // start with the last parent node
    int ind = (arr.size() / 2) - 1;

    // move upwards until the root
    while (ind >= 0)
    {
        int leftChildIndex = 2 * ind + 1;
        int rightChildIndex = 2 * ind + 2;

        int leftChild = (leftChildIndex < arr.size()) ? arr[leftChildIndex] : INT_MIN;
        int rightChild = (rightChildIndex < arr.size()) ? arr[rightChildIndex] : INT_MIN;

        // If both children are missing, decrement ind and continue
        if (leftChild == INT_MIN && rightChild == INT_MIN)
        {
            ind--;
            continue;
        }

        // If right child is missing, compare only with left child
        if (rightChild == INT_MIN)
        {
            if (arr[ind] < leftChild)
            {
                swap(arr[ind], arr[leftChildIndex]);
            }
            ind--;
            continue;
        }

        int swapIndex = (leftChild > rightChild) ? leftChildIndex : rightChildIndex;

        // Check if swapping is needed
        if (arr[ind] < arr[swapIndex])
        {
            swap(arr[ind], arr[swapIndex]);
            ind = swapIndex;
        }

        else
        {
            ind--;
        }
    }
    return arr;
}

int main()
{
    vector<int> arr = {10, 20, 15, 12, 40, 25, 18};

    vector<int> myArr = heapify(arr);

    for (const auto &element : myArr)
    {
        cout << element << " ";
    }

    return 0;
}
