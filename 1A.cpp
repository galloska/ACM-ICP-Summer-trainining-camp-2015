#include <bits/stdc++.h>
using namespace std;
 
 
int n, m;
char mapa[52][52];
int p[52 * 52];
 
int get (int x){
    if (x == p[x])
        return x;
    p[x] = get(p[x]);
    return p[x];
}
 
bool sameSet (int u, int v){
    return get (u) == get (v);
}
 
void unite (int x, int y){
    int a = get (x);
    int b = get (y);
    p[a] = b;
}
 
int main (){
 
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf (" %c", &mapa[i][j]);
    for (int i = 1; i <= n * m; i++)
        p[i] = i;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            for (int x = 1; x <= n; x++){
                for (int y = 1; y <= m; y++){
                    if (i != x || j != y){
                        int dis = abs (i - x) + abs (j - y);
                        if (mapa[i][j] == mapa[x][y] && dis == 1){
                            int u = (i - 1) * m + j;
                            int v = (x - 1) * m + y;
                            if (u < v){
                                if (sameSet (u, v)){
                                    cout << "Yes" << endl;
                                    return 0;
                                }
                                unite (u, v);
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
