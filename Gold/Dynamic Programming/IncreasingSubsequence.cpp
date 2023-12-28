#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int& i: a) cin >> i;
    vector<int> ret = {a[0]};
    for (int i = 1; i < n; i++) {
        if (a[i] > ret.back()) ret.push_back(a[i]);
        else *lower_bound(ret.begin(), ret.end(), a[i]) = a[i];
    }
    cout << ret.size();

    return 0;
}