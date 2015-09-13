#include <bits/stdc++.h>
using namespace std;
 
int n;
int mapa[102][102];
int dis[102];
int vis[102];
 
void busca (int nodo, int nivel){
    if (!vis[nodo]){
        vis[nodo] = 1;
        dis[nodo] = nivel;
        for (int i = 1; i <= n; i++)
            if (mapa[nodo][i])
                busca (i, nivel + 1);
    }
}
 
int main (){
 
    freopen ("rootdist.in", "r", stdin);
    freopen ("rootdist.out", "w", stdout);
    scanf ("%d", &n);
    for (int i = 2; i <= n; i++){
        int aux;
        scanf ("%d", &aux);
        mapa[i][aux] = 1;
        mapa[aux][i] = 1;
    }
    busca (1, 0);
    int mayor = 0;
    for (int i = 1; i <= n; i++)
        mayor = max (mayor, dis[i]);
    printf ("%d\n", mayor);
    int cont = 0;
    for (int i = 1; i <= n; i++)
        if (dis[i] == mayor) cont++;
    printf ("%d\n", cont);
    for (int i = 1; i <= n; i++)
        if (dis[i] == mayor) printf ("%d ", i);
    printf ("\n");
    return 0;
}
