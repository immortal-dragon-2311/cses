#include <iostream>
#include <cstdint>
#include <vector>
#include <climits>

using namespace std;


using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> arr(n);
    
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    int l = 0, r = 0;

    ll cs = 0, mx = INT_MIN;

    while (l<n && r <n){
        cs += arr[r];
        mx = max(cs, mx);

        if(cs < 0) {
            cs=0;
            l = r+1;
        }
        r++;
    }

    cout << mx;
    


    return 0;
}
