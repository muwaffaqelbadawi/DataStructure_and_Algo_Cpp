#include<bits/stdc++.h>
using namespace std;

void printP1(int n) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void printP2(int n) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void printP3(int n) {
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j <<" ";
        }
        cout << endl;
    }
}
void printP4(int n) {
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i <<" ";
        }
        cout << endl;
    }
}
void printP5(int n) {
    for (int i = 0; i <= n; i++)
    {
        for(int j=0; j<=n-i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}
void printP6(int n) {
    for (int i = 1; i <= n; i++)
    {
        for(int j=1; j<=n-i+1; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}
void printP7(int n) {
    for (int i = 0; i<n; i++) {
        for(int j=0; j<n-i-1; j++) {
            // Space
            cout << " ";
        }

        for (int k=0; k<2*i+1; k++) {
            // Stars
            cout << "*";
        }

        for (int l=0; l<n-i-1; l++) {
            // Spaces
            cout << " ";
        }
        cout << endl;
    }
    
}
void printP8(int n) {
    for (int i = 0; i<n; i++) {

        for(int j=0; j<i; j++) {
            // Space
            cout << " ";
        }

        for (int k=0; k<2*(n-i)-1; k++) {
            // Stars
            cout << "*";
        }

        for (int l=0; l<i; l++) {
            // Spaces
            cout << " ";
        }
        cout << endl;
    }
    
}

int main() {
    int t;
    cin >> t;

    for(int i=0; i<t; i++) {
        int n;
        cin >> n;
        printP8(n);
    }

    return 0;
}

