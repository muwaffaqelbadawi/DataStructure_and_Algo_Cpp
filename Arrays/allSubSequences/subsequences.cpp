#include <bits/stdc++.h>
using namespace std;

// Custom Reverse Function
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
void allSubsequences(int ind, vector<int> &ds, vector<int> &arr, int n)
{
    if (ind == n)
    {
        for (auto it : ds)
        {
            cout << it << " ";
        }
        if (ds.size() == 0)
        {
            cout << "{}";
        }
        cout << endl;
        return;
    }
    // take or pick the particular index into subsequence
    ds.push_back(arr[ind]);
    allSubsequences(ind + 1, ds, arr, n);
    ds.pop_back();

    // not pick, or not take condition, this element is not added to your subsequence
    allSubsequences(ind + 1, ds, arr, n);
}
void subsequencesWithSumK(int ind, vector<int> &ds, int s, int sum, vector<int> &arr, int n)
{
    if (ind == n)
    {
        if (s == sum)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
        }
        return;
    }
    // pick
    ds.push_back(arr[ind]);
    s += arr[ind];
    subsequencesWithSumK(ind + 1, ds, s, sum, arr, n);
    s -= arr[ind];
    ds.pop_back();

    // not pick
    subsequencesWithSumK(ind + 1, ds, s, sum, arr, n);
}
bool subsequencWithAnySumK(int ind, vector<int> &ds, int s, int sum, vector<int> &arr, int n)
{
    if (ind == n)
    {
        // if condition satisfied
        if (s == sum)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
            return true;
        }
        // condition not satisfied
        else
            return false;
    }
    // pick
    ds.push_back(arr[ind]);
    s += arr[ind];

    if (subsequencWithAnySumK(ind + 1, ds, s, sum, arr, n) == true)
        return true;
    s -= arr[ind];
    ds.pop_back();

    // not pick
    if (subsequencWithAnySumK(ind + 1, ds, s, sum, arr, n) == true)
        return true;
    return false;
}
int countSubsequences(int ind, int s, int sum, vector<int> &arr, int n)
{
    // condition not satisfied
    if (s > sum)
        return 0;
    if (ind == n)
    {
        // if condition satisfied
        if (s == sum)
            return 1;

        // condition not satisfied
        else
            return 0;
    }
    s += arr[ind];

    int l = countSubsequences(ind + 1, s, sum, arr, n);
    s -= arr[ind];

    int r = countSubsequences(ind + 1, s, sum, arr, n);
    return l + r;
}
void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (ind == arr.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }
    // pick up the element
    if (arr[ind] <= target)
    {
        ds.push_back(arr[ind]);
        // Pick
        findCombination(ind, target - arr[ind], arr, ans, ds);
        // remove vthe element
        ds.pop_back();
    }
    // Not pick
    findCombination(ind + 1, target, arr, ans, ds);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, target, candidates, ans, ds);
    return ans;
}
void findCombination2(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }
    for (int i = ind; i < arr.size(); i++)
    {
        // if this is not the first time to pick don't pick duplicates
        if (i > ind && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > target)
            break;
        ds.push_back(arr[i]);
        findCombination(i + 1, target - arr[i], arr, ans, ds);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, target, candidates, ans, ds);
    return ans;
}
// Power Set
vector<vector<int>> pwset(vector<int> v)
{
    int n = v.size();
    vector<vector<int>> subsets;

    // for (int num = 0; num < pow(2, n); num++)
    for (int num = 0; num < (1 << n); num++)
    {
        vector<int> sub;
        for (int i = 0; i < n; i++)
        {
            if (num & (1 << i))
            {
                sub.push_back(v[i]);
            }
        }
        subsets.push_back(sub);
    }
    return subsets;
}
// Genarating all substrings using power set
vector<vector<char>> pwsetSubStrings(string str)
{
    int n = str.size();
    vector<vector<char>> subStrings;

    // for (int num = 0; num < pow(2, n); num++)
    for (int num = 0; num < (1 << n); num++)
    {
        vector<char> sub;
        for (int i = 0; i < n; i++)
        {
            if (num & (1 << i))
            {
                sub.push_back(str[i]);
            }
        }
        subStrings.push_back(sub);
    }
    return subStrings;
}
void printSubStrings(const vector<vector<char>> &subStrings)
{
    for (const auto &subString : subStrings)
    {
        for (const auto &num : subString)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}
void printSubsets(const vector<vector<int>> &subsets)
{
    for (const auto &subset : subsets)
    {
        for (const auto &num : subset)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}
// Subset sum I
void func(int ind, int sum, vector<int> &arr, int N, vector<int> &sumSubset)
{
    if (ind == N)
    {
        sumSubset.push_back(sum);
        return;
    }

    // Pick the element
    func(ind + 1, sum + arr[ind], arr, N, sumSubset);

    // Not pick
    func(ind + 1, sum, arr, N, sumSubset);
}
vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> sumSubset;
    func(0, 0, arr, N, sumSubset);
    sort(sumSubset.begin(), sumSubset.end());
    return sumSubset;
}
// Subset sum II
void findSubsets(int ind, vector<int> &nums, vector<int> ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);
    for (int i = ind; i < nums.size(); i++)
    {
        // if this is not the first time to pick don't pick duplicates
        if (i > ind && nums[i] == nums[i - 1])
            continue;
        ds.push_back(nums[i]);
        findSubsets(i + 1, nums, ds, ans);
        ds.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    findSubsets(0, nums, ds, ans);
    return ans;
}
void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[])
{
    // Base case
    if (ds.size() == nums.size())
    {
        // the extra time of N
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (!freq[i])
        {
            ds.push_back(nums[i]);
            freq[i] = 1;
            recurPermute(ds, nums, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[nums.size()];
    // initialize freq arr with zeros
    for (int i = 0; i < nums.size(); i++)
        freq[i] = 0;
    recurPermute(ds, nums, ans, freq);
    return ans;
}
// Generating all permutations second approach
void recurPermute2(int ind, vector<int> &nums, vector<vector<int>> &ans)
{
    // Base case
    if (ind == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i = ind; i < nums.size(); i++)
    {
        Reverse(nums, ind, i);
        recurPermute2(ind + 1, nums, ans);
        Reverse(nums, ind, i);
    }
}
vector<vector<int>> permute2(vector<int> &nums)
{
    vector<vector<int>> ans;
    recurPermute2(0, nums, ans);
    return ans;
}
void printPermutations(const vector<vector<int>> &permutations)
{
    cout << "[";
    for (size_t i = 0; i < permutations.size(); i++)
    {
        cout << "[";
        for (size_t j = 0; j < permutations[i].size(); j++)
        {
            cout << permutations[i][j];
            if (j != permutations[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i != permutations.size() - 1)
            cout << ",";
    }
    cout << "]";
    cout << endl;
}
void printPermutations1(const vector<vector<int>> &permutations)
{
    for (const auto &permutee : permutations)
    {
        for (const auto &num : permutee)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}
// Generate next permutation
// STL Library
vector<int> nextGeneratedPermutation(vector<int> &arr)
{
    next_permutation(arr.begin(), arr.end());
    return arr;
}
vector<int> nextGreaterPermutation(vector<int> &arr)
{
    int ind = -1;
    const int n = arr.size();

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            ind = i;
            break;
        }
    }

    if (ind == -1)
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }

    for (int i = n - 1; i >= ind; i--)
    {
        if (arr[i] > arr[ind])
        {
            swap(arr[i], arr[ind]);
            break;
        }
    }

    reverse(arr.begin() + ind + 1, arr.end());
    return arr;
}
vector<int> nextGreaterPermutation2(vector<int> &arr)
{
    int ind = -1;
    const int n = arr.size();

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            ind = i;
            break;
        }
    }

    if (ind == -1)
    {
        Reverse(arr, 0, n-1);
        return arr;
    }

    for (int i = n - 1; i >= ind; i--)
    {
        if (arr[i] > arr[ind])
        {
            swap(arr[i], arr[ind]);
            break;
        }
    }

    Reverse(arr, ind + 1, n-1);
    return arr;
}
void printNextGreaterPermutation(const vector<int> &nextPermute)
{
    for (const auto &num : nextPermute)
    {
        cout << num << " ";
    }
}
// Find the leader
vector<int> superiorElements(vector<int> &a)
{
    // O(N)
    vector<int> ans;
    int maxi = INT_MIN;
    int n = a.size();

    // O(N)
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > maxi)
        {
            ans.push_back(a[i]);
        }
        // keep track of the right max
        maxi = max(maxi, a[i]);
    }
    // O(N Log N) in the worst case
    sort(ans.begin(), ans.end());
    return ans;
}
// Longest Successive Elements - Better solution
int longestSuccessiveElements(vector<int> &a)
{
    const int n = a.size();
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;
    if (n == 0) return 0;
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
    {
        if (a[i] - 1 == lastSmaller)
        {
            cnt++;
            lastSmaller = a[i];
        }
        else if (lastSmaller != a[i])
        {
            cnt = 1;
            lastSmaller = a[i];
        }
        longest = max(longest, cnt);
    }
    return longest;
}
// Longest Successive Elements - OP.
int longestSuccessiveElements(vector<int> &a)
{
    const int n = a.size();
    if (n == 0)
        return 0;
    int longest = 1;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }
    for (const auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x += 1;
                cnt += 1;
            }
            // Whatever ther's update
            longest = max(longest, cnt);
        }
    }
    return longest;
}
// Set Matrix Zeros - Better
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{
    int col[m] = {0};
    int row[n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] || col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

// Set Matrix Zeros - OP.
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{
    // int col[m] = {0};  -> matrix[0][..]
    // int row[n] = {0};  -> matrix[..][0]

    int col0 = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                // mark the i-th row
                matrix[i][0] = 0;
                // mark j-th col
                if (j != 0)
                {
                    matrix[0][j] = 0;
                }

                else
                {
                    col0 = 0;
                }
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] != 0)
            {
                // check for col & row
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[0][j] = 0;
        }
    }

    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }
    return matrix;
}
// My Pow
double myPow(double x, int n)
{
    double ans = 1.0;
    long long nn = n;
    if (nn < 0)
        nn = -1 * nn;
    while (nn)
    {
        if (nn % 2)
        {
            ans = ans * x;
            nn = nn - 1;
        }
        else
        {
            x = x * x;
            nn = nn / 2;
        }
    }
    if (n < 0)
        ans = (double)(1.0) / (double)(ans);
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
    vector<int> result = nextGreaterPermutation(arr);
    printNextGreaterPermutation(result);

    // string str;
    // cin >> str;
    // int target = 7;
    // n = arr.size();
    return 0;
}
