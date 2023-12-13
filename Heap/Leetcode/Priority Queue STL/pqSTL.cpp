#include <bits/stdc++.h>
using namespace std;

int kthLargest(int *arr, int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
        
    while (--k)
    {
        pq.pop();
    }
        
    return pq.top();
}

int main()
{
    // vector<int> arr = {5, 6, 7, 2};

    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << kthLargest(arr, n, k);

    delete[] arr;

    return 0;
}