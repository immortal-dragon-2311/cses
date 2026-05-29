#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // take n
    int n, t;
    cin >> n >> t;

    // take values
    vector<pair<int,int>> arr(n);
    for (int i = 0; i< n; i++) {
        int val;
        cin >> val;
        arr[i] = {val, i};
    }

    // sort arr
    sort (arr.begin(), arr.end());

    int l = 0, r = n-1;

    while (l<r) 
    {
        if(arr[l].first + arr[r].first == t) {
            cout << arr[l].second+1 << " " << arr[r].second+1 << endl;
            return 0;
        } else if (arr[l].first + arr[r].first > t) {
            r--;
        } else {
            l++;
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
