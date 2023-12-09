#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &arr)
{
    int max = arr[0];

    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

// 1- Unique remembered names
vector<string> findUniqueFriendsNames(map<string, int> &friendBirthdayMap, vector<string> friendBirthdays, vector<string> friendNames)
{
    vector<string> uniqueBirthdays;
    vector<int> uniqueIndices;
    vector<string> rememberedNames;

    // Determine unique birthdays
    for (const auto &birthday : friendBirthdayMap)
    {
        if (birthday.second == 1)
        {
            uniqueBirthdays.push_back(birthday.first);
        }
    }

    // Determine unique IDs of the birthdays
    for (int i = 0; i < uniqueBirthdays.size(); i++)
    {
        auto it = find(friendBirthdays.begin(), friendBirthdays.end(), uniqueBirthdays[i]);
        int uniqueInd = distance(friendBirthdays.begin(), it);
        uniqueIndices.push_back(uniqueInd);
    }

    // Determine the remembered names
    for (int i = 0; i < uniqueIndices.size(); i++)
    {
        rememberedNames.push_back(friendNames[uniqueIndices[i]]);
    }

    return rememberedNames;
}

// 2- Determine friends with maximum likes (in case of collision)
vector<string> findCollisionFriendsNames(vector<string> friendBirthdays, vector<int> friendLikes, vector<string> friendNames)
{
    set<int> maxLikesOutOfCollisions;
    vector<string> rememberedNames;

    // Determine the indices of similar birthdays
    for (int i = 0; i < friendBirthdays.size(); i++)
    {
        vector<int> maxCorrespondingLikesOfSimilarBirthdays;
        for (int j = i + 1; j < friendBirthdays.size(); j++)
        {
            if (j == friendBirthdays.size() - 1 && maxCorrespondingLikesOfSimilarBirthdays.size() > 0)
            {
                maxCorrespondingLikesOfSimilarBirthdays.push_back(friendLikes[i]);
            }

            if (friendBirthdays[i] == friendBirthdays[j])
            {
                maxCorrespondingLikesOfSimilarBirthdays.push_back(friendLikes[j]);
            }
        }

        // Find maximum only if the array of size 2 or greater
        if (!maxCorrespondingLikesOfSimilarBirthdays.empty())
        {
            // Find friend with maximum likes
            int maxLike = findMax(maxCorrespondingLikesOfSimilarBirthdays);
            maxLikesOutOfCollisions.insert(maxLike);
        }
    }

    // Determine maximum likes indices
    for (const auto likes : maxLikesOutOfCollisions)
    {
        for (int j = 0; j < friendLikes.size(); j++)
        {
            if (likes == friendLikes[j])
            {
                // corresponding friend index
                rememberedNames.push_back(friendNames[j]);
            }
        }
    }
    return rememberedNames;
}

// 3- Print number of friends and their names
void WishingHBD(int noOFriends, int likes, string name, string birthday, vector<string> friendNames, vector<int> friendLikes, vector<string> friendBirthdays, map<string, int> friendBirthdayMap)
{
    vector<string> uniqueFriendsNams = findUniqueFriendsNames(friendBirthdayMap, friendBirthdays, friendNames);

    // Maximum like collection
    vector<string> collisionFriendsNames = findCollisionFriendsNames(friendBirthdays, friendLikes, friendNames);

    int friendNumber = uniqueFriendsNams.size() + collisionFriendsNames.size();

    cout << friendNumber << endl;

    for (int i = 0; i < uniqueFriendsNams.size(); i++)
    {
        cout << uniqueFriendsNams[i] << endl;
    }

    for (int i = 0; i < collisionFriendsNames.size(); i++)
    {
        cout << collisionFriendsNames[i] << endl;
    }
}

int main()
{
    int noOFriends, likes;
    cin >> noOFriends;

    string name, birthday;

    vector<string> friendNames, friendBirthdays;
    vector<int> friendLikes;

    map<string, int> friendBirthdayMap;

    for (int i = 0; i < noOFriends; i++)
    {
        cin >> name >> likes >> birthday;

        friendNames.push_back(name);
        friendLikes.push_back(likes);
        friendBirthdays.push_back(birthday);

        // Determine collision birthdays
        friendBirthdayMap[birthday] += 1;
    }

    WishingHBD(noOFriends, likes, name, birthday, friendNames, friendLikes, friendBirthdays, friendBirthdayMap);

    return 0;
};