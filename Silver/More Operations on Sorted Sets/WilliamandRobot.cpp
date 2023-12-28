#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[n];
    for (int& i: arr) cin >> i;
    
    multiset<int> taken;
    taken.insert(max(arr[0], arr[1]));
    for (int i = 2; i < n; i+=2) {
        if (*taken.begin() < min(arr[i],arr[i+1])) {
            taken.erase(taken.begin());
            taken.insert({arr[i],arr[i+1]});
        }
        else taken.insert(max(arr[i],arr[i+1]));
    }
    long long ret = 0;
    for (const int& i: taken) ret += i;
    cout << ret;
    
    return 0;
}