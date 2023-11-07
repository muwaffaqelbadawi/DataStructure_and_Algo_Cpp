#include <bits/stdc++.h>
using namespace std;

// Implementation of Lower Bound
int lb(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int x;
    cin >> x;
    vector<int> arr = {3,5,8,15,19};
    int result = lb(arr, arr.size(), x);
    cout << result;

    return 0;
}
