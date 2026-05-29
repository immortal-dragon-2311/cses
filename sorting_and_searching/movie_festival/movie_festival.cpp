#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // input n
    int n;
    cin >> n;

    vector<pair<int, int>> arr;

    for (int i = 0; i<n; i++) {
        int s, e;
        cin>> s >> e;

        arr.push_back({e, s});
    }

    // sort array by end time
    sort(arr.begin(), arr.end());

    int curr_end = -1, count = 0;

    // pick first non-overlapping interval that you get
    for(int i = 0; i<n; i++) {
        auto p = arr[i];

        int end_time = p.first;
        int start_time = p.second;

        if (start_time >= curr_end) {
            count++;
            curr_end = end_time;
        }
    }

    cout << count << endl;

    return 0;
}
