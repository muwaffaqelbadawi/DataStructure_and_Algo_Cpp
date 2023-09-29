#include <bits/stdc++.h>
using namespace std;

void printP1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void printP2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void printP3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void printP4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
void printP5(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void printP6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void printP7(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // Space
            cout << " ";
        }

        for (int k = 0; k < 2 * i + 1; k++)
        {
            // Stars
            cout << "*";
        }

        for (int l = 0; l < n - i - 1; l++)
        {
            // Spaces
            cout << " ";
        }
        cout << endl;
    }
}
void printP8(int n)
{
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < i; j++)
        {
            // Space
            cout << " ";
        }

        for (int k = 0; k < 2 * (n - i) - 1; k++)
        {
            // Stars
            cout << "*";
        }

        for (int l = 0; l < i; l++)
        {
            // Spaces
            cout << " ";
        }
        cout << endl;
    }
}
void printP9(int n)
{
    for (int i = 0; i <= n; i++)
    {

        for (int j = 0; j < n - 1; j++)
        {
            // Space
            cout << " ";
        }

        for (int k = 0; k < i; k++)
        {
            // Stars
            cout << "*";
        }

        for (int l = 0; l < n - i; l++)
        {
            // Spaces
            cout << " ";
        }
        cout << endl;
    }
}
void printP10(int n)
{
    for (int i = 0; i <= n; i++)
    {

        for (int j = 0; j < n - 1; j++)
        {
            // Space
            cout << " ";
        }

        for (int k = 0; k < n - i + 1; k++)
        {
            // Stars
            cout << "*";
        }

        for (int l = 0; l < i; l++)
        {
            // Spaces
            cout << " ";
        }
        cout << endl;
    }
}
void printP101(int n)
{
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars_num = i;
        if (i > n)
            stars_num = 2 * n - i;

        for (int j = 1; j <= stars_num; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}
void printP11(int n)
{
    int start = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            start = 1;
        else
            start == 0;
        for (int j = 0; j <= i; j++)
        {
            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }
    
};

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        // Test Cases
        int n;
        cin >> n;
        printP11(n);
    }

    return 0;
}
