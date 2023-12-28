#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e6;
int occ[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        occ[a]++;
    }
    for (int gcd = MAX; gcd >= 1; gcd--) {
        int c = 0;
        for (int j = gcd; j <= MAX; j += gcd) c += occ[j];
        if (c > 1) {
            cout << gcd;
            return 0;
        }
    }
   
    return 0;
}