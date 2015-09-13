#include <bits/stdc++.h>
using namespace std;
 
int n, m;
int mapa[102][102];
 
int main(){
     
    freopen ("triangles.in", "r", stdin);
    freopen ("triangles.out", "w", stdout);
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= m; i++){
        int a, b;
        scanf ("%d %d", &a, &b);
        mapa[a][b] = 1;
        mapa[b][a] = 1;
    }
    int cont = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            for (int k = j + 1; k <= n; k++){
                if (mapa[i][j] && mapa[i][k] && mapa[j][k])
                    cont++;
            }
        }
    }
    printf ("%d\n", cont);
    return 0;
}
