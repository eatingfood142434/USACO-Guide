#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    pair<int,int> nums[n];
    for (int i = 0; i < n; i++) {cin >> nums[i].first; nums[i].second = i+1;}
    sort(nums, nums+n);
    int ret = 0;
    for (int i = 0; i < n-1; i++) {
        int lower = i+1, upper = n-1;
        while (lower != upper) {
            if (nums[lower].first+nums[upper].first == x-nums[i].first) {
                cout << nums[i].second << " " << nums[lower].second << " " << nums[upper].second;
                return 0;
            }
            else if (nums[lower].first+nums[upper].first > x-nums[i].first) upper--;
            else lower++;
        }
    }
    cout << "IMPOSSIBLE";
    
    return 0;
}