#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;

    // Problems

    /* // 1. Find the first occurence of a X in a sorted array.
    // If it does not exists, print -1
    vector<int> arr = {1,4,4,4,4,9,9,10,11};
    int n = arr.size();
    int ind = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    if(ind != n && arr[ind] == x) cout << ind;
    else cout << -1;  */
    
    /* // 2. Find the last occurence of a X in a sorted array.
    // If it does not exists, print -1
    vector<int> arr = {1,4,4,4,4,9,9,10,11};
    int n = arr.size();
    int ind = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
    ind--;
    if(ind >= 0 && arr[ind] == x) cout << ind;
    else cout << -1; */

    /* // 3. Find The largest number smaller than X in a sorted array.
    // If no number exists print -1
    vector<int> arr = {1,4,4,4,4,9,9,10,11};
    int n = arr.size();
    int ind = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    ind--;
    if(ind >= 0) cout << arr[ind];
    else cout << -1; */
    
    // 4. Find The smallest number greater than X in a sorted array.
    // If no number exists print -1
    vector<int> arr = {1,4,4,4,4,9,9,10,11};
    int n = arr.size();
    int ind = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
    if(ind < n) cout << arr[ind];
    else cout << -1;

    /* // Binary Search
    vector<int> arr = {1, 4, 5, 8, 9};
    bool res = binary_search(arr.begin(), arr.end(), n); */

    /* // Lower Bound
    vector<int> arr = {1, 4, 5, 6, 9, 9};
    int ind = lower_bound(arr.begin(), arr.end(), n) - arr.begin(); */
    
    /* // Lower Bound
    vector<int> arr = {1, 4, 5, 6, 9, 9};
    int ind = upper_bound(arr.begin(), arr.end(), n) - arr.begin(); */
    return 0;
}
