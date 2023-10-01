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

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        // Test Cases
        int x;
        cin >> x;

        // bool all_divisions = isArmstrongNumber(x);
        all_divisions(x);
    }

    return 0;
}
