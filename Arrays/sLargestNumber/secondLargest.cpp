#include <bits/stdc++.h>
using namespace std;

int SecondLargest(vector<int> &arr)
{
    int largest = arr[0];
    int slargest = -1;
    for (int i = 1; i <= arr.size() - 1; i++)
    {
        if (arr[i] > largest)
        {
            slargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > slargest && arr[i] < largest)
        {
            slargest = arr[i];
        }
    }
    return slargest;
}
int SecondSmallest(vector<int> &arr)
{
    int smallest = arr[0];
    int ssmallest = INT_MAX;

    for (int i = 1; i <= arr.size() - 1; i++)
    {
        if (arr[i] < smallest)
        {
            ssmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] != smallest && arr[i] < ssmallest) {
            ssmallest = arr[i];
        }
    }
    return ssmallest;
}

int main()
{
    int n;
    vector<int> arr;

    while (cin >> n)
    {
        arr.push_back(n);
    }

    int slargest = SecondLargest(arr);
    cout << slargest;

    return 0;
}
