#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i<n; i++) {
        int x;
        cin >> x;
        arr[x-1] = i;
    }

    int x = INT_MAX, scans = 0;

    for (int i = 0; i<n; i++) {
        if (arr[i] < x) {
            scans++;
        }
        x = arr[i];
    }

    cout << scans;

    return 0;
}
