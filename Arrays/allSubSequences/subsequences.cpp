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

int main()
{
    int n;
    vector<int> arr;
    vector<int> ds;

    while (cin >> n) arr.push_back(n);
    n = arr.size();

    allSubsequences(0, ds, arr, n);
    return 0;
}
