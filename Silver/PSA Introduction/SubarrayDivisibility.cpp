#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[n];
    for (int& i: arr) {cin >> i; i %= n;}
    long long prefix_sum = 0, ret = 0;
    map<long long,int> remainders; remainders[0] = 1;
    for (const int& i: arr) {
        prefix_sum += i;
        ret += remainders[(prefix_sum % n + n) % n];
        remainders[(prefix_sum % n + n) % n]++;
    }
    cout << ret;
    return 0;
}