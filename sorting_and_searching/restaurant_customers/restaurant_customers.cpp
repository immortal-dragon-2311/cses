#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<int, int>> a;

   int n;
   cin>> n;

   for (int i = 0; i < n; i++) {
    int arr, dep;

    cin >> arr >> dep;
    a.push_back({arr, 0});
    a.push_back({dep, 1});
   }

   sort(a.begin(), a.end());

   int c=0, mx = 0;

   for(int i = 0; i<a.size(); i++) {
    auto x = a[i];

    // cout<< x.first << " " << x.second << endl;

    if(x.second == 0) {
        c++;
    } else {
        c--;
    }
    
    // cout << "c is " << c << endl;

    mx = max(c, mx);

   }

   cout<<mx;


    return 0;
}