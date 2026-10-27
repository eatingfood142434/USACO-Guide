#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
    int n, k, p;
    cin >> n >> k;
    vector<int> sizes;
    for (int i = 0; i < n; i++) {
        cin >> p;
        sizes.push_back(p);
    }
    int m = 0;
    int counter = 0;
    for (const int& i: sizes) {
        for (const int& j: sizes) {
            if (abs(i-j) <= k && j >= i) {
                counter++;
            }
        }
        m = max(m, counter);
        counter = 0;
    }
    cout << m << "\n";
    return 0;
}