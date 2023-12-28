#include <bits/stdc++.h>
using namespace std;

int sum(int a, int b) {
    int a_and_b, a_or_b;
    cout << "and " << a << " " << b << endl;
    cin >> a_and_b;
    cout << "or " << a << " " << b << endl;
    cin >> a_or_b;
    return a_and_b+a_or_b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k, zero = -1, one = -1;
    cin >> n >> k;
    int a = sum(1,2), b = sum(2,3), c = sum(1,3);
    a = (a+c-b)/2; c -= a; b -= c;
    int arr[n]; arr[0]=a, arr[1]=b, arr[2]=c;
    
    for (int i = 4; i <= n; i++) arr[i-1] = sum(1,i)-a;
    sort(arr,arr+n);
    cout << "finish " << arr[k-1] << endl;
    return 0;
}