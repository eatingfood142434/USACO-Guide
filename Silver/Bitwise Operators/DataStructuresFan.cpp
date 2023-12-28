#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, t, q;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        int arr[n];
        for (int& i: arr) cin >> i;
        cin >> s >> q;
        
        int xor0 = 0, xor1 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') xor0 ^= arr[i];
            else xor1 ^= arr[i];
        }
        int psa[n+1]; psa[0] = 0;
        for (int i = 1; i <= n; i++) psa[i] = arr[i-1] ^ psa[i-1];
        
        int a, b, c;
        while (q--) {
            cin >> a >> b;
            if (a == 1) {
                cin >> c;
                int temp = psa[c] ^ psa[b-1];
                xor0 ^= temp;
                xor1 ^= temp;
            }
            else cout << (b ? xor1:xor0) << " ";
        }
        cout << "\n";
    }
    
    return 0;
}