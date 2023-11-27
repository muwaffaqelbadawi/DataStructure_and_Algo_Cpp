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



// Find Peak Element II
int maxElement(vector<vector<int>> &mat, int n, int m, int col)
{
    int maxValue = -1;
    int index = -1;
    for(int i=0; i<n; i++)
    {
        if(mat[i][col] > maxValue)
        {
            maxValue = mat[i][col];
            index = i;
        }
    }
    return index;
}
vector<int> findPeakGrid(vector<vector<int>> &g){
    int n = g.size();
    int m = g[0].size();
    int low = 0;
    int high = m - 1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        int maxRowIndex = maxElement(g, n, m, mid);
        int left = mid - 1 > 0 ? g[maxRowIndex][mid - 1] : -1;
        int right = mid + 1 < m ? g[maxRowIndex][mid + 1] : -1;

        if(g[maxRowIndex][mid] > left && g[maxRowIndex][mid] > right)
        {
            return {maxRowIndex, mid};
        }

        else if(g[maxRowIndex][mid] < left)
        {
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }
    return {-1, -1};
}



// Median in a row-wise sorted Matrix
int upperBound(vector<int> &arr, int x, int n)
{
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
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
int countSmallerEqual(vector<vector<int>> &matrix, int n, int m, int x)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += upperBound(matrix[i], x, m);
    }
    return cnt;
}
int median(vector<vector<int>> &matrix, int m, int n)
{
    int low = INT_MAX;
    int high = INT_MIN;
    n = matrix.size();
    m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m - 1]);
    }

    int req = (n * m) / 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int smallerEquals = countSmallerEqual(matrix, n, m, mid);
        if (smallerEquals <= req)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{

    return 0;
}
