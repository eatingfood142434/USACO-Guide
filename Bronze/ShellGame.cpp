#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream cin ("shell.in");
    ofstream cout ("shell.out");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    short n, s1, s2, g;
    cin >> n;
    short a1[3] = {0, 0, 0};
    short a[3] = {1, 2, 3};
    for (short i = 0; i < n; i++) {
        cin >> s1 >> s2 >> g;
        swap(a[s1-1], a[s2-1]);
        a1[a[g-1]-1]++;
    }
    short max = 0;
    for (short v: a1) if (v > max) max = v;
    cout << max << endl;
    return 0;
}