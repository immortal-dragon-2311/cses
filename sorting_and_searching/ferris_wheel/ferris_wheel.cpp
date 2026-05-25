#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
    n children want to go on a ferris wheel
    We have to find a gondola for each child
    Total weight of each gondola should not excced x
    p[i] - weight of i-th child
    n - number of children
    x - maximum allowed weight
    We need to find minimum number of gondolas
    */

    int n , x;
    cin >> n >> x;
    
    vector<int> p(n, 0);
    for (int i=0; i<n; i++) {
        cin>>p[i];
    }

    // sort the array first
    sort(p.begin(), p.end());

    while (n > 0 && p[n-1] > x) {
        n--;
    }
    if(n == 0) {
        return 0;
    }

    int i = 0, j = n-1, ans = 0;

    while(i<j) {
        //cout<< i << " " << p[i] << " " << j << " " << p[j] << endl;
        if(p[i] + p[j] <= x) {
            // possible to pair with smallest
            i++;
        } 
        ans++;
        j--;        
    }

    if (i == j) {
        ans++;
    }

    cout << ans;

    return 0;
}
