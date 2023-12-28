#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    do {
        cout << "next 0\n";
        cout.flush();
        getline(cin, s);
        cout << "next 0 1\n";
        cout.flush();
        getline(cin, s);
    } while (s[0] != '2');
    do {
        cout << "next 0 1 2 3 4 5 6 7 8 9\n";
        cout.flush();
        getline(cin, s);
    } while (s[0] != '1');
    cout << "done";
    cout.flush();
    return 0;
}