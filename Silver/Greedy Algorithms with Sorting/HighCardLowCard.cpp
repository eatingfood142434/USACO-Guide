#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("cardgame.in","r",stdin);
    freopen("cardgame.out","w",stdout);
    int n, ret = 0;
    cin >> n;
    vector<int> a(n), b(n), temp1, temp2;
    for (int& i: a) cin >> i;
    temp1 = {a.begin(), a.begin()+n/2};
    temp2 = {a.begin()+n/2, a.end()};
    sort(a.begin(), a.end());
    
    int c = 1, d = 0;
    for (int i = 0; i < n; i++) {
        for (int j = c; j < a[i]; j++) b[d++] = j;
        c = a[i]+1;
    }
    for (int i = a[n-1]+1; i <= 2*n; i++) b[d++] = i;
    
    int p1 = n-1, p2 = 0;
    sort(temp1.begin(), temp1.end(), greater<int>());
    for (int i = 0; i < n/2; i++) {
        if (b[p1] > temp1[i]) {
            b.erase(b.begin()+p1);
            p1--;
        }
    }
    sort(temp2.begin(), temp2.end());
    for (int i = 0; i < n/2; i++) if (b[p2] < temp2[i]) p2++;
    
    cout << n-1-p1+p2;
    
    return 0;
}