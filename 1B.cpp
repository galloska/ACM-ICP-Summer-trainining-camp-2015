#include <bits/stdc++.h>
using namespace std;
 
int n, m;
int mapa[102][102];
int memo[102][102];
int vis[102][102];
 
int dina (int i, int j){
    if (i == n && j == m) return mapa[i][j];
    if (i > n || j > m) return -1000000000;
    if (vis[i][j] == 0){
        vis[i][j] = 1;
        int a = dina (i + 1, j) + mapa[i][j];
        int b = dina (i, j + 1) + mapa[i][j];
        memo[i][j] = max (a, b);
    }
    return memo[i][j];
}
 
int main (){
 
    freopen ("turtle.in", "r", stdin);
    freopen ("turtle.out", "w", stdout);
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf ("%d", &mapa[i][j]);
    cout << dina (1, 1);
    return 0;
}
