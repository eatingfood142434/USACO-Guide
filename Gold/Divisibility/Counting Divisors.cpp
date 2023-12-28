#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, a, ret;
    cin >> n;
    while (n--) {
        cin >> a;
        ret = 1;
        map<int,int> c;
        for (int i = 2; i*i <= a; i++) {
            while (a%i == 0) {
                a /= i;
                c[i]++;
            }
        }
        if (a != 1) c[a]++;
        for (auto it = c.begin(); it != c.end(); it++) ret *= (it->second+1);
        cout << ret << "\n";
    }
    
    return 0;
}