#include <bits/stdc++.h>
using namespace std;


// Heap sort is combination of insertion and deletion

// Creation of Max Heap
vector<int> createMaxHeap(const vector<int> &arr)
{
    // Initialize heap array
    vector<int> heapArr;

    // Reserve memory for heapArr to avoid unnecessary reallocations
    heapArr.reserve(arr.size());

    // If arr is empty return empty heapArr
    if (arr.empty())
    {
        return heapArr;
    }

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
            // 0-based index
            if (heapArr[ind] > heapArr[(ind - 1) / 2])
            {
                swap(heapArr[ind], heapArr[(ind - 1) / 2]);
                ind = (ind - 1) / 2;
            }
            else
            {
                break;
            }
        }
    }
    return heapArr;
}

// Sort Heap
vector<int> sortHeap(vector<int> heap)
{
    // If heap is empty or has only element it's already a sorted Heap
    if (heap.empty() || heap.size() == 1)
    {
        return heap;
    }

    // Initial unsorted Heap size = n
    int heapSize = heap.size() - 1;

    while (heapSize >= 1)
    {
        // Maintain a copy of unsorted Heap root
        int temp = heap[0];

        // Last element of unsorted Heap becomes the root
        heap[0] = heap[heapSize];

        // Index of unsorted Heap root
        int ind = 0;

        // Last parent of unsorted Heap
        int lastParentNode = (heapSize / 2) - 1;

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
        
        // Add unsorted Heap root to the sorted Heap
        heap[heapSize] = temp;

        // Decrease the size of unsorted Heap
        --heapSize;
    }
    return heap;
}



int main()
{
    vector<int> arr = {10, 20, 15, 30, 40};

    vector<int> myHeap = createMaxHeap(arr);
    vector<int> mySortedHeap = sortHeap(myHeap);

    for (const auto &element : mySortedHeap)
    {
        cout << element << " ";
    }

    return 0;
}