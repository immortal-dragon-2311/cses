#include <iostream>
#include <map>
#include <cstdint>
#include <climits>
#include <algorithm>
#include <vector>

using ll = long long;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i =0; i<n; i++) {
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

    map<int, int> mp;
    ll sum=0;

    for (int i = 0; i<n; i++) {
        if(mp.find(arr[i])==mp.end()) {
            mp[arr[i]]=0;
        }
        mp[arr[i]]++;
        sum += (ll)arr[i];
        // cout << arr[i] << " " << mp[arr[i]] << endl;
    }

    ll currSum = 0, cost = LONG_MAX; int currFreq = 0;

    // cout << "map loaded" << endl;

    for (auto &x : mp) {

        // cout << x.first << " " << x.second << endl;
        // cout << "currSum " << currSum << " currFreq " << currFreq << endl;

        ll unchanged = ll(x.second) * ll(x.first);
        ll prevCost = abs((ll)x.first * ll (currFreq) - currSum);
        ll nextCost = abs(sum - (unchanged + currSum) - (ll)x.first*(ll)(n-currFreq-x.second));

        // cout<< "prevCost " << prevCost << " nextCost " << nextCost << endl;

        cost = min(cost, prevCost+nextCost);

        // cout << "cost " << cost << endl;

        currFreq+=x.second;
        currSum+=unchanged;
    }

    cout<<cost;


    return 0;
}
