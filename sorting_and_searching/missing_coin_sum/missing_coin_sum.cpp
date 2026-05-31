#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> arr(n, 0);
    

    for(int i= 0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    ll mx = 0, sum = 0;

    for (int i = 0; i<n; i++) {
        if (arr[i] > mx+1) {
            cout<<mx+1;
            return 0;
        }
        mx+=arr[i];
    }

    cout<<mx+1;
    

    return 0;
}
