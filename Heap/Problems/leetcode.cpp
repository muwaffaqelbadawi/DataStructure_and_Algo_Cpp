#include <bits/stdc++.h>
using namespace std;

// Leetcode Problems
// 215. Kth Largest Element in an Array


// Creation of Max Heap
vector<int> createMaxHeap(const vector<int> &arr)
{
    // Initialize heap array
    vector<int> heapArr;

    // Reserve memory for heapArr to avoid unnecessary reallocations
    heapArr.reserve(arr.size());

    // If arr is empty return empty heapArr
    if (arr.empty())
        return heapArr;

    // If there's only one element it considers Max Heap or Min Heap
    if (arr.size() == 1)
    {
        heapArr.push_back(arr[0]);
        return heapArr;
    }

    // Insert the first element
    heapArr.push_back(arr[0]);

    // push all elements to myHeap and maintaining the Heap property
    for (int i = 1; i < arr.size(); i++)
    {
        heapArr.push_back(arr[i]);

        // Keep track of the last element
        int ind = heapArr.size() - 1;

        while (ind > 0)
        {
            // 0-based indexing
            if (heapArr[ind] > heapArr[(ind - 1) / 2])
            {
                swap(heapArr[ind], heapArr[(ind - 1) / 2]);
                ind = (ind - 1) / 2;
            }
            else
                break;
        }
    }
    return heapArr;
}

// Delete from a heap
vector<int> deleteFromHeap(vector<int> heap)
{
    // If arr is empty return empty heapArr
    if (heap.empty())
    {
        return heap;
    }

    // If there's only one element delete it and return the empty vector
    if (heap.size() == 1)
    {
        // Remove the root
        heap.erase(heap.begin());
        return heap;
    }

    // last element (deepest leaf of the heap) becomes the root
    heap[0] = heap[heap.size() - 1];

    // Remove last element (deepest leaf of the heap)
    heap.pop_back();

    // Index of the root
    int ind = 0;
    int lastParentNode = (heap.size() / 2) - 1;

    while (ind <= lastParentNode)
    {
        int leftChildIndex = 2 * ind + 1;
        int rightChildIndex = 2 * ind + 2;

        int leftChild = (leftChildIndex < heap.size()) ? heap[leftChildIndex] : INT_MIN;
        int rightChild = (rightChildIndex < heap.size()) ? heap[rightChildIndex] : INT_MIN;

        int swapIndex = (leftChild > rightChild) ? leftChildIndex : rightChildIndex;

        // Check if swapping is needed
        if (heap[ind] < heap[swapIndex])
        {
            swap(heap[ind], heap[swapIndex]);
            ind = swapIndex;
        }

        else
        {
            break;
        }
    }
    return heap;
}

int main()
{
    vector<int> arr = {50, 30, 20, 15, 10, 8, 16};

    vector<int> myHeap = createMaxHeap(arr);

    cout << "myHeap:" << endl;
    for (const auto &element : myHeap)
    {
        cout << element << " ";
    }

    cout << endl;

    const vector<int> &myNewHeap = deleteFromHeap(myHeap);

    cout << "myNewHeap:" << endl;
    for (const auto &element : myNewHeap)
    {

        cout << element << " ";
    }

    return 0;
}