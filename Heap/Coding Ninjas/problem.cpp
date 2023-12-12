#include <bits/stdc++.h>
using namespace std;

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
            {
                break;
            }
        }
    }
    return heapArr;
}

// Creation of Max Heap
vector<int> createMinHeap(const vector<int> &arr)
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
            if (heapArr[ind] < heapArr[(ind - 1) / 2])
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

int deleteFromHeap(vector<int> &heap, int n, int k)
{
    // If arr is empty return empty heapArr
    if (heap.empty())
    {
        return heap[0];
    }

    // If there's only one element delete it and return the empty vector
    if (n == 1)
    {
        // Remove the root
        heap.erase(heap.begin());
        return heap[0];
    }

    for (int i = 0; i < k - 1; i++)
    {
        // last element (deepest leaf of the heap) becomes the root
        heap[0] = heap[n - 1];

        // Remove last element (deepest leaf of the heap)
        heap.pop_back();

        // Index of the root
        int ind = 0;
        int lastParentNode = (n / 2) - 1;

        while (ind <= lastParentNode)
        {
            int leftChildIndex = 2 * ind + 1;
            int rightChildIndex = 2 * ind + 2;

            int leftChild = (leftChildIndex < n) ? heap[leftChildIndex] : INT_MIN;
            int rightChild = (rightChildIndex < n) ? heap[rightChildIndex] : INT_MIN;

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
    }
    return heap[0];
}

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    vector<int> maxHeap = createMaxHeap(arr);
    vector<int> minHeap = createMinHeap(arr);

    int KthLargestEl = deleteFromHeap(maxHeap, n, k);
    int KthSmallestEl = deleteFromHeap(minHeap, n, k);

    return {KthLargestEl, KthSmallestEl};
}

int main()
{
    vector<int> arr = {5, 6, 7, 2};

    vector<int> myHeap = createMaxHeap(arr);

    vector<int> smallLarge = kthSmallLarge(myHeap, 4, 3);

    for (const auto &element : smallLarge)
    {
        cout << element << " ";
    }

    return 0;
}