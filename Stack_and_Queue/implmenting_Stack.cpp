#include <bits/stdc++.h>
using namespace std;



// Valid Parentheses
bool isValidParenthesis(string s)
{
    int n = s.size();
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);

        else
        {
            if (st.empty())
                return false;
            char c = st.top();
            st.pop();
            if ((s[i] == ')' && c == '(') || (s[i] == '}' && c == '{') || (s[i] == ']' && c == '['))
            {
            }

            else
                return false;
        }
    }
    if (st.empty())
        return true;
    return false;
}


// Next Greater Element II
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i % n])
            {
                st.pop();
            }

            if (i < n)
            {
                if (!st.empty())
                    nge[i] = st.top();
            }
            st.push(nums[i % n]);
        }
        return nge;
    }
};





int main()
{
    return 0;
}