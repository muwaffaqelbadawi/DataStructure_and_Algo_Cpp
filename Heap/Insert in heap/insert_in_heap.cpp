#include<bits/stdc++.h>
using namespace std;

// Creation of Max Heap
vector<int> createMaxHeap(const vector<int> &arr)
{
    // Initialize heap array
    vector<int> myHeap;

    // Reserve memory for myHeap to avoid unnecessary reallocations
    myHeap.reserve(arr.size());

    // If arr is empty return empty myHeap
    if(arr.empty()) return myHeap;

    // If there's only one element it considers Max Heap and Min Heap
    if (arr.size() == 1)
    {
        myHeap.push_back(arr[0]);
        return myHeap;
    }
    
    // Insert the first element
    myHeap.push_back(arr[0]);

    // push all elements to myHeap and maintaining the Heap property
    for (int i = 1; i < arr.size(); i++)
    {
        myHeap.push_back(arr[i]);

        // Keep track of the last element
        int ind = myHeap.size() - 1;

        while(ind > 0)
        {
            // 0-based indexing
            if(myHeap[ind] > myHeap[(ind-1)/2])
            {
                swap(myHeap[ind], myHeap[(ind-1)/2]);
                ind = (ind-1)/2;
            }
            else break;
        }
    }
    return myHeap;
}

// Insert in Max Heap (work for both max and min you should change the sigh)
vector<int> insertInHeap(vector<int> myHeap, int el)
{
    // Insert the element
    myHeap.push_back(el);

    // Keep track of the element
    int ind = myHeap.size() - 1;

    while (ind > 0)
    {
        // 0-based indexing
        if (myHeap[ind] > myHeap[(ind - 1) / 2])
        {
            swap(myHeap[ind], myHeap[(ind - 1) / 2]);
            ind = (ind - 1) / 2;
        }
        else break;
    }
    return myHeap;
}


int main()
{
    int el;
    cin >> el;

    vector<int> arr = {10, 20, 15, 30, 40};

    vector<int> myHeap = createMaxHeap(arr);

    const vector<int> &myNewHeap = insertInHeap(myHeap, el);

    for (const auto &element : myNewHeap)
    {
        cout << element << " ";
    }

    return 0;
}