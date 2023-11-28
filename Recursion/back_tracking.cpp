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
    // nd--(Arr[i], Arr[n - i - 1]);
    return Reverse_Arr(i + 1, Arr, n);
}

// 
bool isStringPalindrome(int i, string &str)
{
    // second base case
    if (i >= str.size() / 2) return true;

    // first base case
    if (str[i] != str[str.size() - i - 1]) return false;

    // else go to the next call
    return isStringPalindrome(i + 1, str);
}

// Fib
int fib(int n) {
    if(n <= 1) return n;

    int last = fib(n - 1);
    int slast = fib(n - 2);
    return last + slast;
}

// N Queen
class Solution
{
public:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> leftrow,
               vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0)
            {
                board[row][col] = 'Q';
                leftrow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
                board[row][col] = '.';
                leftrow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> bord(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            bord[i] = s;
        }
        vector<int> leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve(0, bord, ans, leftrow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }
};

// Sudoku solver
class Solution
{

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }

public:
    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == c)
            {
                return false;
            }

            if (board[row][i] == c)
            {
                return false;
            }

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            {
                return false;
            }
        }
        return true;
    }

public:
    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isValid(board, i, j, c))
                        {
                            board[i][j] = c;

                            if (solve(board))
                            {
                                return true;
                            }

                            else
                            {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};




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
