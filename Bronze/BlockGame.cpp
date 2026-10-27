#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
    freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);
    int n;
    int a3[26] {};
    int c;
    string s1, s2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a1[26] {}, a2[26] {};
        cin >> s1 >> s2;
        for (char c: s1) a1[c - 'a']++;
        for (char c: s2) a2[c - 'a']++;
        for (int j = 0; j < 26; j++) a3[j] += max(a1[j], a2[j]);
    }
    for (int i = 0; i < 26; i++) cout << a3[i] << endl;
    return 0;
}