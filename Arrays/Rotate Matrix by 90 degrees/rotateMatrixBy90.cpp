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
        reverse(mat[i].begin(), mat[i].end());
    }
}

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

int main()
{
    int n;
    cin >> n;

    // initializ vector arr of n rows and n columns
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
    }

    rotateMatrix(arr);
    printMatrix(arr);
    return 0;
}