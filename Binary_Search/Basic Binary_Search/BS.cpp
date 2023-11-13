#include <bits/stdc++.h>
using namespace std;

// Binary Search - Iterative approach
int searchIterative(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }

        else if (target > nums[mid])
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

// Binary Search - Recursive approach
int bs(vector<int> &nums, int low, int high, int target)
{
    if (low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;
    if (nums[mid] == target)
    {
        return mid;
    }

    else if (target > nums[mid])
    {
        return bs(nums, mid + 1, high, target);
    }

    else
    {
        return bs(nums, low, mid - 1, target);
    }
}

int searchRecursive(vector<int> &nums, int target)
{
    return bs(nums, 0, nums.size() - 1, target);
}

int main()
{
    int n;
    vector<int> arr;
    int target = 3;

    while (cin >> n)
    {
        arr.push_back(n);
    }

    int result = searchIterative(arr, target);
    cout << result;

    return 0;
}
