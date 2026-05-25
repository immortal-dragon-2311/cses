#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /* 
    n concert tickets available
    m customers
    h[i] - price of each ticket
    t[i] - max price a customer can pay for the tickets
    */

    int n, m;
    cin >> n >> m;

    multiset<int> h;

    // initialize a multiset for prices
    for(int i =0; i<n; i++) {
        int x;
        cin>>x;
        h.insert(x);
    }

    // calculate the price of ticket for each person
    for(int i =0; i<m; i++) {
        int mp;
        cin>>mp; // maximum price the user can pay

        // calculate upper bound
        auto it = h.upper_bound(mp);
        if(it != h.begin()) {
            --it;
            cout<< *(it) << endl; // printing element that is less than or equal to mp

            // remove value from the list since it is used
            h.erase(it);
        } else {
            cout << -1 << endl;
        }
    }

    

    return 0;
}
