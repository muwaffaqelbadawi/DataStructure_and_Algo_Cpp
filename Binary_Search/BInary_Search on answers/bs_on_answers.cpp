#include <bits/stdc++.h>
using namespace std;


// Square Root of a number
int floorSqrt(int n)
{
    int low = 1, high = n;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long value = mid * mid;

        if ((mid * mid) <= n)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }
    return high;
}

// Binary exponentiation approach
int func(int mid, int n)
{
  long long ans = 1;
  while(n > 0)
  {
    if(n % 2 == 1)
    {
      ans *= mid;
      n -= 1;
    }

    else
    {
      mid *= mid;
      n /= 2;
    }
  }
  // mid ^ n
  return ans;
}

// Find Nth Root Of M
int NthRoot1(int n, int m)
{
    int low = 1, high = m;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (func(mid, n) == m)
        {
            return mid;
        }

        if (pow(mid, n) < m)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

// Iterative aproach
int funcI(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= mid;

        if (ans > m)
        {
            return 2;
        }
    }
    if (ans == m)
    {
        return 1;
    }

    return 0;
}

// Find Nth Root Of M
int NthRoot2(int n, int m)
{
    int low = 1, high = m;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midN = funcI(mid, n, m);

        if (midN == 1)
        {
            return mid;
        }

        else if (midN == 0)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

// Koko Eating Bananas
int findMax(vector<int> &v)
{
    int maxi = INT_MIN;
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}
long long calculateTotalHours(vector<int> &v, int hourly)
{
    long long totalHours = 0;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        totalHours += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalHours;
}
int minimumRateToEatBananas(vector<int> v, int h)
{
    int low = 1, high = findMax(v);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        long long totalHours = calculateTotalHours(v, mid);

        if (totalHours <= h)
        {
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }
    return low;
}




main()
{
    int x;
    cin >> x;
    vector<int> arr = {3, 5, 8, 15, 19};
    return 0;
}