#include <bits/stdc++.h>
using namespace std;
 
int main() {
    freopen("grave.in", "r", stdin);
    freopen("grave.out", "w", stdout);
    int xa, xb, xc, xd, ya, yb, yc, yd, w, h;
    scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
    scanf("%d%d%d%d", &xc, &yc, &xd, &yd);
    scanf("%d%d", &w, &h);
    puts((w <= (xc - xa) && h <= (yb - ya)) || (w <= (xb - xd) && h <= (yb - ya)) || (w <= (xb - xa) && h <= (yc - ya)) || (w <= (xb - xa) && h <= (yb - yd)) ? "Yes" : "No");
    return 0;
}
