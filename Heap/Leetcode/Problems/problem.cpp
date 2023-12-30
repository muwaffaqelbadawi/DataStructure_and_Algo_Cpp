#include <bits/stdc++.h>
using namespace std;

/*
vector<string> findRelativeRanks(const vector<int> &score)
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
*/

/*
vector<string> findRelativeRanks(vector<int> score)
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
*/

/*
vector<string> findRelativeRanks(const vector<int> &score)
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
*/

/*
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
*/

/*
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
*/

/* // lambda approach
int minNonZeroEl(const vector<int> &nums)
{
    auto it = min_element(nums.begin(), nums.end(), [](int a, int b)
                          { return a > 0 && (b == 0 || a < b); });

    return (it != nums.end()) ? *it : INT_MAX;
}
*/

/*
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
*/

pair<int, int> findMax(vector<int> &arr)
{
    int maxi = INT_MIN;
    pair<int, int> maxiInd;
    int n = arr.size();

    for (int i = 0; i < n; i++) 
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
            maxiInd = make_pair(maxi, i);
        }
    }
    return maxiInd;
}

int deleteGreatestValue(vector<vector<int>> &grid)
{
    int m = grid.size();
    int cnt = 0;
    while (!grid[m-1].empty())
    {
        vector<int> maxElements;
        for (int i = 0; i < m; i++)
        {
            int maxEl, Ind;
            tie(maxEl, Ind) = findMax(grid[i]);

            maxElements.push_back(maxEl);
            grid[i].erase(grid[i].begin() + Ind);
        }
        cnt += *max_element(maxElements.begin(), maxElements.end());
    }
    return cnt;



   /*
    priority_queue<pair<int, pair<int, int>>> pq;
    for (int i = 0; i < m; i++)
    {
        int n = grid[i].size();
        for (int j = 0; j < n; j++)
        {
            pq.push({grid[i][j], {i, j}});
        }
    }

    if (pq.size() == 1)
    {
        int row = pq.top().second.first;
        int column = pq.top().second.second;
        grid[row].erase(grid[row].begin() + column);
        cnt += pq.top().first;

        pq.pop();
        return cnt;
    }

    while (!pq.empty())
    {
        int maxEl = INT_MIN;
        for (int i = 0; i < 2; i++)
        {
            int row = pq.top().second.first;
            int column = pq.top().second.second;
            if (column < grid[row].size())
            {
                grid[row].erase(grid[row].begin() + column);
            }

            maxEl = max(maxEl, pq.top().first);
            pq.pop();
        }
        cnt += maxEl;
    }
    return cnt;
 */
}

int main()
{
    vector<vector<int>> grid = {{58, 42, 8, 75, 28}, {35, 21, 13, 21, 72}};
    int result = deleteGreatestValue(grid);
    cout << result << endl;

    return 0;
}