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
// First approach
// Find specific element of Pascal Triangle given row and col
int nCr(int n, int r)
{
    long long res = 1;

    // calculating nCr
    for (int i = 1; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return (int)(res);
}
// Pascal Triangle first approach
vector<vector<int>> pascalTriangle(int n)
{
    vector<vector<int>> ans;

    // Store the entire pascal's triangle:
    for (int row = 1; row <= n; row++)
    {
        vector<int> tempLst; // temporary list
        for (int col = 1; col <= row; col++)
        {
            tempLst.push_back(nCr(row - 1, col - 1));
        }
        ans.push_back(tempLst);
    }
    return ans;
}
// Second approatch
vector<int> generateRow(int row)
{
    long long ans = 1;
    vector<int> ansRow;
    for (int col = 1; col < row; col++)
    {
        ans = ans * (row - col);
        ans = ans / (col);
        ansRow.push_back(ans);
    }
    return ansRow;
}
// Pascal Triangle second approach
vector<vector<int>> pascalTriangle(int N)
{
    vector<vector<int>> ans;
    for (int i = 1; i <= N; i++)
    {
        ans.push_back(generateRow(i));
    }
    return ans;
}
void printPascalTriangle(const vector<vector<int>> &subsets)
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

// Majority Element II
vector<int> majorityElementII(vector<int> v)
{
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        if (cnt1 == 0 && v[i] != el2)
        {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && v[i] != el1)
        {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (el1 == v[i])
        {
            cnt1++;
        }
        else if (el2 == v[i])
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    // Manual Check
    vector<int> ls;
    cnt1 = 0;
    cnt2 = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (el1 == v[i])
        {
            cnt1++;
        }
        if (el2 == v[i])
        {
            cnt2++;
        }
    }
    int mini = (int)(v.size() / 3) + 1;
    if (cnt1 >= mini)
        {
            ls.push_back(el1);
        }
    if (cnt2 >= mini)
        {
            ls.push_back(el2);
        }
    sort(ls.begin(), ls.end());
    return ls;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> ans = pascalTriangle(n);
    printPascalTriangle(ans);

    /* vector<int> arr;

    while(cin >> n)
    {
        arr.push_back(n);
    }

    */

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

    // int allsSubWithK = findAllSubarraysWithGivenSum(arr, 3);
    // cout << allsSubWithK;

    // rotateMatrix(arr);
    // printMatrix(arr);
    return 0;
}