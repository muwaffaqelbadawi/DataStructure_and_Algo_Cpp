#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;

    // Top border
    cout << "+";
    for (int k = 0; k < n; k++) cout << "-";
    cout << "+";
    cout << endl;
    

    // Middle Section
    for (int i = 0; i < n; i++)
    {
        cout << "|";
        for (int k = 0; k < n; k++) cout << " ";
        cout << "|";
        cout << endl;
    }
    
    
    // Bottom Border
    cout << "+";
    for (int k = 0; k < n; k++) cout << "-";
    cout << "+";
    cout << endl;
};