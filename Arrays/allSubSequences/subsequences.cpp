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
            for (auto it : ds) cout << it << " ";
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
            for (auto it : ds) cout << it << " ";
            cout << endl;
            return  true;
        }
        // condition not satisfied
        else return false;
    }
    // pick
    ds.push_back(arr[ind]);
    s += arr[ind];

    if(subsequencWithAnySumK(ind + 1, ds, s, sum, arr, n) == true) return true;
    s -= arr[ind];
    ds.pop_back();

    // not pick
    if(subsequencWithAnySumK(ind + 1, ds, s, sum, arr, n) == true) return true;
    return false;
}


int countSubsequences(int ind, int s, int sum, vector<int> &arr, int n)
{
    // condition not satisfied
    if(s > sum) return 0;
    if (ind == n)
    {
        // if condition satisfied
        if (s == sum) return  1;

        // condition not satisfied
        else return 0;
    }
    s += arr[ind];

    int l = countSubsequences(ind + 1, s, sum, arr, n);
    s -= arr[ind];

    int r = countSubsequences(ind + 1, s, sum, arr, n);
    return l + r;
}

int main()
{
    int n;
    int sum = 2;
    vector<int> arr;
    // vector<int> ds;

    while (cin >> n) arr.push_back(n);
    n = arr.size();

    int numberOfSubsequences = countSubsequences(0, 0, sum, arr, n);
    cout << numberOfSubsequences;
    return 0;
}
