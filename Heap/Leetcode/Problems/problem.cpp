#include <bits/stdc++.h>
using namespace std;

/*

vector<string> findRelativeRanks1(const vector<int> &score)
{
    priority_queue<pair<int, int>> pq; // Pair of score and index
    vector<string> rankList(score.size());

    for (int i = 0; i < score.size(); i++)
    {
        pq.push({score[i], i});
    }

    int ind = 0;
    while (!pq.empty() && ind < score.size())
    {
        int currentScore = pq.top().first;
        int currentInd = pq.top().second;
        pq.pop();

        if (ind == 0)
        {
            rankList[currentInd] = "Gold Medal";
        }

        else if (ind == 1)
        {
            rankList[currentInd] = "Silver Medal";
        }

        else if (ind == 2)
        {
            rankList[currentInd] = "Bronze Medal";
        }

        else
        {
            rankList[currentInd] = to_string(ind + 1);
        }

        ind++;
    }

    return rankList;
}

vector<string> findRelativeRanks2(vector<int> &score)
{
    int n = score.size();

    priority_queue<pair<int, int>> pq;
    vector<string> res(n, "");
    string medals[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};

    for (int i = 0; i < n; ++i)
    {
        pq.push({score[i], i});
    }

    for (int i = 0; i < n; ++i)
    {
        int idx = pq.top().second;
        pq.pop();

        if (i < 3)
        {
            res[idx] = medals[i];
        }

        else
        {
            res[idx] = to_string(i + 1);
        }
    }
    return res;
}

vector<string> findRelativeRanks3(const vector<int> &score)
{
    priority_queue<pair<int, int>> pq;
    vector<string> rankList(score.size());

    for (int i = 0; i < score.size(); i++)
    {
        pq.push({score[i], i});
    }

    int ind = 0;

    while (!pq.empty() && ind < score.size())
    {
        int curInd = pq.top().second;

        if (ind == 0)
        {
            rankList[curInd] = "Gold Medal";
        }

        else if (ind == 1)
        {
            rankList[curInd] = "Silver Medal";
        }

        else if (ind == 2)
        {
            rankList[curInd] = "Bronze Medal";
        }

        else
        {
            rankList[curInd] = to_string(ind + 1);
        }
        pq.pop();
        ++ind;
    }
    return rankList;
}

long long pickGifts(vector<int> &gifts, int k)
{
    priority_queue<int> pq;
    long long sum = 0;

    for (int i = 0; i < gifts.size(); i++)
    {
        pq.push(gifts[i]);
        sum += gifts[i];
    }

    while (k--)
    {
        long long temp = static_cast<long long>(sqrt(pq.top()));

        // Remove the original element from the sum
        sum -= pq.top();
        pq.pop();

        // Push the modified element back to the queue
        pq.push(temp);

        // Add the modified element to the sum
        sum += temp;
    }
    return sum;
}

int maxProduct(vector<int> &nums)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int &number : nums)
    {
        pq.push(number);

        if (pq.size() > 2)
        {
            pq.pop();
        }
    }

    int max1 = pq.top();
    pq.pop();
    int max2 = pq.top();

    return (max1 - 1) * (max2 - 1);
}

// lambda approach
int minNonZeroElLambda(const vector<int> &nums)
{
    auto it = min_element(nums.begin(), nums.end(), [](int a, int b) { return a > 0 && (b == 0 || a < b); });

    return (it != nums.end()) ? *it : INT_MAX;
}

int minNonZeroEl(vector<int> &nums)
{
    int minEl = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            minEl = min(minEl, nums[i]);
        }
    }
    return minEl;
}

int minimumOperations(vector<int> &nums)
{
    int sumNums = accumulate(nums.begin(), nums.end(), 0);
    int cnt = 0;

    if (sumNums == 0)
    {
        return 0;
    }

    while (sumNums > 0)
    {
        int x = minNonZeroEl(nums);

        // How many times decrementing occurs
        int dec = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                nums[i] -= x;
                ++dec;
            }
        }

        sumNums -= x * dec;
        ++cnt;
    }
    return cnt;
}

// Brute force (naive)
int deleteGreatestValue1(vector<vector<int>> &grid)
{
    int m = grid.size();
    int cnt = 0;
    while (any_of(grid.begin(), grid.end(), [](const vector<int> &row) { return !row.empty(); }))
    {
        vector<int> maxElements;
        for (int i = 0; i < m; i++)
        {
            int maxi = INT_MIN;
            pair<int, pair<int, int>> maxElInd;

            int n = grid[i].size();
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] > maxi)
                {
                    maxi = grid[i][j];
                    maxElInd = make_pair(maxi, make_pair(i, j));
                }
            }

            int maxEl = maxElInd.first;
            int ith, jth;
            tie(ith, jth) = maxElInd.second;

            maxElements.push_back(maxEl);
            grid[ith].erase(grid[ith].begin() + jth);
        }
        cnt += *max_element(maxElements.begin(), maxElements.end());
    }
    return cnt;
}

// Brute force (naive)
int deleteGreatestValue2(vector<vector<int>> &grid)
{
    int m = grid.size();

    for (int i = 0; i < m; i++)
    {
        sort(grid[i].begin(), grid[i].end());
    }

    int cnt = 0;
    while (any_of(grid.begin(), grid.end(), [](const vector<int> &row) { return !row.empty(); }))
    {
        vector<int> maxElements;

        for (int i = 0; i < m; i++)
        {
            if (!grid[i].empty())
            {
                int maxEl = grid[i].back();
                grid[i].pop_back();
                maxElements.push_back(maxEl);
            }
        }
        cnt += *max_element(maxElements.begin(), maxElements.end());
    }
    return cnt;
}

// Brute with Priority Queue
int deleteGreatestValueOpt(vector<vector<int>> &grid)
{
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>> pq;

    int cnt = 0;

    int m = grid.size();

    while (any_of(grid.begin(), grid.end(), [](const vector<int> &row) { return !row.empty(); }))
    {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>> maxPQ;

        for (int i = 0; i < m; i++)
        {
            int n = grid[i].size();

            for (int j = 0; j < n; j++)
            {
                pq.push(make_tuple(grid[i][j], i, j));
            }

            int maxEl, ith, jth;
            tie(maxEl, ith, jth) = pq.top();

            maxPQ.push(pq.top());
            grid[ith].erase(grid[ith].begin() + jth);

            while (!pq.empty())
            {
                pq.pop();
            }
        }
        cnt += get<0>(maxPQ.top());
    }
    return cnt;
}

// Better (priority Queue)

*/


int deleteGreatestValueBetter(vector<vector<int>> &grid)
{
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>> pq;

    int cnt = 0;

    int m = grid.size();

    for (int i = 0; i < m; i++)
    {
        int n = grid[i].size();
        for (int j = 0; j < n; j++)
        {
            pq.push(make_tuple(grid[i][j], i, j));
        }
    }

    while (!pq.empty())
    {
        vector<tuple<int, int, int>> temp;
        vector<bool> checkList(m, false);

        while (accumulate(checkList.begin(), checkList.end(), 0) < m)
        {
            int greatEl, ith, jth;
            tie(greatEl, ith, jth) = pq.top();

            // If all rows are false
            if (accumulate(checkList.begin(), checkList.end(), 0) == 0)
            {
                checkList[ith] = true;
                cnt += greatEl;
                pq.pop();
            }
 
            else if (!checkList[ith])
            {
                checkList[ith] = true;
                pq.pop();
            }

            else
            {
                temp.push_back(pq.top());
                pq.pop();
            }
        }

        while (!temp.empty())
        {
            pq.push(temp.back());
            temp.pop_back();
        }
    }
    return cnt;
}

int main()
{
    vector<vector<int>> grid = {{5, 10, 98, 2}, {13, 80, 6, 3}, {60, 66, 5, 82}, {35, 42, 16, 9}};
    int result = deleteGreatestValueBetter(grid);
    cout << result << endl;
    return 0;
}