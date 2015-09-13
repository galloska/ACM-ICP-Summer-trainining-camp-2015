#include <bits/stdc++.h>
using namespace std;
 
#define MAXN 2000002
 
int ft[MAXN];
 
void update(int i, int v) {
    while (i <= MAXN) {
        ft[i] += v;
        i += (i & -i);
    }
}
 
int query(int i) {
    int v = 0;
    while (i) {
        v += ft[i];
        i -= (i & -i);
    }
    return v;
}
 
int main() {
    int n, k, v;
    freopen("median.in", "r", stdin);
    freopen("median.out", "w", stdout);
    scanf("%d%d", &n, &k);
    int s = 0;
    long long int r = 0;
    update(MAXN / 2, 1);
    while (n--) {
        scanf("%d", &v);
        v = (v >= k) ? 1 : -1;
        s += v;
        r += query(s + MAXN / 2);
        update(s + MAXN / 2, 1);
    }
    printf("%lld\n", r);
    return 0;
}
