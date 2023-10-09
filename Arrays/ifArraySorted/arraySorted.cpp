#include <bits/stdc++.h>
using namespace std;

bool ArraySorted(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] >= arr[i - 1])
        {
        }
        else
        {
            return false;
        }
    }
    return true;
}
int removeDuplicates(vector<int> &arr)
{
    int i = 0;
    for (int j = 1; j < arr.size() - 1; j++)
    {
        if (arr[j] != arr[i])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    return i + 1;
}
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


// bitwise xor operator is the caret symbol ^
int missingNumber(vector<int> &a, int N)
{
    int xor1 = 0, xor2 = 0;
    int n = N - 1;

    for (int i = 0; i < n; i++)
    {
        xor2 = xor1 ^ a[i];
        xor1 = xor1 ^ (n + 1);
    }

    return xor1 ^ xor2;
}

int main()
{
    int n;
    vector<int> arr;

    while (cin >> n)
    {
        arr.push_back(n);
    }

    int slargest = ArraySorted(arr);
    cout << slargest;

    return 0;
}
