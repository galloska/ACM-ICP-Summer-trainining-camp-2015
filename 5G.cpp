#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int W, H, w, h, ww, hh;
    freopen("garage.in", "r", stdin);
    freopen("garage.out", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> W >> H >> w >> h;
    ww = W / (w * 2);
    hh = H / (h * 2);
    if ((W % (w * 2)) >= w) {
        ww++;
    }
    if ((H % (h * 2)) >= h) {
        hh++;
    }
    cout << (long long int)ww * (long long int)hh << endl;
    return 0;
}
