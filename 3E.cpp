#include <bits/stdc++.h>
using namespace std;
 
int n;
int s[44];
int dp[44][676][1001];
bool vis[44][676][1001];
int a[44];
 
int ans(int i, int sa, int sb) {
    if (vis[i][sa][sb]) {
        return dp[i][sa][sb];
    }
    if (i > n) {
        return dp[i][sa][sb] = s[n] - sa - sb;
    }
    vis[i][sa][sb] = true;
    int x, y, z;
    x = y = z = 1 << 30;
    if (sa + a[i] <= s[n] - sa - sb - a[i] && sb <= s[n] - sa - sb - a[i]) {
        if (sa + a[i] <= sb)
            x = ans(i + 1, sa + a[i], sb);
        else
            x = ans(i + 1, sb, sa + a[i]);
    }
    if (sa <= s[n] - sa - sb - a[i] && sb + a[i] <= s[n] - sa - sb - a[i]) {
        y = ans(i + 1, sb + a[i], sa);
    }
    z = ans(i + 1, sa, sb);
    return dp[i][sa][sb] = min(x, min(y, z));
}
 
int main() {
    freopen("baleshare.in", "r", stdin);
    freopen("baleshare.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    printf("%d\n", ans(1, 0, 0));
    return 0;
}
