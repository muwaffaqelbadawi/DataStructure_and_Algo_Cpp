#include<bits/stdc++.h>
using namespace std;

// Creation of Max Heap
vector<int> createMaxHeap(const vector<int> &arr)
{
    // Initialize heap array
    vector<int> heapArr;

    // Reserve memory for heapArr to avoid unnecessary reallocations
    heapArr.reserve(arr.size());

    // If arr is empty return empty heapArr
    if(arr.empty()) return heapArr;


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

        while(ind > 0)
        {
            // 0-based indexing
            if(heapArr[ind] > heapArr[(ind-1)/2])
            {
                swap(heapArr[ind], heapArr[(ind-1)/2]);
                ind = (ind-1)/2;
            }
            else break;
        }
    }
    return heapArr;
}

int measureHeapHeight(const vector<int> &heap)
{
    // If the heap is empty, return height 0
    if (heap.empty())
    {
        return 0;
    }

    // Initializing height
    int height = 0;

    // Starting from the root (index 0) and going downwards
    int ind = 0;

    while (ind < heap.size())
    {
        height++;

        // Move to the left child (0-based index)
        ind = 2 * (ind + 1);
    }
    return height;
}

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

    int ind = 0;
    int parent = heap[ind];
    int leftChild = heap[2 * (ind + 1)];
    int rightChild = heap[2 * (ind + 2)];
    int heapHeight = measureHeapHeight(heap);
    int secondLastLevel = pow(2, heapHeight) / 2;

    while (max(leftChild, rightChild) > parent && ind <= secondLastLevel)
    {
        if(leftChild > parent)
        {
            swap(parent, leftChild);
        }

        else
        {
            swap(parent, rightChild);
        }

        ind = 2 * (ind + 1);
    }
    return heap;
}


int main()
{
    vector<int> arr = {10, 20, 15, 30, 40};

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