#include <bits/stdc++.h>
using namespace std;

// Select minimums & swap
void selection_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int minimum = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[minimum])
            {
                minimum = j;
            }
        }
        int temp = arr[minimum];
        arr[minimum] = arr[i];
        arr[i] = temp;
    }
}
void bubble_sort(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        int didSwap = 0;
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                didSwap = 1;
            }
        }
        if (didSwap == 0)
        {
            break;
        }
        cout << "runs" << endl;
    }
}
void insersion_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    insersion_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
