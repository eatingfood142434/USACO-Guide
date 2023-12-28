#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("cowdance.in","r",stdin);
    freopen("cowdance.out","w",stdout);
    int n, t;
    cin >> n >> t;
    vector<int> cows(n);
    for (int& i: cows) cin >> i;
    int l = 0, h = n, mid = (h+l)/2, c, lowest, amt;
    multiset<int> curr;
    while (h-l > 1) {
        c = 0; amt = 0;
        while (curr.size() < mid) curr.insert(cows[c++]);
        while (c < n) {
            curr.insert(*curr.begin()+cows[c++]);
            curr.erase(curr.begin());
        }
        if (*prev(curr.end()) <= t) h = mid;
        else l = mid;
        mid = (h+l)/2;
        curr.clear();
    }
    cout << h;

    return 0;
}
