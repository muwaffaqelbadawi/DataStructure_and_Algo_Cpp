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
int firstOccurrence1(vector<int> &arr, int n, int k)
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
int lastOccurrence2(vector<int> &arr, int n, int k)
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

// Search In Rotated Sorted Array
int search(vector<int>& arr, int n, int k)
{
    int low = 0, high = n - 1;
    while(low  <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == k)
        {
            return mid;
        }

        if(arr[low] <= arr[mid])
        {
            // left sorted
            if(arr[low] <= k && k <= arr[mid])
            {
                // eleminate the right half
                high = mid - 1;
            }

            else
            {
                // eleminate the left half
                low = mid + 1;
            }
        }

        else
        {
            // right soerted
            if(arr[mid] <= k && k <= arr[high])
            {
                // eleminate the right half
                low = mid + 1;
            }

            else
            {
                // eleminate the left half
                high = mid - 1;
            }

        }
    }
    return -1;
}

// Search In A Rotated Sorted Array II
bool searchInARotatedSortedArrayII(vector<int> &arr, int k)
{
    int n = arr.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == k)
        {
            return true;
        }

        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++, high--;
            continue;
        }

        if (arr[low] <= arr[mid])
        {
            // left sorted
            if (arr[low] <= k && k <= arr[mid])
            {
                // eleminate the right half
                high = mid - 1;
            }

            else
            {
                // eleminate the left half
                low = mid + 1;
            }
        }

        else
        {
            // right soerted
            if (arr[mid] <= k && k <= arr[high])
            {
                // eleminate the right half
                low = mid + 1;
            }

            else
            {
                // eleminate the left half
                high = mid - 1;
            }
        }
    }
    return false;
}

// Find Minimum in Rotated Sorted Array
int findMin(vector<int> &arr)
{
    int n = arr.size();
    int low = 0, high = n - 1, ans = INT_MAX;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[low] <= arr[mid])
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }

        else
        {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

// Find Minimum in Rotated Sorted Array - Optimized
int findMinOP(vector<int> &arr)
{
    int n = arr.size();
    int low = 0, high = n - 1, ans = INT_MAX;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[low] <= arr[high])
        {
            ans = min(ans, arr[low]);
            break;
        }

        if (arr[low] <= arr[mid])
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }

        else
        {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

// Find the number of rotations
int findKRotation(vector<int> &arr)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = INT_MAX;
    int index = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[low] <= arr[high])
        {
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }
            break;
        }

        if (arr[low] <= arr[mid])
        {
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }
            low = mid + 1;
        }

        else
        {
            if (arr[mid] < ans)
            {
                index = mid;
                ans = arr[mid];
            }
            high = mid - 1;
        }
    }
    return index;
}

// Single Element in a Sorted Array
int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size();
    int low = 1, high = n - 2;

    if (n == 1)
    {
        return arr[0];
    }

    if (arr[0] != arr[1])
    {
        return arr[0];
    }

    if (arr[n - 1] != arr[n - 2])
    {
        return arr[n - 1];
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
        {
            return arr[mid];
        }

        // left half
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
        {
            // eliminate the left half
            low = mid + 1;
        }

        // if this is not the case
        else
        {
            // eliminate the right half
            high = mid - 1;
        }
    }
    // dummy statement
    return -1;
}

// Find Peak Element - version (1)
int findPeakElement1(vector<int> &arr)
{
    int n = arr.size();
    int low = 1, high = n-2;
    
    if(n == 1)
    {
        return 0;
    }

    if(arr[0] > arr[1])
    {
        return 0;
    }

    if(arr[n-1] > arr[n-2])
    {
        return n-1;
    }

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
        {
            return mid;
        }

        else if(arr[mid] > arr[mid-1])
        {
            low = mid + 1;
        }
        
        else if(arr[mid] > arr[mid+1])
        {
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

// Find Peak Element - version (2)
int findPeakElement2(vector<int> &arr)
{
    int n = arr.size();
    int low = 1, high = n-2;
    
    if(n == 1)
    {
        return 0;
    }

    if(arr[0] > arr[1])
    {
        return 0;
    }

    if(arr[n-1] > arr[n-2])
    {
        return n-1;
    }

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
        {
            return mid;
        }

        else if(arr[mid] > arr[mid-1])
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int x = 5;
    cout << x;

    // vector<int> arr = {3, 5, 8, 15, 19};
    // pair<int, int> result = getFloorAndCeil(arr, arr.size(), x);
    // cout << "Floor: " << result.first << endl;
    // cout << "Ceil: " << result.second << endl;

    return 0;
}
