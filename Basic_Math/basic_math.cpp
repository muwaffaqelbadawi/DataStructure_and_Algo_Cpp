#include <bits/stdc++.h>
using namespace std;

int extract_digits(int x)
{
    int number_of_digits = 0;
    while (x > 0)
    {
        x = x / 10;
        number_of_digits++;
    }
    return number_of_digits;
}
int extract_digits_log(int x)
{
    int number_of_digits = (int)(log10(x) + 1);
    return number_of_digits;
}
int reverse_of_a_number(int x)
{
    int reversed_num = 0;
    while (x > 0)
    {
        int last_digit = x % 10;
        reversed_num = (reversed_num * 10) + last_digit;
        x = x / 10;
    }
    return reversed_num;
}
bool isPalindrome(int x)
{
    int dup = x;
    int reversed_num = 0;
    while (x > 0)
    {
        int last_digit = x % 10;
        reversed_num = (reversed_num * 10) + last_digit;
        x = x / 10;
    }
    if (reversed_num == dup)
        return true;
    return false;
}
bool isArmstrongNumber(int x)
{
    int dup = x;
    int power = (int)(log10(dup) + 1);
    int sum = 0;
    while (x > 0)
    {
        int last_digit = x % 10;
        sum = sum + pow(last_digit, power);
        x = x / 10;
    }
    if (sum == dup)
        return true;
    return false;
}
void all_divisions(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << endl;
        }
    }
}
vector<int> all_divisions2(int n)
{
    vector<int> ls;

    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ls.push_back(i);

            if (n / i != i)
            {
                ls.push_back(n / i);
            }
        }
    }
    sort(ls.begin(), ls.end());
    return ls;
}
bool isPrime(int n)
{
    int count = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            count++;

            if (n / i != i)
            {
                count++;
            }
        }
    }
    if (count == 2)
        return true;
    return false;
}
int GCD(int n1, int n2)
{
    int gcd = 1;
    for (int i = min(n1, n2); i > 1; i--)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            gcd = i;
            break;
        }
    }
    return gcd;
}
int GCD1(int n1, int n2)
{
    while (n1 > 0 && n2 > 0)
    {
        if (n1 > n2) n1 = n1 % n2;
        else n2 = n2 % n1;
    }
    if (n1 == 0) return n2;
    return n1;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        // Test Cases
        int n1;
        int n2;
        cin >> n1 >> n2;

        int gcd = GCD(n1, n2);
        cout << gcd;

        // C++ forEach loop
        /* for (auto it : all_divisions)
        {
            cout << it << endl;
        } */
    }
    return 0;
}
