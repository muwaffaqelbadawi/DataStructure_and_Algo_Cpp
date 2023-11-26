#include <bits/stdc++.h>
using namespace std;



// Row with max 1s
int lowerBound(vector<int> arr, int n, int x)
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
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int cnt_max = 0;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        int cnt_ones = m - lowerBound(matrix[i], m, 1);
        if (cnt_ones > cnt_max)
        {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}

// Search In A 2D Matrix
bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();
    int low = 0, high = n * m - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int row = mid / m;
        int col = mid % m;

        if (mat[row][col] == target)
        {
            return true;
        }

        else if (mat[row][col] < target)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }
    return false;
}



int main()
{

    return 0;
}
