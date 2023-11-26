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
pair<int, int> firstAndLastPosition1(vector<int> &arr, int n, int k)
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
pair<int, int> firstAndLastPosition2(vector<int> &arr, int n, int k)
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

// Median of two sorted arrays - Brute
double median(vector<int> &a, vector<int> &b)
{
    vector<int> c;
    int n1 = a.size(), n2 = b.size();
    int i = 0, j = 0;

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
            c.push_back(a[i++]);
        else
            c.push_back(b[j++]);
    }
    while (i < n1)
        c.push_back(a[i++]);
    while (j < n2)
        c.push_back(b[j++]);

    int n = n1 + n2;
    if (n % 2 == 1)
    {
        return (double)c[n / 2];
    }

    double median = ((double)c[n / 2] + (double)c[(n / 2) - 1]) / 2.0;
    return median;
}

// Median of two sorted arrays - Better
double median(vector<int> &a, vector<int> &b)
{
    int n1 = a.size(), n2 = b.size();
    int n = n1 + n2; // total size
    // required indices:
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1el = -1, ind2el = -1;

    // apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            if (cnt == ind1)
                ind1el = a[i];
            if (cnt == ind2)
                ind2el = a[i];
            cnt++;
            i++;
        }
        else
        {
            if (cnt == ind1)
                ind1el = b[j];
            if (cnt == ind2)
                ind2el = b[j];
            cnt++;
            j++;
        }
    }

    // copy the left-out elements:
    while (i < n1)
    {
        if (cnt == ind1)
            ind1el = a[i];
        if (cnt == ind2)
            ind2el = a[i];
        cnt++;
        i++;
    }
    while (j < n2)
    {
        if (cnt == ind1)
            ind1el = b[j];
        if (cnt == ind2)
            ind2el = b[j];
        cnt++;
        j++;
    }
}

// Median of two sorted arrays - OP.
double median(vector<int>& a, vector<int>& b) {
	int n1 = a.size();
    int n2 = b.size();
    if(n1 > n2) return median(b, a);
    int low = 0, high = n1;
    int left = (n1 + n2 + 1) / 2;
    int n = n1 + n2;
    while(low <= high)
    {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if(mid1 < n1) r1 = a[mid1];
        if(mid2 < n2) r2 = b[mid2];
        if(mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = b[mid2 - 1];

        
        if(l1 <= r2 && l2 <= r1)
        {
            if(n % 2 == 1) return max(l1, l2);
            return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }
        else if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0;
}

// K-th Element of Two Sorted Arrays - OP.
int kthElement(vector<int> &a, vector<int> &b, int n1, int n2, int k)
{
    if (n1 > n2)
        return kthElement(b, a, n2, n1, k);
    int low = max(k - n2, 0), high = min(k, n1);
    int left = k;
    int n = n1 + n2;
    while (low <= high)
    {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1)
            r1 = a[mid1];
        if (mid2 < n2)
            r2 = b[mid2];
        if (mid1 - 1 >= 0)
            l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }

        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0;
}






int main()
{
    int x = 80;
    cout << x;

    // vector<int> arr = {3, 5, 8, 15, 19};
    // pair<int, int> result = getFloorAndCeil(arr, arr.size(), x);
    // cout << "Floor: " << result.first << endl;
    // cout << "Ceil: " << result.second << endl;

    return 0;
}
