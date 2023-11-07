#include <bits/stdc++.h>
using namespace std;

// Floor and Ciel
int findFloor(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] <= x)
        {
            ans = arr[mid];
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int findCeil(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            ans = arr[mid];
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    int f = findFloor(a, n, x);
    int c = findCeil(a, n, x);
    return make_pair(f, c);
}

int main()
{
    int x;
    cin >> x;
    
    vector<int> arr = {3, 5, 8, 15, 19};
    pair<int, int> result = getFloorAndCeil(arr, arr.size(), x);
    cout << "Floor: " << result.first << endl;
    cout << "Ceil: " << result.second << endl;

    return 0;
}
