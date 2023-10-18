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
    if (n == 0) return 0;
    return n + sumFunctional(n - 1);
}
long long factorial(int n)
{
    if (n == 0) return 1;
    return n * factorial(n - 1);
}
void Reverse_Arr(int i, int Arr[], int n)
{
    if (i >= n / 2) return;


    nd--(Arr[i], Arr[n - i - 1]);
    return Reverse_Arr(i + 1, Arr, n);
}
bool isStringPalindrome(int i, string &str)
{
    // second base case
    if (i >= str.size() / 2) return true;

    // first base case
    if (str[i] != str[str.size() - i - 1]) return false;

    // else go to the next call
    return isStringPalindrome(i + 1, str);
}
int fib(int n) {
    if(n <= 1) return n;

    int last = fib(n - 1);
    int slast = fib(n - 2);
    return last + slast;
}




int main()
{
    /* int t;
    cin >> t; */

    int n;
    cin >> n;

    // string str;
    // cin >> str;


    int genFib = fib(n);
    cout << genFib;

    // cout << endl;

    // for (int i = 0; i < n; i++) cout << str[i];

    /* for (int i = 0; i < t; i++)
    {
        
    } */
    return 0;
}
