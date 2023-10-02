#include <bits/stdc++.h>
using namespace std;

// print numbers from n to 1 using recursion and back_track

void descending(int i, int n)
{
    if (i > n)
        return;

    descending(i + 1, n);
    cout << i << endl;
}
// Summation using parameterized Recursion
int sumParameterized(int i, int sum)
{
    if (i < 0)
        return sum;
    return sumParameterized(i - 1, sum + i);
}
// Find sum of first n numbers using functional Recursion
// Using in dynamic programming (dp)
int sumFunctional(int n)
{
    if (n == 0)
        return 0;
    return n + sumFunctional(n - 1);
}
long long factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

void Reverse_Arr(int i, int Arr[], int n)
{
    if (i >= n/2)
        return;
    swap(Arr[i], Arr[n-i-1]);
    Reverse_Arr(i+1, Arr, n);
}

int main()
{
    int t;
    cin >> t;

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < t; i++)
    {
        for (int i = 0; i < n; i++) cin >> arr[i];
        Reverse_Arr(0, arr, n);
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
    }
    return 0;
}
