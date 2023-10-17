#include <bits/stdc++.h>
using namespace std;

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







int main()
{
    // int n;
    string str;
    cin >> str;
    // int target = 7;
    /* vector<int> arr;

    while (cin >> n)
    {
        arr.push_back(n);
    } */
    // n = arr.size();

    vector<vector<char>> result = pwsetSubStrings(str);
    printSubStrings(result);

    return 0;
}
