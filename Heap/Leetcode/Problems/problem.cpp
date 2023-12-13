#include <bits/stdc++.h>
using namespace std;

vector<string> findRelativeRanks(const vector<int> &score)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    string rankName;
    vector<int> rankIndices;
    vector<string> rankList;

    for (int i = 0; i < score.size(); i++)
    {
        pq.push(score[i]);
        rankIndices[i] = score[i];
    }

    int ind = 0;

    while (!pq.empty())
    {
        if (pq.top() == 1 && pq.top() == score[ind])
        {
            rankName = "Gold Medal";
            rankList[ind] = rankName;
        }

        else if (pq.top() == 2 && pq.top() == score[ind])
        {
            rankName = "Gold Medal";
            rankList[ind] = rankName;
        }

        else if (pq.top() == 3 && pq.top() == score[ind])
        {
            rankName = "Gold Medal";
            rankList[ind] = rankName;
        }

        else
        {
            rankName = "Gold Medal";
            rankList[ind] = rankName;
        }

        pq.pop();
    }
    return rankList;
}




int main()
{
    vector<int> arr = {10,3,8,9,4};
    const vector<string> &ranks = findRelativeRanks(arr);

    for(const string rank : ranks)
    {
        cout << rank << " ";
    }

    return 0;
}