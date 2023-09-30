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
}
void printP12(int n)
{
    for (int i = 1; i < n; i++)
    {
        int start = 1;
        for (int j = start; j <= i; j++)
        {
            cout << start << " ";
            ++start;
        }
        cout << endl;
    }
}
void printP121(int n)
{
    int space = 2 * (n - 1);
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= i; j++)
        {
            // Numbers
            cout << j;
            // ++start;
        }
        //  Space
        for (int k = 1; k <= space; k++)
        {
            // Space
            cout << " ";
        }

        for (int l = i; l >= 1; l--)
        {
            // Reverse numbers
            cout << l;
        }
        cout << endl;
        space -= 2;
    }
}
void printP13(int n)
{
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}
void printP14(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int num = 65;
        for (int j = 1; j <= i; j++)
        {
            cout << char(num);
            num++;
        }
        cout << endl;
    }
}
void printP141(int n)
{
    for (int i = 1; i < n; i++)
    {
        for (char ch = 'A'; ch < 'A' + i; ch++)
        {
            cout << ch;
        }
        cout << endl;
    }
}
void printP15(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + n - i; ch++)
        {
            cout << ch;
        }
        cout << endl;
    }
}
void printP16(int n)
{

    for (int i = 1; i <= n; i++)
    {
        char ch = 'A' + i - 1;

        /* int num = 65;
        for (int j=1; j<=i; j++) {
            cout << char(num);
        }
        cout << endl;
        num++;
        */

        for (int j = 1; j <= i; j++)
        {
            cout << ch;
        }
        cout << endl;
    }
}
void printP17(int n)
{
    for (int i = 0; i < n; i++)
    {
        // Space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        // Characters
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (int k = 1; k <= 2 * i + 1; k++)
        {
            cout << ch;

            // Observ Symmetry
            if (k <= breakpoint)
                ch++;
            else
                ch--;
        }

        // Space
        for (int l = 1; l < n - i - 1; l++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void printP18(int n)
{
    /* for(int i=0; i<n; i++)
    {
        char ch = 'A' + i;
        for(int j=i; j<n; j++)
        {
            cout << ch;
            ch++;
        }
        cout << endl;
    } */

    for (int i = 0; i < n; i++)
    {
        /* char ch = 'E' - i;
        for (int j = 0; j <= i; j++)
        {
            cout << ch;
            ch++;
        } */

        for (char ch = 'E' - i; ch <= 'E'; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}
void printP19(int n)
{
    for (int i = 0; i <= 2 * n; i++)
    {
        int stars_num = n - i;
        int space_num = 2 * i;
        if (i > n)
        {
            stars_num = i - n;
            space_num = 2 * (2 * n - i);
        }
        // Stars
        for (int j = 1; j <= stars_num; j++)
        {
            cout << "*";
        }
        // Spaces
        for (int k = 1; k <= space_num; k++)
        {
            cout << " ";
        }
        // Stars
        for (int l = 1; l <= stars_num; l++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void printP191(int n)
{
    int spaces = 0;
    for (int i = 0; i < n; i++)
    {
        // Stars
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        // Spaces
        for (int k = 1; k <= spaces; k++)
        {
            cout << " ";
        }
        // Stars
        for (int l = 1; l <= n - i; l++)
        {
            cout << "*";
        }
        spaces += 2;
        cout << endl;
    }

    spaces = 2 * n - 2;
    for (int i = 1; i <= n; i++)
    {
        // Stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        // Spaces
        for (int k = 0; k < spaces; k++)
        {
            cout << " ";
        }
        // Stars
        for (int l = 1; l <= i; l++)
        {
            cout << "*";
        }
        spaces -= 2;
        cout << endl;
    }
}
void printP20(int n)
{

    for (int i = 0; i < n; i++)
    {

        // Stars
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        // Spaces
        for (int k = 0; k < 2 * (n - i - 1); k++)
        {
            cout << " ";
        }
        // Stars
        for (int l = 0; l <= i; l++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 1; i < n; i++)
    {
        // Stars
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        // Spaces
        for (int k = 0; k < 2 * i - 1; k++)
        {
            cout << " ";
        }
        // Stars
        for (int l = 0; l <= n - i; l++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void printP201(int n)
{
    int spaces = 2 * n - 2;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;
        // Stars
        for (int j = 0; j < stars; j++)
        {
            cout << "*";
        }
        // Spaces
        for (int k = 0; k <= spaces; k++)
        {
            cout << " ";
        }
        // Stars
        for (int l = 0; l < stars; l++)
        {
            cout << "*";
        }
        cout << endl;
        if (i < n)
            spaces -= 2;
        else
            spaces += 2;
    }
}
void printP21(int n)
{
    for (int i = 0; i < n; i++)
    {
        // Stars
        for (int j = 0; j < n; j++)
        {
            // Spaces
            // Short circuiting
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
                cout << "*";

            else
                cout << " ";
        }
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        // Test Cases
        int n;
        cin >> n;
        printP21(n);
    }
    return 0;
}

/* char ch = 'A';
    cout << char(ch + 1) << endl;
    cout << char(char(65) + 1);
*/