#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*

    There are n applicants and m free apartments. 
    Each applicant has a desired apparatment size -> [a[i]-k, a[i]+k]
    
    */

    int n, m, k;

    cin >> n >> m >> k;

    vector<int> a(n, 0);
    vector<int> b(m, 0);

    for(int i = 0; i<n; i++) {
        cin>>a[i];
    }

    for (int i =0; i<m; i++) {
        cin>>b[i];
    }


    // sort both a, b
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0, i=0, j=0;
    
    while (i<n && j<m)
    {
        //cout << i << " " << j << endl;
        if(b[j] >=  a[i] - k && b[j] <= a[i] + k) {
            // match found, increment i, j, ans
            ans++; i++; j++;
        } else if (b[j] < a[i] - k) {
            // apartment too small
            j++;
        } else {
            // apartment too big
            i++;
        }
    }

    cout << ans;
    
    return 0;
}
