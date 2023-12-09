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
    if(arr.empty())
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

        while(ind > 0)
        {
            // 0-based index
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

// The height is defined as the length of the longest path from the root to a leaf.
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

    // 0-based index
    while (ind < heap.size())
    {
        height++;

        // Move to the left child
        ind = 2 * (ind + 1);
    }
    return height;
}


int main()
{
    vector<int> arr = {10, 20, 15, 30, 40};

    vector<int> myHeap = createMaxHeap(arr);

    for (const auto &element : myHeap)
    {
        cout << element << " ";
    }

    int heapHight = measureHeapHeight(myHeap);

    cout << endl << heapHight;

    return 0;
}