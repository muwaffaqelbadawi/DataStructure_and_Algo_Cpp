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
void Reverse(vector<int> &arr, int start, int end)
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
        mpp[arr[i]]++;
    for (auto it : mpp)
        if (it.second == 1)
            return it.first;
}
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
int getLongestSubarray(vector<int> &a, int k)
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
int majorityElement(vector<int> v)
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
int majorityElement(vector<int> v)
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

        if (sum < 0) sum = 0;
        
    }
    if (maxi < 0) return 0;
    else return maxi;
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

int main()
{
    int n;
    vector<int> arr;

    while (cin >> n)
    {
        arr.push_back(n);
    }

    int slargest = ArraySorted(arr);
    cout << slargest;

    return 0;
}
