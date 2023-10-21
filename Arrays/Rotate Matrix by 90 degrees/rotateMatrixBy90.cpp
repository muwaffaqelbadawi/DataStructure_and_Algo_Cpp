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

// Rotate Matrix by 90 Degrees (Rotate Image)
void rotateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    // Step One:
    // Transpose
    // TC---> O(n / 2 * N / 2)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // row mat [i]
    for (int i = 0; i < n; i++)
    {
        // Step Two:
        // Reverse
        // TC---> O(N * N / 2)
        // use this function or the custom one
        // reverse(mat[i].begin(), mat[i].end());

        // Custome Reverse function
        Reverse(mat[i], 0, n - 1);
    }
}
// Print Matrix
void printMatrix(const vector<vector<int>> &mat)
{
    for (const auto &row : mat)
    {
        for (const auto &num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}
// Spiral Matrix
vector<int> spiralMatrix(vector<vector<int>> &MATRIX)
{
    int n = MATRIX.size();
    int m = MATRIX[0].size();
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;
    vector<int> ans;

    while (top <= bottom && left <= right)
    {
        // right
        // constant top
        for (int i = left; i <= right; i++)
        {
            ans.push_back(MATRIX[top][i]);
        }
        top++;

        // botom
        // constant right
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(MATRIX[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            // left
            // constant botton
            for (int i = right; i >= left; i--)
            {
                ans.push_back(MATRIX[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            // top
            // constant left
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(MATRIX[i][left]);
            }
            left++;
        }
    }
    return ans;
}
// Count All Subarrays With Given Sum
int findAllSubarraysWithGivenSum(vector<int> &arr, int k)
{
    map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0, cnt = 0;

    // TC---> O(N * Log N)
    // SC---> O(N)
    for (int i = 0; i < arr.size(); i++)
    {
        preSum += arr[i];
        int remove = preSum - k;
        cnt += mpp[remove];
        mpp[preSum]++;
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr;

    while(cin >> n)
    {
        arr.push_back(n);

    }

    /* // initializ vector arr of n rows and n columns
    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
    } */

    int allsSubWithK = findAllSubarraysWithGivenSum(arr, 3);
    cout << allsSubWithK;

        // rotateMatrix(arr);
        // printMatrix(arr);
        return 0;
}