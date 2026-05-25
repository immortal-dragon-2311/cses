#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if(n == 0) return 0;

    vector<int> arr(n, 0);

    for (int i = 0; i<n; i++) {
        int x;
        cin >> x;

        // st.insert(x);
        // tried out using an unordered set(
        // test case had been designed to introduce hash collissions - O(n) avg time insertion - O(n^2) time complexity

        // going with approach 2 - sorting and checking
        arr[i] = x;
    }

    sort(arr.begin(), arr.end());

    int ans = 1, curr = arr[0];

    for(int i = 1; i<n; i++) {
        if (curr != arr[i]) {
            curr = arr[i];
            ans++;
        }
    }

    cout<<ans<<endl;
    return 0;
}
