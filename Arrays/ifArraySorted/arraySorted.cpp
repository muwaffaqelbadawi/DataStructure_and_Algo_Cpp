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
    return 0;
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
vector<vector<int>> mergeOverlappingIntervals1(vector<vector<int>> &arr)
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
vector<vector<int>> mergeOverlappingIntervals2(vector<vector<int>> &arr)
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
void merge1(long long arr1[], long long arr2[], int n, int m)
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
void merge2(long long arr1[], long long arr2[], int n, int m)
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

// Find missing and repeating numbers - Better (Hashing)
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    int n = a.size();
    int hashArr[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        hashArr[a[i]]++;
    }

    int repeating = -1, missing = -1;

    for (int i = 1; i <= n; i++)
    {
        if (hashArr[i] == 2)
        {
            repeating = i;
        }

        else if (hashArr[i] == 0)
        {
            missing = i;
        }

        if (repeating != -1 && missing != -1)
        {
            break;
        }
    }
    return {repeating, missing};
}

// Find missing and repeating numbers - O.P. 1 (Mathematical approach)
vector<int> findMissingRepeatingNumbers1(vector<int> a)
{
    long long n = a.size();
    // S - Sn = x - y
    // S2 - S2N
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++)
    {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }
    long long val1 = S - SN; // x - y
    long long val2 = S2 - S2N;
    val2 = val2 / val1; // x + y
    long long x = (val1 + val2) / 2;
    long long y = x - val1;
    return {(int)x, (int)y};
}

// Find missing and repeating numbers - O.P. 2 (XOR method)
vector<int> findMissingRepeatingNumbers2(vector<int> a)
{
    long long n = a.size();
    int XOR = 0;
    for (int i = 0; i < n; i++)
    {
        XOR = XOR ^ a[i];
        XOR = XOR ^ i + 1;
    }

    // Simple bit manipulation trick
    int number = XOR & ~(XOR - 1);

    /* int bitNo = 1;
    while(1)
    {
        if((XOR & (1 << bitNo) != 0)
        {
            break;
        }
        bitNo++;
    } */

    int zero = 0;
    int one = 0;

    for (int i = 0; i < n; i++)
    {
        // Part of one's club
        if ((a[i] & number) != 0)
        {
            one = one ^ a[i];
        }

        // Part of zero's club
        else
        {
            zero = zero ^ a[i];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        // Part of one's club
        if ((i & number) != 0)
        {
            one = one ^ i;
        }

        // Part of zero's club
        else
        {
            zero = zero ^ i;
        }
    }

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == zero)
        {
            cnt++;
        }
    }

    if (cnt == 2)
    {
        return {zero, one};
    }

    return {one, zero};
}

// Count Number of Inversions - (O.P. Merge Sort)
int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr

    // storing elements in the temporary array in a sorted manner//
    int cnt = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }

        // right is smaller
        else
        {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }

    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);      // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += merge(arr, low, mid, high);    // merging sorted halves
    return cnt;
}

int numberOfInversions(vector<int> &a, int n)
{
    return mergeSort(a, 0, n - 1);
}

// Reverse Pairs
void mergeP(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr

    // storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int cnt = 0;
    int right = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2 * arr[right])
            right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSortP(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);      // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high); // merging sorted halves
    return cnt;
}

int team(vector<int> &skill, int n)
{
    return mergeSort(skill, 0, n - 1);
}

// Maximum product of the subarray
int subarrayWithMaxProduct(vector<int> &arr)
{
    int pre = 1, suff = 1;
    int ans = INT_MIN;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (pre == 0)
        {
            pre = 1;
        }

        if (suff == 0)
        {
            suff = 1;
        }

        pre *= arr[i];
        suff *= arr[n - i - 1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
}

int main()
{
    // int n;

    vector<int> arr = {2,3,-2,4};

    // while (cin >> n)
    // {
    //     arr.push_back(n);
    // }

    int result = subarrayWithMaxProduct(arr);
    cout << result;

    return 0;
}
