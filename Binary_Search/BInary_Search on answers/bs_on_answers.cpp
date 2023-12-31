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

// Iterative approach
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

// Minimum days to days to make m X k Bouquets
int maxiDay(vector<int> &arr)
{
    int maxi = INT_MIN;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}
int miniDay(vector<int> &arr)
{
    int mini = INT_MAX;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, arr[i]);
    }
    return mini;
}
bool Possible(vector<int> arr, int day, int m, int k)
{
    int cnt = 0;
    int NoOfB = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= day)
        {
            cnt++;
        }

        else
        {
            NoOfB += (cnt / k);
            cnt = 0;
        }
    }
    NoOfB += (cnt / k);
    return NoOfB >= m;
}
int roseGarden(vector<int> arr, int k, int m)
{
    long long val = m * 1ll * k * 1ll;
    int n = arr.size();

    if (val > n)
    {
        return -1;
    }

    int low = miniDay(arr), high = maxiDay(arr);
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (Possible(arr, mid, m, k))
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

// Find the smallest division
int maxiNumber(vector<int> &arr)
{
    int maxi = INT_MIN;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}
int sum(vector<int> arr, int mid)
{
    int cnt = 0;
    int divSum = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        divSum += ceil((double)(arr[i]) / (double)(mid));
    }
    return divSum;
}
int smallestDivisor(vector<int> &arr, int limit)
{
    int n = arr.size();

    if(n > limit)
    {
        return -1;
    }

    int low = 1, high = maxiNumber(arr);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (sum(arr, mid) <= limit)
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

// Capacity to ship package
int maxiLoad(vector<int> &weights)
{
    int maxi = INT_MIN;
	int n = weights.size();
    for(int i=0; i<n; i++)
    {
        maxi = max(maxi, weights[i]);
    }
    return  maxi;
}
int summation(vector<int> &weights)
{
    int sum = 0;
    int n = weights.size();

    for(int i=0; i<n; i++)
    {
        sum += weights[i];
    }
    return sum;
}
int func(vector<int> &weights, int d)
{
    int days = 1, load = 0;
    int n = weights.size();

    for(int i=0; i<n; i++)
    {
        if((load + weights[i]) > d)
        {
            days++;
            load = weights[i];
        }

        else
        {
            load += weights[i];
        }
    }
    return days;
}
int leastWeightCapacity(vector<int> &weights, int d)
{
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    while(low <= high)
    {
        int mid = (low +high) / 2;
        int daysReq = func(weights, mid);
        
        if(daysReq <= d)
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

// Find the Kth missing number
int missingK(vector<int> vec, int n, int k)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1);
        if (missing < k)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }
    return low + k;
    // return high + k + 1
}

// Aggressive Cows
// Can we place is a helper function
// TC ---> O(N Log N) + [ O(Log2 (arr[n-1] - arr[0] + 1)) * O(N) ]
// SC ---> O(1)
bool canWePlace(vector<int> &stalls, int dist, int k)
{
    // C1 will always be at first place
    // k = number of cows
    int cntCows = 1;
    int last = stalls[0];
    int n = stalls.size();
    
    for(int i=0; i<n; i++)
    {
        if((stalls[i] - last) >= dist)
        {
            cntCows++;
            last = stalls[i];
        }

        if(cntCows >= k)
        {
            return true;
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());

    int n = stalls.size();
    int low = 0;
    int high = stalls[n-1] - stalls[0];

    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(canWePlace(stalls, mid, k) == true)
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


// Books Allocation
// n = number of pages
// m = number of students
int func(vector<int> &arr, int pages)
{
    int students = 1;
    long long pagesStudent = 0;
    int n = arr.size();

    for(int i=0; i<n; i++)
    {
        if(pagesStudent + arr[i] <= pages)
        {
            // add pages to current student
            pagesStudent += arr[i];
        }

        else
        {
            // add pages to the next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}
int findPages(vector<int>& arr, int n, int m) {
    if(m > n)
    {
        return -1;
    }

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while(low <= high)
    {
        int mid = (low + high) / 2;
        int students = func(arr, mid);

        if(students > m)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }
    return  low;
}

// Minimize Max Distance to Gas Station - Brute
// k = number of gas stations to place
long double minimizeMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howMany(n - 1, 0);

    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        long double maxSection = -1;
        int maxIndex = -1;

        for (int i = 0; i < n - 1; i++)
        {
            long double diff = arr[i + 1] - arr[i];
            long double sectionLength = diff / ((long double)(howMany[i] + 1));

            if (sectionLength > maxSection)
            {
                maxSection = sectionLength;
                maxIndex = i;
            }
        }
        // insert the current gas station
        howMany[maxIndex]++;
    }
    long double maxAns = -1;

    for (int i = 0; i < n - 1; i++)
    {
        long double diff = arr[i + 1] - arr[i];
        long double sectionLength = diff / ((long double)(howMany[i] + 1));
        maxAns = max(maxAns, sectionLength);
    }
    return maxAns;
}

main()
{
    int x;
    cin >> x;
    vector<int> arr = {3, 5, 8, 15, 19};
    return 0;
}