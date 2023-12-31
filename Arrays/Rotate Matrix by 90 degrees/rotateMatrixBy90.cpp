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
    int preSum = 0;
    int cnt = 0;
    map<int, int> mpp;
    mpp[preSum]++;

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
// Find all the combination
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
vector<vector<int>> pascalTriangle1(int N)
{
    vector<vector<int>> ans;
    for (int i = 1; i <= N; i++)
    {
        ans.push_back(generateRow(i));
    }
    return ans;
}

// Printing Pascal Triangle
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

// Majority Element II (> floor(n / 3))
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

// Three Sum - Brute TC---> ~ O(n^3) Time Limit Exceeded
vector<vector<int>> triplet1(int n, vector<int> &arr)
{
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// Three Sum - Better Solution
vector<vector<int>> triplet2(int n, vector<int> &arr)
{
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            int third = -(arr[i] + arr[j]);
            // chack if the element is exist in the set
            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// 3 Sum - O.P.
vector<vector<int>> triplet3(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }

        int j = i + 1;
        int k = n - 1;

        // as long as j less than k
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];

            if (sum < 0)
            {
                j++;
            }

            else if (sum > 0)
            {
                k--;
            }

            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;

                while (j < k && arr[j] == arr[j - 1])
                {
                    j++;
                }

                while (j < k && arr[k] == arr[k + 1])
                {
                    k--;
                }
            }
        }
    }
    return ans;
}

// 4 Sum - Brute
vector<vector<int>> fourSum1(vector<int> &nums, int target)
{
    int n = nums.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < n; l++)
                {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if (sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// 4 Sum - Better
vector<vector<int>> fourSum2(vector<int> &nums, int target)
{
    int n = nums.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<long long> hashset;
            for (int k = j + 1; k < n; k++)
            {
                long long sum = nums[i] + nums[j];
                sum += nums[k];

                long long fourth = target - (sum);
                if (hashset.find(fourth) != hashset.end())
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)(fourth)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// 4 Sum - O.P.
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j != i + 1 && nums[j] == nums[j - 1])
                continue;
            int k = i + 1;
            int l = n - 1;
            while (k < l)
            {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;

                    while (k < l && nums[k] == nums[k - 1])
                    {
                        k++;
                    }

                    while (k < l && nums[l] == nums[l + 1])
                    {
                        l--;
                    }
                }

                else if (sum < target)
                {
                    k++;
                }

                else
                {
                    l--;
                }
            }
        }
    }
    return ans;
}

// Find all subarrays with XOR K
int subarraysWithXORK(vector<int> arr, int k)
{
    int frontXOR = 0;
    int cnt = 0;
    map<int, int> mpp;
    mpp[frontXOR]++; // Initially {0, 1}

    for (int i = 0; i < arr.size(); i++)
    {
        frontXOR ^= arr[i];
        int x = frontXOR ^ k;
        cnt += mpp[x];
        mpp[frontXOR]++;
    }
    return cnt;
}

int inTheMap(map<int, int> mpp, int i)
{
    mpp[4] = 0;
    int val = mpp[i];
    return val;
}









int main()
{

    map<int, int> mpp;

    int result = inTheMap(mpp, 7);
    cout << result;

    /* int n;


    vector<int> arr;

    while(cin >> n)
    {
        arr.push_back(n);
    }

    int allsSubWithK = findAllSubarraysWithGivenSum(arr, 3); */
    // cout << allsSubWithK;

    // vector<vector<int>> ans = pascalTriangle(n);
    // printPascalTriangle(ans);

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

    

    // rotateMatrix(arr);
    // printMatrix(arr);
    return 0;
}