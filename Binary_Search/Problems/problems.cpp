#include <bits/stdc++.h>
using namespace std;

// Floor and Ciel
int findFloor(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] <= x)
        {
            ans = arr[mid];
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
int findCeil(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            ans = arr[mid];
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    int f = findFloor(a, n, x);
    int c = findCeil(a, n, x);
    return make_pair(f, c);
}

// First and Last Position of an Element In Sorted Array - Upper and Lower Bound
int lowerBound(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int upperBound(vector<int> &arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    int lb = lowerBound(arr, n, k);
    if (lb == n || arr[lb] != k)
        return {-1, -1};
    return {lb, upperBound(arr, n, k) - 1};
}

// First and Last Position of an Element In Sorted Array - Binary Search
int firstOccurrence(vector<int> &arr, int n, int k)
{
    int low = 0, high = n - 1;
    int first = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == k)
        {
            first = mid;
            high = mid - 1;
        }

        else if (arr[mid] < k)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }
    return first;
}
int lastOccurrence(vector<int> &arr, int n, int k)
{
    int low = 0, high = n - 1;
    int last = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == k)
        {
            last = mid;
            low = mid + 1;
        }

        else if (arr[mid] < k)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }
    return last;
}
pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    int first = firstOccurrence(arr, n, k);
    if (first == -1)
        return {-1, -1};
    int last = lastOccurrence(arr, n, k);
    return {first, last};
}

// Number of occurrence
int firstOccurrence(vector<int> &arr, int n, int k)
{
    int low = 0, high = n - 1;
    int first = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == k)
        {
            first = mid;
            high = mid - 1;
        }

        else if (arr[mid] < k)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }
    return first;
}
int lastOccurrence(vector<int> &arr, int n, int k)
{
    int low = 0, high = n - 1;
    int last = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == k)
        {
            last = mid;
            low = mid + 1;
        }

        else if (arr[mid] < k)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }
    return last;
}
pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    int first = firstOccurrence(arr, n, k);
    if (first == -1)
        return {-1, -1};
    int last = lastOccurrence(arr, n, k);
    return {first, last};
}
int count(vector<int> &arr, int n, int x)
{
    pair<int, int> ans = firstAndLastPosition(arr, n, x);
    if (ans.first == -1)
        return 0;
    return ans.second - ans.first + 1;
}






int main()
{
    int x;
    cin >> x;

    vector<int> arr = {3, 5, 8, 15, 19};
    pair<int, int> result = getFloorAndCeil(arr, arr.size(), x);
    cout << "Floor: " << result.first << endl;
    cout << "Ceil: " << result.second << endl;

    return 0;
}
