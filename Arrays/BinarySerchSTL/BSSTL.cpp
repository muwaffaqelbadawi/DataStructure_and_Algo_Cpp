#include <bits/stdc++.h>
using namespace std;

// Binary Search STL function
// Lower and Upper Bounds STL functions
int main()
{
    int n;
    cin >> n;

    /* // Binary Search
    vector<int> arr = {1, 4, 5, 8, 9};
    bool res = binary_search(arr.begin(), arr.end(), n); */

    /* // Lower Bound
    vector<int> arr = {1, 4, 5, 6, 9, 9};
    int ind = lower_bound(arr.begin(), arr.end(), n) - arr.begin(); */
    
    // Lower Bound
    vector<int> arr = {1, 4, 5, 6, 9, 9};
    int ind = upper_bound(arr.begin(), arr.end(), n) - arr.begin();

    cout << ind;

    return 0;
}
