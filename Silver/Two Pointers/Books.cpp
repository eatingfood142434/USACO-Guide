#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    int books[n];
    for (int& i: books) cin >> i;
    int left = 0, right = 0, max_b = 0, curr_b = 0, curr_t = 0;
    while (right < n) {
        curr_t += books[right];
        curr_b++; right++;
        while (curr_t > t) {
            curr_t -= books[left];
            curr_b--;
            left++;
        }
        max_b = max(max_b, curr_b);
    }
    cout << max_b;
    
    return 0;
}