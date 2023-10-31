#include <bits/stdc++.h>
using namespace std;

bool ArraySorted(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] >= arr[i - 1])
        {
        }
        else
        {
            return false;
        }
    }
    return true;
}

int removeDuplicates(vector<int> &arr)
{
    int i = 0;
    for (int j = 1; j < arr.size() - 1; j++)
    {
        if (arr[j] != arr[i])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    return i + 1;
}

void Swap(vector<int> &arr, int start, int end)
{
    while (start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// bitwise xor operator is the caret symbol ^
int missingNumber(vector<int> &a, int N)
{
    int xor1 = 0, xor2 = 0;
    int n = N - 1;

    for (int i = 0; i < n; i++)
    {
        xor2 = xor1 ^ a[i];
        xor1 = xor1 ^ (n + 1);
    }

    return xor1 ^ xor2;
}

// in map key is it.first and value is it.second
int getSingleElement(vector<int> &arr)
{
    map<long long, int> mpp;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    for (auto it : mpp)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }
}

// Better
int longestSubarrayWithSumK(vector<int> a, long long k)
{
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        long long rem = sum - k;

        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}

void sortArray(vector<int> &arr, int n)
{
    // Everytime there's moving pointers use while loop
    // In most of the cases better solution uses hashing in some way TC=N*LogN
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

string read(int n, vector<int> book, int target)
{
    int left = 0, right = n - 1;
    sort(book.begin(), book.end());
    while (left < right)
    {
        int sum = book[left] + book[right];
        if (sum == target)
        {
            return "YES";
        }
        if (sum < target)
            left++;
        else
            right--;
    }
    return "NO";
}

// Find longest subarray with sum K
int getLongestSubarray(vector<int> &a, int k)
{
    map<long long, int> mpp;
    long long preSum = 0;
    int maxLen = 0;
    for (int i = 0; i < a.size(); i++)
    {
        preSum += a[i];
        if (preSum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        long long rem = preSum - k;

        if (mpp.find(rem) != mpp.end())
        {
            int len = i - mpp[rem];
            maxLen = max(maxLen, len);
        }

        // Do not update the index of preSum if it already exist in the map
        // Look as left as possible (we need to find longest subarray not shortest)
        if (mpp.find(preSum) == mpp.end())
        {
            mpp[preSum] = i;
        }
    }
    return maxLen;
}

int majorityElement1(vector<int> v)
{
    map<int, int> mpp;
    for (int i = 0; i < v.size(); i++)
    {
        // mark the elements with the time occurence
        mpp[v[i]]++;
    }
    for (auto it : mpp)
    {
        if (it.second > (v.size() / 2))
        {
            return it.first;
        }
    }
    return -1;
}

int majorityElement2(vector<int> v)
{
    int count = 0;
    int el;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count = 1;
            el = v[i];
        }
        else if (v[i] == el)
            count++;
        else
            count--;
    }

    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == el)
            count1++;
    }
    if (count1 > (n / 2))
        return el;
    else
        return -1;
}

long long maxSubarraySum(vector<int> arr, int n)
{
    long long sum = 0, maxi = LONG_MIN;
    int start = 0, ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++)
    {
        if (sum = 0)
            start = i;
        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0)
            sum = 0;
    }
    if (maxi < 0)
        return 0;
    else
        return maxi;
}

int bestTimeToBuyAndSellStock(vector<int> &prices)
{
    int mini = prices[0];
    int profit = 0;
    int cost = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        cost = prices[i] - mini;
        // Maximize the cost
        profit = max(profit, cost);
        mini = min(mini, prices[i]);
    }
    return profit;
}

vector<int> rearrangeArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 0);
    int posIndex = 0, negIndex = 1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0)
        {
            ans[negIndex] = nums[i];
            negIndex += 2;
        }
        else
        {
            ans[posIndex] = nums[i];
            posIndex += 2;
        }
    }
    return ans;
}

// Merge All Overlapping Intervals - Brute
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];

        if (!ans.empty() && end <= ans.back()[1])
        {
            continue;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j][0] <= end)
            {
                end = max(end, arr[j][1]);
            }

            else
            {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

// Merge All Overlapping Intervals - O.P.
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]);
        }

        else
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

// Merge Two Sorted Arrays - Brure
void merge(long long arr1[], long long arr2[], int n, int m)
{
    long long arr3[m + n];
    int left = 0;
    int right = 0;
    int index = 0;

    while (left < n && right < m)
    {
        if (arr1[left] <= arr2[right])
        {
            arr3[index] = arr1[left];
            left++, index++;
        }

        else
        {
            arr3[index] = arr2[right];
            right++, index++;
        }
    }

    while (left < n)
    {
        arr3[index++] = arr1[left++];
    }

    while (right < m)
    {
        arr3[index++] = arr2[right++];
    }

    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
        {
            arr1[i] = arr3[i];
        }

        else
        {
            arr2[i - n] = arr3[i];
        }
    }
}

// Merge Two Sorted Arrays - O.P. 1
void merge(long long arr1[], long long arr2[], int n, int m)
{
    int left = n - 1;
    int right = 0;

    while (left >= 0 && right < m)
    {
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--, right++;
        }

        else
        {
            break;
        }
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

// Merge Two Sorted Arrays - O.P. 2 (gab method)
class Solution
{
private:
    void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2)
    {
        if (arr1[ind1] > arr2[ind2])
        {
            swap(arr1[ind1], arr2[ind2]);
        }
    }

public:
    // Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        int len(n + m);
        int gap = (len / 2) + (len % 2);

        while (gap > 0)
        {
            int left = 0;
            int right = left + gap;

            while (right < len)
            {
                // arr1 and arr2
                if (left < n && right >= n)
                {
                    swapIfGreater(arr1, arr2, left, right - n);
                }

                // arr2 and arr2
                else if (left >= n)
                {
                    swapIfGreater(arr2, arr2, left - n, right - n);
                }

                // arr1 and arr1
                else
                {
                    swapIfGreater(arr1, arr1, left, right);
                }
                left++, right++;
            }
            if (gap == 1)
            {
                break;
            }
            gap = (gap / 2) + (gap % 2);
        }
    }
};











int main()
{

    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        long long arr1[n], arr2[m];

        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);

        for (int i = 0; i < n; i++)
            cout << arr1[i] << " ";

        for (int i = 0; i < m; i++)
            cout << arr2[i] << " ";

        cout << endl;
    }

    return 0;
}

// } Driver Code Ends

int main()
{
    int n;

    vector<int> arr;

    while (cin >> n)
    {
        arr.push_back(n);
    }

    int result = getLongestSubarray(arr, 3);
    cout << result;

    return 0;
}
