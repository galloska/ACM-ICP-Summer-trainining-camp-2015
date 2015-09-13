#include <bits/stdc++.h>
using namespace std;
 
typedef pair< int, int > pii;
 
#define x first
#define y second
 
double d[22][22];
double m[1 << 23][21];
bool v[1 << 23][21];
 
int w, h, a, b, rx, ry, p;
pii pl[22];
 
double dist(double xa, double ya, double xb, double yb) {
    return sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
}
 
double dp(int mask, int i) {
    if (v[mask][i]) {
        return m[mask][i];
    }
    if (mask == (1 << (p + 1)) - 1) {
        return min(min(pl[i].x, w - pl[i].x), min(pl[i].y, h - pl[i].y));
    }
    v[mask][i] = true;
    m[mask][i] = numeric_limits< double >::max();
    if (i == 0) {
        for (int j = 1; j <= p; j++) {
            m[1][0] = min(m[1][0], dp(1 << j | 1, j) + dist(rx, ry, pl[j].x, pl[j].y));
        }
        return m[1][0];
    }
    for (int j = 1; j <= p; j++) {
        if (!(mask & (1 << j))) {
            m[mask][i] = min(m[mask][i], dp(1 << j | mask, j) + d[i][j]);
        }
    }
    return m[mask][i];
}
 
int main() {
    freopen("kitchen.in", "r", stdin);
    freopen("kitchen.out", "w", stdout);
    int i, j;
    double ans = numeric_limits< double >::max();
    scanf("%d%d", &w, &h);
    scanf("%d", &p);
    for (i = 1; i <= p; i++) {
        scanf("%d%d", &a, &b);
        pl[i] = pii(a, b);
    }
    scanf("%d%d", &rx, &ry);
    for (i = 1; i <= p; i++) {
        for (j = 1; j <= p; j++) {
            if (i == j) {
                d[i][j] = numeric_limits< double >::max();
            } else {
                d[i][j] = dist(pl[i].x, pl[i].y, -pl[j].x, pl[j].y);
                d[i][j] = min(d[i][j], dist(pl[i].x, pl[i].y, pl[j].x, -pl[j].y));
                d[i][j] = min(d[i][j], dist(pl[i].x, pl[i].y, w + w - pl[j].x, pl[j].y));
                d[i][j] = min(d[i][j], dist(pl[i].x, pl[i].y, pl[j].x, h + h - pl[j].y));
            }
        }
    }
    printf("%.6lf\n", dp(1, 0));
    return 0;
}
