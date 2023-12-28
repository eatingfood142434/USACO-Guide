#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    vector<int> usb, ps2;
    string temp;
    for (int i = 0, t; i < m; i++) {
        cin >> t >> temp;
        if (temp == "USB") usb.push_back(t);
        else ps2.push_back(t);
    }
    sort(usb.begin(), usb.end());
    sort(ps2.begin(), ps2.end());
    
    long long priceusb = 0, priceps2 = 0, priceunused = 0;
    int amtusb = a, amtps2 = b, amtunused = c;
    for (int i = 0; i < a; i++) {
        if (i >= usb.size()) {amtusb = i; break;}
        priceusb += usb[i];
    }
    for (int i = 0; i < b; i++) {
        if (i >= ps2.size()) {amtps2 = i; break;}
        priceps2 += ps2[i];
    }
    vector<int> unused;
    for (int i = amtusb; i < usb.size(); i++) unused.push_back(usb[i]);
    for (int i = amtps2; i < ps2.size(); i++) unused.push_back(ps2[i]);
    sort(unused.begin(), unused.end());
    for (int i = 0; i < c; i++) {
        if (i >= unused.size()) {amtunused = i; break;}
        priceunused += unused[i];
    }
    cout << amtusb+amtps2+amtunused << " " << priceusb+priceps2+priceunused;
    
    return 0;
}