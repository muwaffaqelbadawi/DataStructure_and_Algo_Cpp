#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];

    // precompute
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mpp[arr[i]] += 1;
    }


    int numMaxFreq;
    int maxFreq = 0;

    for(auto it : mpp) {
        if(it.second > maxFreq) {
            numMaxFreq = it.first;
            maxFreq = it.second;
        }
    }

    

    int q;
    cin >> q;

    while(q--) {
        int number;
        cin >> number;
        // fetch
        cout << mpp[number] << endl;
    }

    cout <<"number with max frequency = " << maxFreq;

    return 0;
}
