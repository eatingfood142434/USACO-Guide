#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("mixmilk.in", "r", stdin);
	freopen("mixmilk.out", "w", stdout);
    pair<int, int> hm[3];
    int m, n, d;
    for (short i = 0; i < 3; i++) {
        scanf("%d %d", &m, &n);
        hm[i] = {m, n};
    }
    for (short i = 0; i < 100; i++) {
        d = min(hm[(i+1)%3].first - hm[(i+1)%3].second, hm[i%3].second);
        hm[i%3].second -= d;
        hm[(i+1)%3].second += d; 
    }
    for (pair k: hm) printf("%d\n", k.second);
    return 0;
}